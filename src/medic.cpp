#include <fstream>
#include "../headers/medic.h"

int medic::number = 1;

string medic::i2s(long long value)
{
    string res;
    do {
        switch (value % 10) {
            case 0:
                res = "0" + res;
                break;
            case 1:
                res = "1" + res;
                break;
            case 2:
                res = "2" + res;
                break;
            case 3:
                res = "3" + res;
                break;
            case 4:
                res = "4" + res;
                break;
            case 5:
                res = "5" + res;
                break;
            case 6:
                res = "6" + res;
                break;
            case 7:
                res = "7" + res;
                break;
            case 8:
                res = "8" + res;
                break;
            case 9:
                res = "9" + res;
                break;
        }
        value /= 10;
    } while (value);
    return res;
}

void medic::Generate(list <medic> &lst)
{
    srand((unsigned) time(0));
    medic shopper;

    ifstream nfin("../Genpers/name");
    ifstream afin("../Genpers/amt");
    ifstream pfin("../Genpers/perm");
    ifstream sfin("../Genpers/shelf");
    ifstream rfin("../Genpers/prices");
    ifstream lfin("../Genpers/sold");
	
	ofstream fout("medic");
	
    /*
        string name; // название				// int
        string amt; // количество // int
        string permutability; // взаимозаменяемость				// str
        string shelf_life; // срок годности						// str
        string prices;    // цена
        string sold;
    */
	
	int name;
	int amt;
	int permutability;
	int shelf_life;
	int prices;
	int sold;
	
	nfin >> name;;
	afin >> amt;;
	pfin >> permutability;;
	sfin >> shelf_life;;
	rfin >> prices;;
	lfin >> sold;;

    string a[name],
            b[amt],
            c[permutability],
			d[shelf_life],
			f[prices],
			g[sold];

    int i;
    i = 0;
    while (i < name) {
        if (nfin.eof()) break;

        getline(nfin, a[i]);

        i++;
    }
    i = 0;
    while (i < amt) {
        if (afin.eof()) break;

        getline(afin, b[i]);
        i++;
    }

    i = 0;
    while (i < permutability) {
        if (pfin.eof()) break;

        getline(pfin, c[i]);
        i++;
    }
	i = 0;
	while (i < shelf_life) {
		if (sfin.eof()) break;
		
		getline(sfin, d[i]);
		i++;
	}
	i = 0;
	while (i < prices) {
		if (rfin.eof()) break;
		
		getline(rfin, f[i]);
		i++;
	}
	i = 0;
	while (i < sold) {
		if (lfin.eof()) break;
		
		getline(lfin, g[i]);
		i++;
	}
	
    i = 0;
    while (i < 60) {
		shopper.name = a[1+rand() % name];
		shopper.amt = b[1+rand() % amt];
		shopper.permutability = c[1+rand() % permutability];
		shopper.shelf_life = d[1+rand() % shelf_life];
		shopper.prices = f[1+rand() % prices];
		shopper.sold = g[1+rand() % sold];
		
        lst.push_back(shopper);
        fout << shopper << endl;
        i++;
    }
}

ostream &operator<<(ostream &os, medic &rd)
{
    os << rd.name << " / "
       << rd.amt << " / "
       << rd.permutability << " / "
       << rd.shelf_life << " / "
       << rd.prices << " / "
       << rd.sold;
    return os;
}

bool medic::operator<(const medic &b)
{
    if (number == 1) return name < b.name;
    if (number == 2) return amt < b.amt;
    if (number == 3) return permutability < b.permutability;
    if (number == 4) return shelf_life < b.shelf_life; // список взятых книг
    if (number == 5) return prices < b.prices; // срок пользования
    return sold < b.sold;
}

bool medic::cmp(medic &b)
{
    short c = 0;
    if (this->name.size() > 1) ++c;
    if (this->amt.size() > 1) ++c;
    if (this->permutability.size() > 1) ++c;
    if (this->shelf_life.size() > 1) ++c;
    if (this->prices.size() > 1) ++c;
    if (this->sold.size() > 1) ++c;

    if (this->name.size() > 1 && this->name == b.name) --c;
    if (this->amt.size() > 1 && this->amt == b.amt) --c;
    if (this->permutability.size() > 1 && (b.permutability.find(permutability)) != string::npos) --c;
    if (this->prices.size() > 1 && this->prices == b.prices) --c;
    if (this->shelf_life.size() > 1 && this->shelf_life == b.shelf_life) --c;
    if (this->sold.size() > 1 && this->sold == b.sold) --c;

    return (c == 0);
}

void medic::read(istream &fin)
{
}

int medic::getNumber()
{
    return number;
}

bool medic::setNumber(int number)
{
    if (number < 1 || number > 6)
        return false;
    medic::number = number;
    return true;
}

medic::medic()
{
    amt = name = permutability = shelf_life = prices = "";
}

void medic::setName(const string &name)
{
    medic::name = name;
}

void medic::setAmt(const string &amt)
{
    medic::amt = amt;
}

void medic::setPermutability(const string &permutability)
{
    medic::permutability = permutability;
}

void medic::setShelf_life(const string &shelf_life)
{
    medic::shelf_life = shelf_life;
}

void medic::setPrices(const string &prices)
{
    medic::prices = prices;
}

bool medic::operator==(const medic &rhs) const
{
    return name == rhs.name &&
           amt == rhs.amt &&
           permutability == rhs.permutability &&
           shelf_life == rhs.shelf_life &&
           prices == rhs.prices;
}

bool medic::operator!=(const medic &rhs) const
{
    return !(rhs == *this);
}

void medic::setSold(const string &sold)
{
    medic::sold = sold;
}

const string &medic::getSold() const
{
    return sold;
}

const string &medic::getAmt() const
{
    return amt;
}

const string &medic::getPrices() const
{
    return prices;
}

