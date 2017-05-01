#ifndef BASEDATA_BD_H
#define BASEDATA_BD_H

#include "DataIO.h"
#include <list>

using namespace std;

template <class T>
class BD : public DataIO {
private:
    list<T> data;
public:
    BD() = delete;
    BD(string in, string out) : DataIO(in, out) {};
    bool load();
    bool write();
    void sort();
    T find();
    void printOne(T wanted);
    void printAll();


};


#endif //BASEDATA_BD_H
