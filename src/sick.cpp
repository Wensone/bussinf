#include "../headers/sick.h"

int sick::number = 1;


string i2s(int value) {
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

void sick::Generate(list <sick> &lst)
{
    srand((unsigned)time(0));
    sick autist;

    ifstream mfin("../Genavto/name");
    ifstream dfin("../Genavto/medics");
    ifstream efin("../Genavto/engine");
    ifstream tfin("../Genavto/type");
    ifstream afin("../Genavto/auc");
    ofstream fout("../Genavto/gen_data");

    int mark;
    int defects;
    int engine;
    int type;
    int auc;

    mfin >> mark;
    dfin >> defects;
    efin >> engine;
    tfin >> type;
    afin >> auc;

    string a[mark],
            b[defects],
            c[engine],
            d[type],
            f[auc];
    int i;
    i = 0;
    while (i < mark) {
        if (mfin.eof()) break;

        getline(mfin, a[i]);

        i++;
    }
    i = 0;
    while (i < defects) {
        if (dfin.eof()) break;

        getline(dfin, b[i]);
        i++;
    }
    i = 0;
    while (i < engine) {
        if (efin.eof()) break;

        getline(efin, c[i]);
        i++;
    }
    i = 0;
    while (i < type) {
        if (tfin.eof()) break;

        getline(tfin, d[i]);
        i++;
    }
    i = 0;
    while (i < auc) {
        if (afin.eof()) break;

        getline(afin, f[i]);
        i++;
    }

    i = 0;
    while (i < 60) {
        autist.name = a[1 + rand() % (mark - 1)];
        autist.symptoms = i2s(1 + rand() % (10 - 1));
        autist.procedure = i2s(1 + rand() % 10 - 1);
        autist.medics = b[1 + rand() % (defects - 1)];
        c[1 + rand() % (engine - 1)];
        i2s(1 + rand() % 1500 - 1);
        i2s(1900 + rand() % 2017 - 1);
        d[1 + rand() % (type - 1)];
        f[1 + rand() % (auc - 1)];
        int day = 1 + rand() % 29;
        int month = 1 + rand() % 11;
        int year = 1900 + rand() % 2017;
        i2s(day);
        autist.date += i2s(month);
        autist.date += i2s(year);
        i2s(1 + rand() % 20000 - 1);
        i2s(1 + rand() % 30000 - 1);
        i2s(1 + rand() % 10 - 1);

        lst.push_back(autist);
        fout << autist << endl;
        i++;
    }

}

ostream &operator<<(ostream &os, const sick &o)
{
    os << o.name << " / "
       << o.symptoms << " / "
       << o.procedure << " / "
       << o.medics;
    return os;
}

void sick::read(ifstream &in)
{

}

bool sick::cmp(sick &b)
{
    short c = 0;
    if (this->name.size() > 1) ++c;
    if (this->symptoms.size() > 1) ++c;
    if (this->medics.size() > 1) ++c;
    if (this->procedure.size() > 1) ++c;

    if (this->name.size() > 1 && this->name == b.name) --c;
    if (this->symptoms.size() > 1 && (b.symptoms.find(symptoms) != string::npos)) --c;
    if (this->medics.size() > 1 && this->medics == b.medics) --c;
    if (this->procedure.size() > 1 && this->procedure == b.procedure) --c;

    return (c == 0);
}

sick::sick()
{
    name = symptoms = medics = procedure = "";
}

int sick::getNumber()
{
    return number;
}

bool sick::setNumber(int pole)
{
    if (pole < 1 || pole > 4)
        return false;
    sick::number = pole;
    return true;
}

bool sick::operator<(const sick &rhs) const
{
    if (number == 1) return name < rhs.name;
    if (number == 2) return symptoms < rhs.symptoms;
    if (number == 3) return procedure < rhs.procedure;
    return medics < rhs.medics;
}


bool sick::operator==(const sick &rhs) const
{
    return name == rhs.name &&
           symptoms == rhs.symptoms &&
           procedure == rhs.procedure &&
           medics == rhs.medics;
}

bool sick::operator!=(const sick &rhs) const
{
    return !(rhs == *this);
}

void sick::setName(const string &name)
{
    sick::name = name;
}

void sick::setSymptoms(const string &symptoms)
{
    sick::symptoms = symptoms;
}

void sick::setProcedure(const string &procedure)
{
    sick::procedure = procedure;
}

void sick::setMedics(const string &medics)
{
    sick::medics = medics;
}
