#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include "Auto.h"
#include "Shopper.h"
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
    DB::DataBase<Shopper> *s;
    DB::DataBase<Auto> *a;
    int base;
    enum Type_base {
        r = 1, c = 2
    };
public:
    BDcommunity();

    ~BDcommunity();

    void print_Auto();

    void print_Shopper();

    Shopper in_Shopper();

    Auto in_Auto();

    int getBaseNow();

    void change_base();

    void checkIO(bool &in, bool &out);

    void create();

    void printBase();

    void switch_input(string newfilename);

    void switch_output(string newfilename);

    void add_new_record(Shopper rec);

    void add_new_record(Auto rec);

    void sort(int n);

    bool find(Shopper s);

    bool find(Auto s);

    bool del_record(Shopper &t);

    bool del_record(Auto &t);

    void del_copy(Shopper &T);

    void del_copy(Auto &T);

    int write();

    int load();

    void print_onec(Shopper &t);

    void print_onec(Auto &t);

    void del_base();

    void clear_screen();

    void menu();

    void del_copyOne(Shopper &T);

    void del_copyOne(Auto &T);

    void console(int argc, char **argv);

    Shopper parse_Shopper(ifstream &os);

    Auto parse_Auto(ifstream &os);

    Shopper parse_Shopper(string s);

    Auto parse_Auto(string s);

    void readInstruction(char *file);

    void report();
};

#endif //BASEDATA_BDCOMMUNITY_H
