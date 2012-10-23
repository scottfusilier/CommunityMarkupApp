#include "tagdialog.h"

TagDialog::TagDialog()
{
    set_resizable(false); //remove resize button
    set_title("Tag the image. Enter Name:");
    add_button("Done",0);
    Gtk::Box *box = get_vbox();
    box->pack_start(m_entry);
    show_all_children();
}

TagDialog::~TagDialog()
{
}

