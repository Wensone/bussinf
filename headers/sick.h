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

    void setName(const string &name);

    void setSymptoms(const string &symptoms);

    void setProcedure(const string &procedure);

    void setMedics(const string &medics);

    static int getNumber();

    static bool setNumber(int pole);

};

#endif
