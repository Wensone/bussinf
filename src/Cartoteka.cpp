#include "../headers/Cartoteka.h"

int Cartoteka::pole = 1;

void Cartoteka::Generate(list <Cartoteka> &lst)
{
    srand((unsigned) time(NULL));
    Cartoteka card;

    string author;
    string name;
    string publ;
    string year;
    string section;
    string avail;
    string val;

    ifstream afin("../Gencard/author");
    ifstream nfin("../Gencard/name");
    ifstream pfin("../Gencard/publ");
    ifstream yfin("../Gencard/year");
    ifstream sfin("../Gencard/section");
    ifstream avfin("../Gencard/avail");
    ifstream vfin("../Gencard/val");

    ofstream fout("gen_card");

    int aut;
    int nm;
    int pbl;
    int yer;
    int sct;
    int avl;
    int vl;

    afin >> aut;
    nfin >> nm;
    pfin >> pbl;
    yfin >> yer;
    sfin >> sct;
    avfin >> avl;
    vfin >> vl;

    string a[aut],
            b[nm],
            c[pbl],
            d[yer],
            f[sct],
            g[avl],
            e[vl];

    int i;
    i = 0;
    while (i < aut) {
        if (afin.eof()) break;

        getline(afin, a[i]);

        i++;
    }

    i = 0;
    while (i < nm) {
        if (nfin.eof()) break;

        getline(nfin, b[i]);
        i++;
    }

    i = 0;
    while (i < pbl) {
        if (pfin.eof()) break;

        getline(pfin, c[i]);
        i++;
    }

    i = 0;
    while (i < yer) {
        if (yfin.eof()) break;

        getline(yfin, d[i]);
        i++;
    }

    i = 0;
    while (i < sct) {
        if (sfin.eof()) break;

        getline(sfin, f[i]);
        i++;
    }

    i = 0;
    while (i < avl) {
        if (avfin.eof()) break;

        getline(avfin, g[i]);
        i++;
    }

    i = 0;
    while (i < vl) {
        if (vfin.eof()) break;

        getline(vfin, e[i]);
        i++;
    }

    i = 0;
    while (i < 60) {
        card.author = a[10 + rand() % 50];
        card.name = b[10 + rand() % 50];
        card.publishing = c[1 + rand() % 18];
        card.year = d[10 + rand() % 50];
        card.section = f[1 + rand() % 20];
        card.avail = g[10 + rand() % 50];
        card.valuation = e[10 + rand() % 50];

        lst.push_back(card);
        fout << card << endl;
        i++;
    }

}

ostream &operator<<(ostream &os, const Cartoteka &o)
{
    os << o.author << "/"
       << o.name << "/"
       << o.publishing << "/"
       << o.year << "/"
       << o.section << "/"
       << o.avail << "/"
       << o.valuation;
    return os;
}

void Cartoteka::read(ifstream &in)
{

}

bool Cartoteka::compare_my_class_na_easy_brat_function(Cartoteka &b)
{
    short c = 0;
    if (this->author.size() > 1) ++c;
    if (this->avail.size() > 1) ++c;
    if (this->name.size() > 1) ++c;
    if (this->valuation.size() > 1) ++c;
    if (this->year.size() > 1) ++c;
    if (this->publishing.size() > 1) ++c;
    if (this->section.size() > 1) ++c;

    if (this->author.size() > 1 && this->author == b.author) --c;
    if (this->avail.size() > 1 && this->avail == b.avail) --c;
    if (this->name.size() > 1 && this->name == b.name) --c;
    if (this->valuation.size() > 1 && this->valuation == b.valuation) --c;
    if (this->year.size() > 1 && this->year == b.year) --c;
    if (this->year.size() > 1 && this->year == b.year) --c;
    if (this->section.size() > 1 && this->section == b.section) --c;

    return (c == 0);
}

void Cartoteka::setAuthor(const string &author)
{
    Cartoteka::author = author;
}

void Cartoteka::setName(const string &name)
{
    Cartoteka::name = name;
}

void Cartoteka::setPublishing(const string &publishing)
{
    Cartoteka::publishing = publishing;
}

void Cartoteka::setYear(const string &year)
{
    Cartoteka::year = year;
}

void Cartoteka::setSection(const string &section)
{
    Cartoteka::section = section;
}

void Cartoteka::setAvail(const string &avail)
{
    Cartoteka::avail = avail;
}

void Cartoteka::setValuation(const string &valuation)
{
    Cartoteka::valuation = valuation;
}

Cartoteka::Cartoteka()
{
    author = avail = name = year = valuation = publishing = section = "";
}

int Cartoteka::getPole()
{
    return pole;
}

bool Cartoteka::setPole(int pole)
{
    if (pole < 0 || pole > 7)
        return false;
    Cartoteka::pole = pole;
    return true;
}

bool Cartoteka::operator==(const Cartoteka &rhs) const
{
    return author == rhs.author &&
           name == rhs.name &&
           publishing == rhs.publishing &&
           year == rhs.year &&
           section == rhs.section &&
           avail == rhs.avail &&
           valuation == rhs.valuation;
}

bool Cartoteka::operator!=(const Cartoteka &rhs) const
{
    return !(rhs == *this);
}

bool Cartoteka::operator<(const Cartoteka &rhs) const
{
    if (pole == 1)
        return author < rhs.author;
    if (pole == 2)
        return name < rhs.name;
    if (pole == 3)
        return publishing < rhs.publishing;
    if (pole == 4)
        return year < rhs.year;
    if (pole == 5)
        return section < rhs.section;
    if (pole == 6)
        return avail < rhs.avail;
    return valuation < rhs.valuation;
}