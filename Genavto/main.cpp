#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <list>

using namespace std;

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

struct Auto {
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
};

int main()
{
    srand((unsigned)time(0));
    list<Auto> lst;
    Auto autist;

    ifstream mfin("mark");
    ifstream dfin("defects");
    ifstream efin("engine");
    ifstream tfin("type");
    ifstream afin("auc");

    //ФИО, адрес, e-mail, список взятых книг
    //времени взятия книги
    //срока пользования книгой
    //предпочитаемые жанры.

    ofstream fout("gen_data");

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
        autist.mark[i] = a[1 + rand() % (mark - 1)];
        autist.outMark[i] = i2s(1 + rand() % outMark - 1);
        autist.inMark = i2s(1 + rand() % inMark - 1);
        autist.defects = b[1 + rand() % (defects - 1)];
        autist.engine = c[1 + rand() % (engine - 1)];
        autist.power = i2s(1 + rand() % power - 1);
        autist.year = i2s(1 + rand() % year - 1);
        autist.type = d[1 + rand() % (type - 1)];
        autist.name_auc = f[1 + rand() % (name_auc - 1)];
        autist.date = i2s(1 + rand() % date - 1);
        autist.first_price = i2s(1 + rand() % first_price - 1);
        autist.end_price = i2s(1 + rand() % end_price - 1);
        autist.last_sold = i2s(1 + rand() % last_sold - 1);
        
        lst.push_back(autist);

        i++;
    }
}