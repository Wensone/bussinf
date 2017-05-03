#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include <iostream>
#include <string>

using namespace std;

template <class A, class B>
class BDcommunity {
private:
    A card;
    B reader;
	int base;
	enum Type_base {A, B};
public:
	BDcommunity() = delete;
	BDcommunity(A card, B read);
	
	void change_base(); // выбираем базу для работы
	void create(int type); // создание базы (описание внутри)
	//bool
	
};

#endif //BASEDATA_BDCOMMUNITY_H
