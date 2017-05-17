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
    sick sk;
    /*
        string name; //
        string symptoms; //
        string procedure; //
        string medics; //
    */
    ifstream nfin("../Gensick/name");
    ifstream sfin("../Gensick/symp");
    ifstream pfin("../Gensick/proc");
    ifstream mfin("../Gensick/med");
    ofstream fout("../Gensick/gen_sick");

    int name;
    int symp;
    int proc;
    int med;

    nfin >> name;
    sfin >> symp;
    pfin >> proc;
    mfin >> med;

    string a[name],
            b[symp],
            c[proc],
            d[med];
    int i;
    i = 0;
    while (i < name) {
        if (nfin.eof()) break;

        getline(nfin, a[i]);

        i++;
    }
    i = 0;
    while (i < symp) {
        if (sfin.eof()) break;

        getline(sfin, b[i]);
        i++;
    }
    i = 0;
    while (i < proc) {
        if (pfin.eof()) break;

        getline(pfin, c[i]);
        i++;
    }
    i = 0;
    while (i < med) {
        if (mfin.eof()) break;

        getline(mfin, d[i]);
        i++;
    }
    i = 0;
    while (i < 60) {
        sk.name = a[1+rand() % name];
		sk.symptoms = b[1+rand() % symp];
		sk.procedure = c[1+rand() % proc];
		sk.medics = d[1+rand() % med];
		
        lst.push_back(sk);
        fout << sk << endl;
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

const string &sick::getMedics() const
{
    return medics;
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
