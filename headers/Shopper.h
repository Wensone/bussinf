#ifndef READ
#define READ

#include <list>
#include <string>

using namespace std;

class Shopper {
private:
    string passport;								// int
    string balance;									// int
    string list_of_car; // список взятых книг		// str
    string time_buy; // время взятия				// str
    string car; // срок пользования					// int
    string prices;									// int
    string data_of_buy; // жанры					// int
    string discount;								// int
    static int number;
public:
    void setPassport(const string &passport);

    void setBalance(const string &balance);

    void setList_of_car(const string &list_of_car);

    void setTime_buy(const string &time_buy);

    void setCar(const string &car);

    void setPrices(const string &prices);

    void setData_of_buy(const string &data_of_buy);

    void setDiscount(const string &discount);

    bool operator==(const Shopper &rhs) const;

    bool operator!=(const Shopper &rhs) const;

    Shopper();

    static int getNumber();

    static bool setNumber(int number);

    void Generate(list <Shopper> &lst);

    bool operator<(const Shopper &);

    bool cmp(Shopper &b);

    friend ostream &operator<<(ostream &os, Shopper &rd);

    void read(istream &in);
	
	string i2s(long long value);

};

#endif //BASEDATA_READER_H
