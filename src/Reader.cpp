#include "../headers/Reader.h"

friend ostream &operator<<(ostream &os, Reader &rd)
{
    os << rd.fio << endl
       << rd.address << endl
       << rd.email << endl
       << rd.book_list << endl
       << rd.time_take << endl
       << rd.time_using << endl
       << rd.book_genre << endl;
    return os;
}