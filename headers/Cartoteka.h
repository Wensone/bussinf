#ifndef BASEDATA_CARTOTEKA_H
#define BASEDATA_CARTOTEKA_H

#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cartoteka {
private:
	string author; // автор
	string name; // название
	string publishing; // издательство
	string year; // год издания
	string section; // радел(спец. литература, хобби, хуеби)
	string avail; // наличие
	string valuation; // оценка

public:
	void operator()(string filename);
	
	list <Cartoteka> GenCard();
	
	bool operator()(Cartoteka &a, Cartoteka &b);
	
	friend ostream & operator << (ostream &os, const Cartoteka &o);
};

#endif //BASEDATA_CARTOTEKA_H
