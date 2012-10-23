#ifndef DISPLAYAREA_H
#define DISPLAYAREA_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

class Photo;

class DisplayArea : public Gtk::DrawingArea
{
public:
    DisplayArea();
    virtual ~DisplayArea();
    void display_image(Photo*);
    typedef sigc::signal<void> tagdialog_signal_type; 
    tagdialog_signal_type tag_sig; /* signal for TagDialog popup window */
    int get_x();
    int get_y();
protected:
    int x, y;
    //image buffer
    Glib::RefPtr<Gdk::Pixbuf> m_image;
    //Override default signal handler:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    bool on_mouse(GdkEventButton *event);
};
#endif // DISPLAYAREA_H

