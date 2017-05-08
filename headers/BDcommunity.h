#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include "Cartoteka.h"
#include "Reader.h"
#include <getopt.h>
#include "DataBase.h"
#include <cstdio>
#include <string>
#include <cstdlib>

#ifdef unix
#define clr "clear"
#else
#define clr "cls"
#endif


class BDcommunity {
private:
    DB::DataBase<Reader> *reader;
    DB::DataBase<Cartoteka> *card;
    int base;
    enum Type_base {
        r = 1, c = 2
    };
public:
    BDcommunity();

    ~BDcommunity();

    void print_Cartoteka();

    void print_Reader();

    Reader enter_Reader();

    Cartoteka enter_Cartoteka();

    int getBaseNow();

    void change_base();

    void checkIO(bool &in, bool &out);

    void create();

    void printBase();

    void switch_input(string newfilename);

    void switch_output(string newfilename);

    void add_new_record(Reader rec);

    void add_new_record(Cartoteka rec);

    void sort(int n);

    bool find(Reader s);

    bool find(Cartoteka s);

    bool del_record(Reader &t);

    bool del_record(Cartoteka &t);

    void del_copy(Reader &T);

    void del_copy(Cartoteka &T);

    int write();

    int load();

    void print_onec(Reader &t);

    void print_onec(Cartoteka &t);

    void del_base();

    void clear_screen();

    void menu();

    void del_copyOne(Reader &T);

    void del_copyOne(Cartoteka &T);

    void console(int argc, char **argv);

    Reader parse_reader(ifstream &os);

    Cartoteka parse_card(ifstream &os);

    Reader parse_reader(string s);

    Cartoteka parse_card(string s);

    void readInstruction(char *file);

    //report
};

#endif //BASEDATA_BDCOMMUNITY_H
