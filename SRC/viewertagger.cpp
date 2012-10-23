#include "viewertagger.h"
#include "displayarea.h"
#include "connectiondialog.h"
#include "tagdialog.h"
#include "iobuffer.h"
#include "dbinterface.h"
#include "queuearray.h"
#include "photo.h"

ViewerTagger::ViewerTagger()
{
    paused = false;
    /* create children */
    db_connection();
    /* callback to timer for photo_timeout */
    Glib::signal_timeout().connect(sigc::mem_fun(*this,
                &ViewerTagger::photo_timeout), 10000 );
    /* create children */
    create_displayarea();
    add(*DA);
    CurrentPhoto = NULL;
    fullscreen();
    show_all_children();
}

ViewerTagger::~ViewerTagger()
{
    delete DA;
    delete IO;
    delete CurrentPhoto;
}

void ViewerTagger::create_iobuffer(const std::string& URL, 
        const std::string& USR, const std::string& PSWD, const std::string& DTB)
{
    /* create io buffer */
    IO = new IOBuffer(URL, USR, PSWD, DTB);
    /* connect callback to dbinterface */
    IO->get_dbi()->error_sig.connect(sigc::mem_fun(*this,
                &ViewerTagger::on_signal));
}

void ViewerTagger::create_displayarea()
{
    DA = new DisplayArea();
    /* connect callback to DisplayArea for TagDialog */
    DA->tag_sig.connect(sigc::mem_fun(*this,
                &ViewerTagger::tag_signal));

}

void ViewerTagger::db_connection()
{
    CD = new ConnectionDialog();
    int result = CD->run();
    
    create_iobuffer(CD->url_e.get_text(), CD->user_e.get_text(), 
            CD->pass_e.get_text(), CD->db_e.get_text());
    delete CD;
}

void ViewerTagger::on_signal(const std::string &error)
{
    /* create error dialog and display */
    Gtk::MessageDialog dialog(*this, "Error");
    dialog.set_secondary_text(error);
    dialog.run();
    fullscreen();
}

void ViewerTagger::tag_signal()
{
    /* local copy of tag click x and y position */
    int x = DA->get_x();
    int y = DA->get_y();
    unfullscreen();
    paused = true;
    TD = new TagDialog();
    TD->move(x, y);
    int result = TD->run();
    /* tag the photo here */
    CurrentPhoto->insert_tag(TD->m_entry.get_text(), x, y);
    delete TD;
    fullscreen();
    /* connect new timer */
    Glib::signal_timeout().connect(sigc::mem_fun(*this,
                &ViewerTagger::photo_timeout), 10000 );
    paused = false;
}

void ViewerTagger::update_view()
{
    /* get front of queue */
    CurrentPhoto = IO->get_inbuffer()->dequeue();
    /* if not null, have display area display the photo */
    if(CurrentPhoto != NULL)
    {
        DA->display_image(CurrentPhoto);
        std::cout<<"Success on timeout update\n";
    }
    else
        std::cout<<"NULL from timeout update\n";
}

bool ViewerTagger::photo_timeout()
{
    /* call back to update image in viewer */
    if(paused)
        /* disconnect timer by returning false for not handled */
        return false;
    update_view();
    /* handled */
    return true;
}

DisplayArea* ViewerTagger::get_display()
{
    return DA;
}
