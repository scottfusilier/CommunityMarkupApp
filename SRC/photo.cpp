#include "photo.h"
#include "tag.h"

//member functions

Photo::Photo(const std::string &path, int id)
{
    std::cout<<"photo creation path : "<<path<<"\n";
    imageID = id;
    head = tail = NULL;
    //import image from file or DB
    try
    {
        image = Gdk::Pixbuf::create_from_file(path);
    }
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
    }
    catch(const Gdk::PixbufError& ex)
    {
        std::cerr << "PixbufError: " << ex.what() << std::endl;
    }
}

Photo::~Photo()
{
    delete head;
    delete tail;
}

void Photo::insert_tag(const std::string &name, int x, int y)
{
    //create a new tag and insert at head of linked list
    Tag *tag = new Tag(name, imageID,  x, y);
    if(head == NULL) //first in list
        head = tail = tag;
    else
    {
        tag->set_next(head);
        head = tag;
    }
    tag = NULL;
    delete tag;
}

bool Photo::delete_tag(const std::string &S)
{
    if(head == NULL) /* empty list */
        return false;
    /* local ptr to reference place in list */
    Tag *curr = head;
    Tag *prev = NULL;
    while(curr != NULL)
    {
        if(curr->get_name().compare(0, S.length(), S) == 0)
        {
            Tag *temp = curr;
            /* delete */
            prev->set_next(curr->get_next());
            curr->set_next(NULL);
            curr = prev->get_next();
            delete temp;
            return true; /* success */
        }
        /* move forward */
        prev = curr;
        curr = curr->get_next();
    }
    return false; /* not found */
}

int Photo::get_id()
{
    return imageID;
}

void Photo::set_id(int n)
{
    imageID = n;
}

Glib::RefPtr<Gdk::Pixbuf> Photo::get_image()
{
    return image;
}
