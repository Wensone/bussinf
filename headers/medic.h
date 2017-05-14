#ifndef def_medic
#define def_medic

#include <list>
#include <string>

using namespace std;

class medic {
private:
    string name; // название				// int
    string amt; // количество // int
    string permutability; // взаимозаменяемость				// str
    string shelf_life; // срок годности						// str
    string prices;    // цена
    string sold;
    static int number;
public:
    void setSold(const string &sold);

    bool operator==(const medic &rhs) const;

    bool operator!=(const medic &rhs) const;

    medic();

    const string &getPrices() const;

    const string &getAmt() const;

    static int getNumber();

    static bool setNumber(int number);

    void Generate(list <medic> &lst);

    bool operator<(const medic &);

    bool cmp(medic &b);

    friend ostream &operator<<(ostream &os, medic &rd);

    void read(istream &in);

    const string &getSold() const;

    string i2s(long long value);

    void setName(const string &name);

    void setAmt(const string &amt);

    void setPermutability(const string &permutability);

    void setShelf_life(const string &shelf_life);

    void setPrices(const string &prices);

};

#endif
