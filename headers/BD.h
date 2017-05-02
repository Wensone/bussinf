#ifndef BASEDATA_BD_H
#define BASEDATA_BD_H

#include "DataIO.h"
#include <list>

using namespace std;

template<class T>
class BD {
private:
    list <T> data;
public:
    BD(){}

    BD(string in, string out) : DataIO(in, out)
    {
    }
    
/*
    void sort_by_temp(T temp);

    T find();

    void print_one(T wanted);

    void print_All();*/

};


#endif //BASEDATA_BD_H
