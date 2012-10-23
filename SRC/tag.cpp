#include "tag.h"

Tag::Tag() : id(0), name(""), x(0), y(0), next(NULL){}

Tag::Tag(const std::string &nm, int ID, int x_pos, int y_pos) : name(nm), id(ID), x(x_pos), y(y_pos), next(NULL)
{
}

Tag::~Tag()
{
}

void Tag::set_id(int n)
{
    id = n;
}

void Tag::set_name(const std::string &newName)
{
    name = newName;
}

void Tag::set_next(Tag * n)
{
    next = n;
}

void Tag::set_x(int x_pos)
{
    x = x_pos;
}

void Tag::set_y(int y_pos)
{
    y = y_pos;
}

int Tag::get_id()
{
    return id;
}

std::string Tag::get_name()
{
    return name;
}

Tag* Tag::get_next()
{
    return next;
}

int Tag::get_x()
{
    return x;
}

int Tag::get_y()
{
    return y;
}
