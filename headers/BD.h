#ifndef BASEDATA_BD_H
#define BASEDATA_BD_H

#include "DataIO.h"
#include <list>

using namespace std;

template<class T>
class BD : public DataIO {
private:
    list <T> data;
public:
    BD() = delete;

    BD(string in, string out) : DataIO(in, out)
    {
    };

    bool load();

    bool write();

    void sort_by_temp(T temp);

    T find();

    void print_one(T wanted);

    void print_All();

};

bool BD::load()
{
    return false;
}

bool BD::write()
{
    return false;
}

template<class T>
void BD::sort_by_temp(T temp)
{
}


template<class T>
T BD::find()
{
    return nullptr;
}

template<class T>
void BD::print_one(T wanted)
{
}

void BD::print_All()
{

}


#endif //BASEDATA_BD_H
