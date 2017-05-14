#ifndef def_sick
#define def_sick


#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class sick {
private:
    string name; // автор
    string symptoms; // название
    string procedure; // издательство
    string medics; // год издания {name 2табл в день | name2 раз в день}
    static int number;

public:
    void read(ifstream &in);

    void Generate(list <sick> &lst);

    bool operator==(const sick &rhs) const;

    bool operator!=(const sick &rhs) const;

    bool cmp(sick &b);

    bool operator<(const sick &rhs) const;

    friend ostream &operator<<(ostream &os, const sick &o);

    sick();

    void setMark(const string &mark);

    void setOutMark(const string &outMark);

    void setInMark(const string &inMark);

    void setDefects(const string &defects);

    void setEngine(const string &engine);

    void setPower(const string &power);

    void setYear(const string &year);

    void setType(const string &type);

    void setName_auc(const string &name_auc);

    void setDate(const string &date);

    void setFirst_price(const string &first_price);

    void setEnd_price(const string &end_price);

    void setLast_sold(const string &last_sold);

    static int getNumber();

    static bool setNumber(int pole);

};

#endif
