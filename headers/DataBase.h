#ifndef DATABASE
#define DATABASE

#include <list>
#include <iostream>
#include <algorithm>
#include "DataIO.h"
#include "Shopper.h"

using namespace std;

namespace DB {
    template<class T>
    class DataBase : public IOResults {
    private:
        list <T> l;
    public:
        DataBase(string in, string out) : IOResults(in, out)
        {
        };

        void generate()
        {
            T t;
            t.Generate(l);
        }

        void write()
        {
            if (!valid_write()) return;

            for (auto p : l) {
                fout << p << endl;
            }

        }

        void write_one(T &t)
        {
            if (!valid_write()) return;;
            fout << t << endl;
        }

        void read()
        {
            if (!valid_read()) return;
            T t;
            t.read(fin);
        }

        bool print_one(const T &t)
        {
            return this->find(t);
        }

        bool find(T &templ)
        {
            for (auto p : l) {
                if (templ.cmp(p)) {
                    templ = p;
                    return true;
                }
            }

            return false;
        }

        void printC(T &t)
        {
            for (auto p : l) {
                if (t.cmp(p)) {
                    cout << p;
                }
            }
        }

        void print_all()
        {
            for (auto p: l) {
                cout << p << endl;
            }

        }

        void sorting()
        {
            l.sort();
        }

        int switchCase(int n)
        {
            T::setNumber(n);
            return 0;
        }

        bool del_rec(T &temp)
        {
            bool c = find(temp);
            if (!c) {
                return false;
            } else {
                l.erase(std::find(l.begin(), l.end(), temp));
            }
            return true;
        }


        void add_rec(T &n)
        {
            l.push_back(n);
        }

        void clean_your_ass()
        {
            l.clear();
            fout.close();
            fout.open(outputFile, ios_base::trunc | ios_base::out);
        }

        void load()
        {
            while (!fin.eof()) {
                T t;
                t.read(fin);
                l.push_back(t);
            }

        }

        void del_oneC(T &t)
        {
            while (del_rec(t)) {}
        }
    };
}
#endif //BASEDATA_DATA_BASE_H
