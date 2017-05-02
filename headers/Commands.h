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

    void del_bd();

    void load_bd();

    void report();

};

void Commands::create() {

}

void Commands::sort() {

}

void Commands::add_user() {

}

void Commands::del_user() {

}

void Commands::printOne() {

}

void Commands::printAll() {

}

void Commands::write_bd() {

}

void Commands::del_BD() {

}

void Commands::load_bd() {

}

void Commands::report() {

}

void Commands::find() {
    BD::find();
}


#endif //BASEDATA_COMMANDS_H
