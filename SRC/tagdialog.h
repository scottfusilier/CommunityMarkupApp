#ifndef TAGDIALOG_H
#define TAGDIALOG_H

#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>

class TagDialog : public Gtk::Dialog
{
public:
   TagDialog(); 
   ~TagDialog(); 
   Gtk::Entry m_entry;
};

#endif //end TAGDIALOG_H
