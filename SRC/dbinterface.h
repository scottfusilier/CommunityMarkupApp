#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <iostream>
#include <sstream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <gtkmm/messagedialog.h>
#include <sigc++/sigc++.h>

class Photo;

class DBinterface
{
public:
    DBinterface();
    DBinterface(const std::string&, const std::string&, const std::string&, 
            const std::string&);
    ~DBinterface();
    Photo* retrieve_photo(int seq);
    bool store_photo(Photo*);
    typedef sigc::signal<void, const std::string& > db_error_signal_type;
    db_error_signal_type error_sig;
protected:
    std::string URL;
    std::string USER;
    std::string PASS;
    std::string DB;
};

#endif //end DBINTERFACE_H
