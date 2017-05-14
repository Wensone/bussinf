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

    ifstream lfin("../Genpers/permutability");
    ifstream tfin("../Genpers/shelf_life");
    ifstream cfin("../Genpers/car");

    //ФИО, адрес, e-mail, список взятых книг
    //времени взятия книги
    //срока пользования книгой
    //предпочитаемые жанры.

    /*
        string name; // серия и номер паспорта				// int
        string amt; // баланс покупателя					// int
        string permutability; // список автомобилей				// str
        string shelf_life; // время покупки						// str
        string car; // покупаемая машина						// str
        string prices;	// цена									// int
        string data_of_buy; // дата покупки						// int
        string discount; // скидон								// int
    */

    ofstream fout("shopper");

    int list_of_car;
    int time_buy;
    int car;

    lfin >> list_of_car;
    tfin >> time_buy;
    cfin >> car;

    string a[list_of_car],
            b[time_buy],
            c[car];

    int i;
    i = 0;
    while (i < list_of_car) {
        if (lfin.eof()) break;

        getline(lfin, a[i]);

        i++;
    }
    i = 0;
    while (i < time_buy) {
        if (tfin.eof()) break;

        getline(tfin, b[i]);
        i++;
    }

    i = 0;
    while (i < car) {
        if (cfin.eof()) break;

        getline(cfin, c[i]);
        i++;
    }

    i = 0;
    while (i < 60) {
        shopper.name = i2s(5000 + rand() % 1000);
        shopper.name += i2s(111111 + rand() % 888888);
        shopper.amt = i2s(100000 + rand() % 10000000);
        shopper.permutability = a[1 + rand() % list_of_car - 1];
        shopper.shelf_life = b[1 + rand() % time_buy - 1];
        c[1 + rand() % car - 1];
        shopper.prices = i2s(80000 + rand() % 10000000);
        i2s(1 + rand() % (8 * 365 + (366 + 366)));
        i2s(20000 + rand() % 300000);

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

