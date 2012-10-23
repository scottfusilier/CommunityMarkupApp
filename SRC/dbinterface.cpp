#include "dbinterface.h"
#include "photo.h"

DBinterface::DBinterface() : URL("tcp://127.0.0.1:3306"), USER(""), PASS(""), DB("Photos")
{
}

DBinterface::DBinterface(const std::string& url, const std::string& user, 
        const std::string& pass, const std::string& db) : URL(url), USER(user), 
        PASS(pass), DB(db)
{
}

DBinterface::~DBinterface()
{
}

Photo* DBinterface::retrieve_photo(int seq)
{
    /* retreive an Employee based on sequence number */
    try 
    {
        /* sql related pointers */
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect(URL, USER, PASS);
        /* Connect to the MySQL DB */
        con->setSchema(DB);
        /* create statement */
        stmt = con->createStatement();
        /* get path */
        std::stringstream ss;
        ss<<"SELECT filePath from Photo where imageID='"<<seq<<"'";
        res = stmt->executeQuery(ss.str());
        if(res->rowsCount() == 0) //empty set
            return NULL;
        std::string path;
        while (res->next())
        {
            path = res->getString(1);
        }
        /* clear stringstream */
        ss.str("");
        /* get filename */
        ss<<"SELECT filename from Photo where imageID='"<<seq<<"'";
        res = stmt->executeQuery(ss.str());
        if(res->rowsCount() == 0) //empty set
            return NULL;
        std::string fileName;
        while (res->next())
        {
            fileName = res->getString(1);
        }
        /* clear stringstream */
        ss.str("");
        /**** concatinate path and filename here ****/
        path.append(fileName);
        /**** for debug ****/
        std::cout<<"complete file path :"<<path<<std::endl; 
        /* create new Photo */
        Photo *photo = new Photo(path, seq); 

        /* TODO  create and add tags to photo if stored in DB */

        /* clean up */
        delete res;
        delete stmt;
        delete con;
        /* return new Photo */
        return photo;
    }
    catch (sql::SQLException &e)
    {
        /* string stream to build up error message */
        std::stringstream sst;
        /* build error message for display */
        sst << "# ERR: SQLException in " << __FILE__;
        sst << "(" << __FUNCTION__ << ") on line "
         << __LINE__ << "\n";
        sst << "# ERR: " << e.what();
        sst << " (MySQL error code: " << e.getErrorCode();
        sst << ", SQLState: " << e.getSQLState() << " )" << "\n";
        /* emit error signal */
        error_sig.emit(sst.str());
        /* indicate failure by returning NULL */
        return NULL;
    }
}

bool DBinterface::store_photo(Photo *photo)
{
    /* store Photo object's Tag info into DB */
    try 
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect(URL, USER, PASS);
        /* Connect to the MySQL DB */
        con->setSchema(DB);
        /* create statement */
        stmt = con->createStatement();
        /* build up insert statement  and store */
        std::stringstream ss;
        /* note: here we need to modify table instead of insert for Photo class 
         * insert into Photo values() where id=photo->getID();
         *
        ** create loop here to process the photo's tags **
        ss<<"insert into Employee values("<<employee->get_id()<<", '"
            <<employee->get_name()<<"', '"<<employee->get_job_title()<<"')";
        stmt->execute(ss.str());
        */
        /* clean up */
        delete stmt;
        delete con;
        /* indicate success */
        return true;
    }
    catch (sql::SQLException &e)
    {
        /* string stream to build up error message */
        std::stringstream sst;
        /* build error message for display */
        sst << "# ERR: SQLException in " << __FILE__;
        sst << "(" << __FUNCTION__ << ") on line "
         << __LINE__ << "\n";
        sst << "# ERR: " << e.what();
        sst << " (MySQL error code: " << e.getErrorCode();
        sst << ", SQLState: " << e.getSQLState() << " )" << "\n";
        /* emit error signal */
        error_sig.emit(sst.str());
        /* indicate failure by returning NULL */
        return false;
    }
}


