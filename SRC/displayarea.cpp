#include "displayarea.h"
#include "photo.h"

DisplayArea::DisplayArea()
{
    x = y = 0;
    //allow events
    add_events(Gdk::POINTER_MOTION_MASK
                | Gdk::POINTER_MOTION_HINT_MASK
                | Gdk::BUTTON_PRESS_MASK
                | Gdk::LEAVE_NOTIFY_MASK); 
    signal_button_press_event().connect(sigc::mem_fun(
                *this, &DisplayArea::on_mouse));
}

DisplayArea::~DisplayArea()
{
}

void DisplayArea::display_image(Photo *photo)
{
    m_image = photo->get_image(); 
    /* redraw window */
    //queue_draw_area();
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
            get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
}

int DisplayArea::get_x()
{
    return x;
}

int DisplayArea::get_y()
{
    return y;
}

bool DisplayArea::on_mouse(GdkEventButton *event)
{
    Gtk::Allocation allocation = get_allocation();
    Cairo::RefPtr<Cairo::Context> cr =
        get_window()->create_cairo_context();
    cr->set_source_rgba(0, 0, 0, 1);
    x = event->x;
    y = event->y;
    cr->move_to(x, y);
    cr->show_text("Tagged here");
    /* emit signal to parent */
    tag_sig.emit();

    return true;
}

bool DisplayArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    if (!m_image)
        return false;
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    // Draw the image in the middle of the drawing area, or (if the image is
    // larger than the drawing area) draw the middle part of the image.
    Gdk::Cairo::set_source_pixbuf(cr, m_image,
        (width - m_image->get_width())/2, (height - m_image->get_height())/2);
    cr->paint();
    return true;
}

