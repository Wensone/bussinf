#ifndef BASEDATA_COMMANDS_H
#define BASEDATA_COMMANDS_H

#include "BD.h"

template<class T>
class Commands : public BD {
public:
    Commands() = delete;

    Commands(string in, string out) : BD(in, out)
    {
    };

    void create();

    void add_user();

    void sort();

    void find();

    void del_user();

    void printOne();

    void printAll();

    void write_bd();

    void del_BD();

    void load_bd();

    void report();

};


#endif //BASEDATA_COMMANDS_H
