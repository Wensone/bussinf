#include "../headers/DataBase.h"
#include "../headers/Reader.h"
#include "../headers/BDcommunity.h"
#include "../headers/Cartoteka.h"

int main(int argc, char ** argv)
{/*
   BDcommunity base;
    base.menu();*/
    string str;
    DB::DataBase<Reader> rd("", "");
    rd.generate();
    rd.print_all();
    Reader t;
    getline(cin, str);
    t.setFio(str);
    if(rd.del_rec(t)) rd.print_all();

}