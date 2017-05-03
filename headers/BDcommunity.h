#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include <iostream>
#include <string>
#include "Cartoteka.h"

using namespace std;

class BDcommunity {
private:
    DB::DataBase<Reader> *reader;
    DB::DataBase<Cartoteka> *card;
    int base;
    enum Type_base {
        r = 1, c = 2
    };
public:
    BDcommunity()
    {
        cout << "Enter starting input and output file by Readers" << endl;
        string in, out;
        cin >> in >> out;
        reader = new DB::DataBase<Reader>(in, out);

        cout << "Enter starting input and output file by Cartoteka" << endl;
        cin >> in >> out;
        card = new DB::DataBase<Cartoteka>(in, out);

        cout << "Enable commands :" << endl;
        // commands
        cout << "starting base for edition" << endl;
        base = 1;
    }

    ~BDcommunity()
    {
        delete card;
        delete reader;
    }

    int getBaseNow()
    {
        return base;
    }

    // выбираем базу для работы
    void change_base()
    {
        cout << "Enter numbedr Base :" << endl
             << "1.Reader\n2.Cartoteka" << endl;
        do {
            cin >> base;
            if (base != r || base != c) {
                cout << "Incorrect number of bd" << endl;
            }
        } while (base < r || base > c);

    }

    void create()
    {
        switch (base) {
            case r : {
                reader->generate();
                break;
            }

            case c : {
                card->generate();
                break;
            }
        }
    }

    void printBase()
    {
        switch (base) {
            case r : {
                reader->print_all();
                break;
            }
            case c : {
                card->print_all();
                break;
            }
        }
    }
    void menu()
    {
        cout <<
    }

};


#endif //BASEDATA_BDCOMMUNITY_H
