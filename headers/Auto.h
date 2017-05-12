#ifndef BASEDATA_CARTOTEKA_H
#define BASEDATA_CARTOTEKA_H


#include <fstream>
#include <list>

using namespace std;

class Auto {
private:
    string mark; // автор
    string outMark; // название
    string inMark; // издательство
    string defects; // год издания
    string engine; // радел(спец. литература, хобби, хуеби)
    string power; // наличие
    string year; // оценка
    string type;
    string name_auc;
    string date;
    string first_price;
    string end_price;
    string last_sold;
    static int number;

public:
    void read(ifstream &in);

    void Generate(list <Auto> &lst);

    bool operator==(const Auto &rhs) const;

    bool operator!=(const Auto &rhs) const;

    bool cmp(Auto &b);

    bool operator<(const Auto &rhs) const;

    friend ostream &operator<<(ostream &os, const Auto &o);

    Auto();

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

#endif //BASEDATA_CARTOTEKA_H
