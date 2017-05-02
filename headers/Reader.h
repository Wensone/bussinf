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

public:
    Reader() {};

    Reader(string fio, string address) : fio(fio), address(address) {};

	void GenName(list <Reader> &lst);

	bool sort(const Reader &, const Reader &);
	
	bool compare_my_class_na_easy_brat_function(Reader &b);
	
	friend ostream &operator<<(ostream &os, Reader &rd);

    void read(istream &in);
};

#endif //BASEDATA_READER_H
