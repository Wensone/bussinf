#include <fstream>
#include <algorithm>
#include "../headers/Shopper.h"

int Shopper::number = 1;

string Shopper::i2s(long long value) {
	string res;
	do {
		switch(value % 10) {
			case 0: res = "0" + res; break;
			case 1: res = "1" + res; break;
			case 2: res = "2" + res; break;
			case 3: res = "3" + res; break;
			case 4: res = "4" + res; break;
			case 5: res = "5" + res; break;
			case 6: res = "6" + res; break;
			case 7: res = "7" + res; break;
			case 8: res = "8" + res; break;
			case 9: res = "9" + res; break;
		}
		value /=  10;
	} while (value);
	return res;
}

void Shopper::Generate(list <Shopper> &lst)
{
	srand((unsigned)time(0));
	Shopper shopper;
	
	ifstream lfin("list_of_car");
	ifstream tfin("time_buy");
	
	//ФИО, адрес, e-mail, список взятых книг
	//времени взятия книги
	//срока пользования книгой
	//предпочитаемые жанры.
	
	/*
		string passport;								// int
		string balance;									// int
		string list_of_car; //   		// str
		string time_buy; //  				// str
		string car; //  					// int
		string prices;									// int
		string data_of_buy; // 					// int
		string discount;								// int
    */
	
	ofstream fout("shopper");
	
	int list_of_car;
	int time_buy;
	
	lfin >> list_of_car;
	tfin >> time_buy;
	
	string a[list_of_car],
			b[time_buy];
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
	/*
		string passport;								// int
		string balance;									// int
		string list_of_car; //   						// str
		string time_buy; //  							// str
		string car; //  								// int
		string prices;									// int
		string data_of_buy; // 							// int
		string discount;								// int
    */
	while (i < 60) {
		shopper.passport = i2s(5000 + rand() % 1000);
		shopper.passport += i2s(111111 + rand() % 888888);
		shopper.balance = i2s(100000 + rand() % 10000000);
		shopper.list_of_car = a[1 + rand() % list_of_car];
		shopper.time_buy = b[1 + rand() % time_buy];
		shopper.car = i2s(1 + rand() % (8*365+(366+366)));
		shopper.prices = i2s(80000 + rand() % 10000000);
		shopper.data_of_buy = i2s(1 + rand() % (8*365+(366+366)));
		shopper.discount = i2s(20000 + rand() % 300000);
		
		lst.push_back(shopper);
		fout << shopper << endl;
		i++;
	}
}

ostream &operator<<(ostream &os, Shopper &rd)
{
    os << rd.passport << " / "
       << rd.balance << " / "
       << rd.list_of_car << " / "
       << rd.time_buy << " / "
       << rd.car << " / "
       << rd.prices << " / "
       << rd.data_of_buy << " / "
       << rd.discount;
    return os;
}

bool Shopper::operator<(const Shopper &b)
{
    if (number == 1) return passport < b.passport;
    if (number == 2) return balance < b.balance;
    if (number == 3) return list_of_car < b.list_of_car;
    if (number == 4) return time_buy < b.time_buy; // список взятых книг
    if (number == 5) return car < b.car; // время взятия
    if (number == 6) return prices < b.prices; // срок пользования
    if (number == 7) return data_of_buy < b.data_of_buy; // срок пользования
    return discount < b.discount; // жанры

}

bool Shopper::cmp(Shopper &b)
{
    short c = 0;
    if (this->passport.size() > 1) ++c;
    if (this->balance.size() > 1) ++c;
    if (this->list_of_car.size() > 1) ++c;
    if (this->time_buy.size() > 1) ++c;
    if (this->prices.size() > 1) ++c;
    if (this->car.size() > 1) ++c;
    if (this->data_of_buy.size() > 1) ++c;
    if (this->discount.size() > 1) ++c;

    if (this->passport.size() > 1 && this->passport == b.passport) --c;
    if (this->balance.size() > 1 && this->balance == b.balance) --c;
    if (this->list_of_car.size() > 1 && this->list_of_car == b.list_of_car) --c;
    if (this->prices.size() > 1 && this->prices == b.prices) --c;
    if (this->time_buy.size() > 1 && this->time_buy == b.time_buy) --c;
    if (this->car.size() > 1 && this->car == b.car) --c;
    if (this->data_of_buy.size() > 1 && this->data_of_buy == b.data_of_buy) --c;
    if (this->discount.size() > 1 && this->discount == b.discount) --c;

    return (c == 0);
}

void Shopper::read(istream &fin)
{
    string temp_str;

    getline(fin, temp_str);


    unsigned long i = temp_str.find("/");
    this->passport = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->balance = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->list_of_car = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->time_buy = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->car = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->prices = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->data_of_buy = temp_str.substr(0, i - 1);
    temp_str.erase(0, i + 2);

    i = temp_str.find("/");
    this->discount = temp_str.substr(0, i - 1);
}

int Shopper::getNumber()
{
    return number;
}

bool Shopper::setNumber(int number)
{
    if (number < 1 || number > 8)
        return false;
    Shopper::number = number;
    return true;
}


Shopper::Shopper()
{
    balance = passport = list_of_car = time_buy = car = data_of_buy = prices = discount = "";
}

void Shopper::setPassport(const string &passport)
{
    Shopper::passport = passport;
}

void Shopper::setBalance(const string &balance)
{
    Shopper::balance = balance;
}

void Shopper::setList_of_car(const string &list_of_car)
{
    Shopper::list_of_car = list_of_car;
}

void Shopper::setTime_buy(const string &time_buy)
{
    Shopper::time_buy = time_buy;
}

void Shopper::setCar(const string &car)
{
    Shopper::car = car;
}

void Shopper::setPrices(const string &prices)
{
    Shopper::prices = prices;
}

void Shopper::setData_of_buy(const string &data_of_buy)
{
    Shopper::data_of_buy = data_of_buy;
}

void Shopper::setDiscount(const string &discount)
{
    Shopper::discount = discount;
}

bool Shopper::operator==(const Shopper &rhs) const
{
    return passport == rhs.passport &&
           balance == rhs.balance &&
           list_of_car == rhs.list_of_car &&
           time_buy == rhs.time_buy &&
           car == rhs.car &&
           prices == rhs.prices &&
           data_of_buy == rhs.data_of_buy &&
           discount == rhs.discount;
}

bool Shopper::operator!=(const Shopper &rhs) const
{
    return !(rhs == *this);
}

