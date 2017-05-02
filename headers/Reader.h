#ifndef READ
#define READ

#include <list>
#include <string>
#include "DataIO.h"

using namespace std;

class Reader : public IOResults {
private:
	string fio;
	string address;
	string email;
	string book_list; // список взятых книг
	string time_take; // время взятия
	string time_using; // срок пользования
	string book_genre; // жанры

public:
	Reader(string in, string out) : IOResults(in, out) {};
	
	void GenName(list <Reader> &lst);
	
	void write() override;
	
	void read() override;
	
	void load();
	
	bool sort(const Reader &, const Reader &);
	
	bool compare_my_class_na_easy_brat_function(Reader &b);
	
	friend ostream &operator<<(ostream &os, Reader &rd);
};

#endif //BASEDATA_READER_H
