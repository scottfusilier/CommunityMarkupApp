#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>

class ConnectionDialog : public Gtk::Dialog
{
public:
    ConnectionDialog();
    virtual ~ConnectionDialog();
    Gtk::Label url_l;
    Gtk::Label user_l;
    Gtk::Label pass_l;
    Gtk::Label db_l;
    Gtk::Entry url_e;
    Gtk::Entry user_e;
    Gtk::Entry pass_e;
    Gtk::Entry db_e;
};
#endif // end CONNECTIONDIALOG_H
