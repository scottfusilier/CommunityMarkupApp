#ifndef PHOTO_H
#define PHOTO_H

#include <gdkmm/pixbuf.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>
class Tag;

class Photo
{
private:
    //id associated with Photo
    int imageID;
    //linked list of Tags
    Tag *head;
    Tag *tail;
    //pixel buffer for image
    Glib::RefPtr<Gdk::Pixbuf> image;    
public:
    Photo(const std::string &, int);
    ~Photo();
    void insert_tag(const std::string &, int, int);
    bool delete_tag(const std::string &);
    int get_id();
    void set_id(int);
    Glib::RefPtr<Gdk::Pixbuf> get_image();    
};
#endif //end PHOTO_H
