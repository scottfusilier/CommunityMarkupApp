#ifndef TAG_H
#define TAG_H

#include<iostream>

class Tag
{
private:
    int id; //should be same as imageID in Photo Class for id in DB
    std::string name;
    Tag *next;
    int x;
    int y;
public:
    Tag();
    Tag(const std::string&, int, int, int);
    ~Tag();
    //member functions
    void set_id(int);
    void set_name(const std::string&);
    void set_next(Tag*);
    void set_x(int);
    void set_y(int);
    int get_id();
    std::string get_name();
    Tag* get_next();
    int get_x();
    int get_y();
};
#endif
