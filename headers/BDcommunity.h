#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include <iostream>
#include <string>
#include "Cartoteka.h"

using namespace std;

class BDcommunity {
private:
    Reader card;
    Cartoteka reader;
	int base;
	enum Type_base {r, c};
public:
	void change_base()
    {

    }
    // выбираем базу для работы

    void create(int type)
    {

    }
    // создание базы (описание внутри)
	//bool
	
};


#endif //BASEDATA_BDCOMMUNITY_H
