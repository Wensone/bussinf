#ifndef READ

#define READ

#include <list>
#include <string>

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
    static int number;

public:
    Reader();

    static int getNumber();

    static bool setNumber(int number);

    bool operator==(const Reader &rhs) const;

    bool operator!=(const Reader &rhs) const;

    void setFio(const string &fio);

    void setAddress(const string &address);

    void setEmail(const string &email);

    void setBook_list(const string &book_list);

    void setTime_take(const string &time_take);

    void setTime_using(const string &time_using);

    void setBook_genre(const string &book_genre);

    void Generate(list <Reader> &lst);

    bool operator<(const Reader &);

    bool compare_my_class_na_easy_brat_function(Reader &b);

    friend ostream &operator<<(ostream &os, Reader &rd);

    void read(istream &in);

    string getBook_genre() ;

};

#endif //BASEDATA_READER_H
