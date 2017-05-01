#ifndef BASEDATA_READER_H
#define BASEDATA_READER_H

#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Reader {
private:

    string fio;
    string address;
    string email;
    string book_list; // список взятых книг
    string time_take; // время взятия
    string time_using; // срок пользования
    string book_genre; // жанры

public:
    void operator()(string filename);

    list <Reader> GenName();

    bool operator()(Reader &a, Reader &b);

    friend ostream &operator<<(ostream &os, Reader &rd);
};

#endif //BASEDATA_READER_H
