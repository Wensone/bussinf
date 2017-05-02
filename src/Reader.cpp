#include "../headers/Reader.h"


void Reader::GenName(list<Reader> &lst)
{
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
        fout << reader << endl;
		reader.write();
        i++;
    }
}

bool Reader::operator()(Reader &a, Reader &b)
{
    //compare
    return a.fio < b.fio;
}

ostream &operator<<(ostream &os, Reader &rd)
{
    os << rd.fio << 		" / "
       << rd.address << 	" / "
       << rd.email << 		" / "
       << rd.book_list << 	" / "
       << rd.time_take << 	" / "
       << rd.time_using << 	" / "
       << rd.book_genre;
    return os;
	//
}

void Reader::operator()(std::ifstream &in)
{
	string temp_str;
	getline(in, temp_str);
	
	unsigned long i = temp_str.find("/");
	this->fio = temp_str.substr(0, i-1);
	temp_str.erase(0, i+2);
	
	i = temp_str.find("/");
	this->address = temp_str.substr(0, i-1);
	temp_str.erase(0, i+2);
	
	i = temp_str.find("/");
	this->email = temp_str.substr(0, i-1);
	temp_str.erase(0, i+2);
	
	i = temp_str.find("/");
	this->book_list = temp_str.substr(0, i-1);
	temp_str.erase(0, i+2);
	
	i = temp_str.find("/");
	this->time_take = temp_str.substr(0, i-1);
	temp_str.erase(0, i+2);
	
	i = temp_str.find("/");
	this->time_using = temp_str.substr(0, i-1);
	temp_str.erase(0, i+2);
	
	i = temp_str.find("/");
	this->book_genre = temp_str.substr(0, i-1);
	
}

bool Reader::load() {
	//(*this)(fin);
}

bool Reader::write() {
	//fout << *this << std::endl;
}

Reader::Reader(const Reader &o) {

}

