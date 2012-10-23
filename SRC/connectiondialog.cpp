#include "connectiondialog.h"


ConnectionDialog::ConnectionDialog() : url_l("URL in the form:\ntcp://127.0.0.1:3306"), user_l("USER:"),
    pass_l("PASSWORD:"),  db_l("DATABASE:")
{
    set_resizable(false);
    set_title("Connection");
    add_button("Done", 0);
    Gtk::Box *box = get_vbox();
    box->pack_start(url_l);
    box->pack_start(url_e);
    box->pack_start(user_l);
    box->pack_start(user_e);
    box->pack_start(pass_l);
    box->pack_start(pass_e);
    box->pack_start(db_l);
    box->pack_start(db_e);

    show_all_children();
}

ConnectionDialog::~ConnectionDialog()
{

}
