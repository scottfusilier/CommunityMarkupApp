#ifndef VIEWERTAGGER_H
#define VIEWERTAGGER_H

#include <gtkmm/window.h>
#include <gtkmm/dialog.h>
#include <glibmm/main.h>
#include <iostream>

class Photo;
class IOBuffer;
class ConnectionDialog;
class TagDialog;
class DisplayArea;

class ViewerTagger : public Gtk::Window
{
public:
    ViewerTagger();
    virtual ~ViewerTagger();
    void db_connection();
    void create_iobuffer(const std::string&, const std::string&, 
            const std::string&, const std::string&);
    void create_displayarea();
    virtual void on_signal(const std::string&);
    virtual void tag_signal();
    bool photo_timeout();
    void update_view();
    DisplayArea* get_display();
protected:
    ConnectionDialog *CD;
    TagDialog *TD;
    Photo *CurrentPhoto;
    IOBuffer *IO;
    DisplayArea *DA;
    bool paused;
};

#endif // VIEWERTAGGER_H

