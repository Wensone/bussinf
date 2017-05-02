#ifndef BASEDATA_READER_H
#define BASEDATA_READER_H

#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include "DataIO.h"

using namespace std;

class Reader : public DataIO {
private:
    string fio;
    string address;
    string email;
    string book_list; // список взятых книг
    string time_take; // время взятия
    string time_using; // срок пользования
    string book_genre; // жанры
	
public:
	Reader(std::string in, std::string out) : DataIO(in, out) {};
	
    void GenName(list<Reader> &lst);
	
	bool write() override;
	
	bool load(std::ifstream &in);
	
	bool operator()(Reader &a, Reader &b);

    friend ostream &operator<<(ostream &os, Reader &rd);
};

#endif //BASEDATA_READER_H
