#ifndef DATABASE
#define DATABASE

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

namespace DB {
	template<class T>
	class DataBase {
	private:
		list <T> l;
		string in;
		string out;
	public:
		DataBase(string in, string out) : in(in), out(out) {};
		
		void print_one(const T &t) {
			T a = find(t);
			if (a) {
				cout << t << endl;
			} else {
				cout << "Not founded" << endl;
			}
		}
		
		T find(T &templ) {
			for (auto p : l) {
				if (templ.compare_my_class_na_easy_brat_function(p)) {
					return p;
				}
			}
			
			return nullptr;
		}
		
		void print_all() {
			for (auto p: l) {
				cout << p << endl;
			}
			
		}
		
		void sorting(T &temp) {
			sort(l.begin(), l.end(), temp.sort);
		}
		
		
		bool del_rec(T &temp) {
			T find = find(temp);
			if (find == nullptr) {
				cout << "This records have not founded" << endl;
				return false;
			} else {
				l.erase(find(l.begin(), l.end(), find));
			}
			return true;
		}
		
		
		void add_rec(T &n) {
			l.push_back(n);
		}
		
		void clean_your_ass() {
			l.clear();
		}
	};
}
#endif //BASEDATA_DATA_BASE_H
