#ifndef IOBUFFER_H
#define IOBUFFER_H

#include <gtkmm/widget.h>

class DBinterface;
class QueueArray;
class Photo;

class IOBuffer : public Gtk::Widget
{
public:
    IOBuffer(const std::string&, const std::string&, const std::string&, 
            const std::string&);
    ~IOBuffer();
    virtual bool on_timeout();
    DBinterface* get_dbi();
    QueueArray* get_inbuffer();
    QueueArray* get_outbuffer();
private:
    unsigned int index;
    DBinterface *DB;
    QueueArray *InBuff;
    QueueArray *OutBuff;
};
#endif //IOBUFFER_H
