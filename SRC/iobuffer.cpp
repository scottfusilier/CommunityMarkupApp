#include "iobuffer.h"
#include "dbinterface.h"
#include "queuearray.h"

IOBuffer::IOBuffer(const std::string& url, const std::string& usr, 
        const std::string& passwd, const std::string& database)
{
    index = 1;
    DB = new DBinterface(url, usr, passwd, database);
    InBuff = new QueueArray();
    OutBuff = new QueueArray();
    //attach timer callback
    Glib::signal_timeout().connect(sigc::mem_fun(*this,
                               &IOBuffer::on_timeout), 1000 );
}

IOBuffer::~IOBuffer()
{
    delete DB;
    delete InBuff, OutBuff;
}

bool IOBuffer::on_timeout()
{
        //get object
        if(!InBuff->isFull())
        {
            Photo *ph = DB->retrieve_photo(index);
            if(ph != NULL) // ***check for NULL here to insure relavent photo***
            {
                InBuff->enqueue(ph);
                std::cout<<"Photo enqueued...\n";
                ph = NULL;
                index++;
            }
            else
            {
                std::cout<<"buffer empty!\n";
                index = 1; //reset index 
            }
        }

        if(!OutBuff->isEmpty())
            /* store object in DataBase */
            DB->store_photo(OutBuff->dequeue()); 
        return true; //indicates event handled
}

DBinterface* IOBuffer::get_dbi()
{
    return DB;
}

QueueArray* IOBuffer::get_inbuffer()
{
    return InBuff;
}

QueueArray* IOBuffer::get_outbuffer()
{
    return OutBuff;
}
