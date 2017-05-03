#include <fstream>
#include <algorithm>
#include "../headers/Reader.h"

int Reader::number = 3;

void Reader::Generate(list <Reader> &lst)
{
    srand((unsigned int) time(NULL));

    Reader reader;

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

    ofstream fout("../Genname/gen_data");

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
        i++;
    }
}

ostream &operator<<(ostream &os, Reader &rd)
{
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

bool Reader::operator<(const Reader &b)
{
    if (number == 1) return fio < b.fio;
    if (number == 2) return address < b.address;
    if (number == 3) return email < b.email;
    if (number == 4) return book_list < b.book_list; // список взятых книг
    if (number == 5) return time_take < b.time_take; // время взятия
    if (number == 6) return time_using < b.time_using; // срок пользования
    if (number == 7) return book_genre < b.book_genre; // жанры

    return false;
}

bool Reader::compare_my_class_na_easy_brat_function(Reader &b)
{
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

void Reader::read(istream &fin)
{
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
}

int Reader::getNumber()
{
    return number;
}

bool Reader::setNumber(int number)
{
    if (number < 0 || number > 7)
        return false;
    Reader::number = number;
    return true;
}

void Reader::setFio(const string &fio)
{
    Reader::fio = fio;
}

void Reader::setAddress(const string &address)
{
    Reader::address = address;
}

void Reader::setEmail(const string &email)
{
    Reader::email = email;
}

void Reader::setBook_list(const string &book_list)
{
    Reader::book_list = book_list;
}

void Reader::setTime_take(const string &time_take)
{
    Reader::time_take = time_take;
}

void Reader::setTime_using(const string &time_using)
{
    Reader::time_using = time_using;
}

void Reader::setBook_genre(const string &book_genre)
{
    Reader::book_genre = book_genre;
}

Reader::Reader()
{
    address = fio = email = time_take = time_using = book_genre = book_list = "";
}

