#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include "sick.h"
#include "medic.h"
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
    DB::DataBase<medic> *m;
    DB::DataBase<sick> *s;
    int base;
    enum Type_base {
        r = 1, c = 2
    };
public:
    BDcommunity();

    ~BDcommunity();

    void prtin_sick();

    void print_medic();

    medic in_Medic();

    sick in_Sick();

    int getBaseNow();

    void change_base();

    void checkIO(bool &in, bool &out);

    void create();

    void printBase();

    void switch_input(string newfilename);

    void switch_output(string newfilename);

    void add_new_record(medic rec);

    void add_new_record(sick rec);

    void sort(int n);

    bool find(medic s);

    bool find(sick s);

    bool del_record(medic &t);

    bool del_record(sick &t);

    void del_copy(medic &T);

    void del_copy(sick &T);

    int write();

    int load();

    void print_onec(medic &t);

    void print_onec(sick &t);

    void del_base();

    void clear_screen();

    void menu();

    void del_copyOne(medic &T);

    void del_copyOne(sick &T);

    void console(int argc, char **argv);

    medic parse_Medic(ifstream &os);

    sick parse_Sick(ifstream &os);

    medic parse_Medic(string s);

    sick parse_Sick(string s);

    void readInstruction(char *file);

    void report();

    void heal(string bolezn);
};

#endif //BASEDATA_BDCOMMUNITY_H
