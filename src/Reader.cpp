#include <fstream>
#include "../headers/Reader.h"


void Reader::GenName(list<Reader> &lst) {
	srand((unsigned int) time(NULL));
	
	Reader reader("", "../Genname/gen_data");
	
	ifstream afin("../Genname/address");
	ifstream bfin("../Genname/books");
	ifstream efin("../Genname/email");
	ifstream ttfin("../Genname/time_take");
	ifstream tufin("../Genname/time_using");
	ifstream nfin("../Genname/names");
	ifstream gfin("../Genname/ganer");
	
	//ФИО, адрес, e-mail, список взятых книг
	//времени взятия книги
	//срока пользования книгой
	//предпочитаемые жанры.
	
	//ofstream fout("../Genname/gen_data");
	
	int fio;
	int adr;
	int mail;
	int book;
	int ttake;
	int tusing;
	int gen;
	
	nfin >> fio;
	afin >> adr;
	efin >> mail;
	bfin >> book;
	ttfin >> ttake;
	tufin >> tusing;
	gfin >> gen;
	
	string a[fio],
			b[adr],
			c[mail],
			d[book],
			f[ttake],
			g[tusing],
			e[gen];
	
	int i;
	i = 0;
	while (i < fio) {
		if (nfin.eof()) break;
		
		getline(nfin, a[i]);
		
		i++;
	}
	i = 0;
	while (i < adr) {
		if (afin.eof()) break;
		
		getline(afin, b[i]);
		i++;
	}
	i = 0;
	while (i < mail) {
		if (efin.eof()) break;
		
		getline(efin, c[i]);
		i++;
	}
	i = 0;
	while (i < book) {
		if (bfin.eof()) break;
		
		getline(bfin, d[i]);
		i++;
	}
	i = 0;
	while (i < ttake) {
		if (ttfin.eof()) break;
		
		getline(ttfin, f[i]);
		i++;
	}
	i = 0;
	while (i < tusing) {
		if (tufin.eof()) break;
		
		getline(tufin, g[i]);
		i++;
	}
	i = 0;
	while (i < gen) {
		if (gfin.eof()) break;
		
		getline(gfin, e[i]);
		i++;
	}
	
	i = 0;
	while (i < 60) {
		reader.fio = a[10 + rand() % 50];
		reader.address = b[10 + rand() % 50];
		reader.email = c[10 + rand() % 50];
		
		int j = 1 + rand() % 3;
		reader.book_list = d[10 + rand() % 50];
		reader.time_take = f[10 + rand() % 50];
		reader.time_using = g[10 + rand() % 50];
		reader.book_genre = e[1 + rand() % 11];
		
		for (; j > 0; j--) {
			reader.book_list += "|" + d[10 + rand() % 50];
			reader.time_take += "|" + f[10 + rand() % 50];
			reader.time_using += "|" + g[10 + rand() % 50];
			reader.book_genre += "|" + e[1 + rand() % 11];
		}
		
		lst.push_back(reader);
		//reader.write();
		i++;
	}
}

ostream &operator<<(ostream &os, Reader &rd) {
	os << rd.fio << " / "
	   << rd.address << " / "
	   << rd.email << " / "
	   << rd.book_list << " / "
	   << rd.time_take << " / "
	   << rd.time_using << " / "
	   << rd.book_genre;
	return os;
	//
}

void Reader::write() {
	if (!valid_write()) return;
	
	ofstream fout(out);
	fout << *this << endl;
	
	fout.close();
}

void Reader::load() {
	if (!valid_read())
		return;
	
	ifstream fin(in);
	
	string temp_str;
	
	getline(fin, temp_str);
	
	unsigned long i = temp_str.find("/");
	this->fio = temp_str.substr(0, i - 1);
	temp_str.erase(0, i + 2);
	
	i = temp_str.find("/");
	this->address = temp_str.substr(0, i - 1);
	temp_str.erase(0, i + 2);
	
	i = temp_str.find("/");
	this->email = temp_str.substr(0, i - 1);
	temp_str.erase(0, i + 2);
	
	i = temp_str.find("/");
	this->book_list = temp_str.substr(0, i - 1);
	temp_str.erase(0, i + 2);
	
	i = temp_str.find("/");
	this->time_take = temp_str.substr(0, i - 1);
	temp_str.erase(0, i + 2);
	
	i = temp_str.find("/");
	this->time_using = temp_str.substr(0, i - 1);
	temp_str.erase(0, i + 2);
	
	i = temp_str.find("/");
	this->book_genre = temp_str.substr(0, i - 1);
	
	fin.close();
}

bool Reader::sort(const Reader &a, const Reader &b) {
	if (this->fio.size()) return a.fio < b.fio;
	if (this->address.size()) return a.address < b.address;
	if (this->email.size()) return a.email < b.email;
	if (this->book_list.size()) return a.book_list < b.book_list; // список взятых книг
	if (this->time_take.size()) return a.time_take < b.time_take; // время взятия
	if (this->time_using.size()) return a.time_using < b.time_using; // срок пользования
	if (this->book_genre.size()) return a.book_genre < b.book_genre; // жанры
	
	return false;
}

bool Reader::compare_my_class_na_easy_brat_function(Reader &b) {
	short c = 0;
	if (this->fio.size()) ++c;
	if (this->address.size()) ++c;
	if (this->email.size()) ++c;
	if (this->book_list.size()) ++c;
	if (this->time_take.size()) ++c;
	if (this->time_using.size()) ++c;
	if (this->book_genre.size()) ++c;
	
	if (this->fio.size() && this->fio == b.fio) --c;
	if (this->address.size() && this->address == b.address) --c;
	if (this->email.size() && this->email == b.email) --c;
	if (this->book_list.size() && this->book_list == b.book_list) --c;
	if (this->time_take.size() && this->time_take == b.time_take) --c;
	if (this->time_using.size() && this->time_using == b.time_using) --c;
	if (this->book_genre.size() && this->book_genre == b.book_genre) --c;
	
	return !c;
}

void Reader::read() {

}
