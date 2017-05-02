#ifndef DATABASE
#define DATABASE

#include <list>
#include <iostream>
#include <algorithm>
#include "DataIO.h"

using namespace std;

namespace DB  {
    template<class T>
    class DataBase : public IOResults {
    private:
        list <T> l;

    public:
        DataBase(string in, string out) : IOResults(in, out) {};


        void write() {
            if (!valid_write()) return;

            for (auto p : l) {
                fout << p << endl;
            }

        }

        void read() {
           if (!valid_read()) return;
            T t;
            t.read(fin);
        }

        void print_one(const T &t)
        {
            T a = find(t);
            if (a) {
                cout << t << endl;
            } else {
                cout << "Not founded" << endl;
            }
        }

        T find(T &templ)
        {
            T t;
            for (auto p : l) {
                if (templ.compare_my_class_na_easy_brat_function(p)) {
                    return p;
                }
            }

            return t;
        }

        void print_all()
        {
            for (auto p: l) {
                cout << p << endl;
            }

        }

        void sorting(T &temp)
        {
            sort(l.begin(), l.end(), temp.sort);
        }


        bool del_rec(T &temp)
        {
            T find = find(temp);
            if (find == nullptr) {
                cout << "This records have not founded" << endl;
                return false;
            } else {
                l.erase(find(l.begin(), l.end(), find));
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
        }

        void load()
        {
            while (!fin.eof()) {
                T t;
                t.read(fin);
                l.push_back(t);
            }

        }
    };
}
#endif //BASEDATA_DATA_BASE_H
