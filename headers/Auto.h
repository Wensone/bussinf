#ifndef BASEDATA_CARTOTEKA_H
#define BASEDATA_CARTOTEKA_H


#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Auto {
private:
	string mark; // марка авто						стр
	string outMark; // оценка внешнего вида			инт
	string inMark; // оценка внутреннего вида		инт
	string defects; // дефекты						стр
	string engine; // двигатель						стр
	string power; // мощьность						инт
	string year; // год								инт
	string type; // Тип								стр
	string name_auc; // Название аукциона продажи	стр
	string date; // дата продажи					инт
	string first_price; // начальная цена			инт
	string end_price; // цена продажи				инт
	string last_sold; // Проследняя продажа			инт
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

    const string &getEnd_price() const;

    const string &getMark() const;

};

#endif //BASEDATA_CARTOTEKA_H
