#ifndef DATABASE
#define DATABASE

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class Data_Base {
private:
	list <T> l;
public:
	void print_one(T t);
	
	T find(T &templ);
	
	void print_all();
	
	void sorting(T temp);
	
	bool del_rec(T temp);
	
	void add_rec(T n);
	
	void clean_your_ass();
};

template<class T>
void Data_Base::print_one(T t) {
	T a = find(t);
	if (a) {
		cout << t << endl;
	} else {
		cout << "Not founded" << endl;
	}
}

template<class T>
T Data_Base::find(T &templ) {
	for (auto p : l) {
		if (templ.compare_my_class_na_easy_brat_function(p)) {
			return p;
		}
	}
	
	return nullptr;
}

void Data_Base::print_all() {
	for (auto p: l) {
		cout << p << endl;
	}
	
}

template <class T>
void Data_Base::sorting(T temp) {
	sort(l.begin(), l.end(), temp.sort);
}

template <class T>
bool Data_Base::del_rec(T temp) {
	T find = find(temp);
	if (find == nullptr) {
		cout << "This records have not founded" << endl;
		return false;
	} else {
		l.erase(find(l.begin(), l.end(), find));
	}
	return true;
}

template <class T>
void Data_Base::add_rec(T n) {
	l.push_back(n);
}

void Data_Base::clean_your_ass() {
	l.clear();
}

#endif //BASEDATA_DATA_BASE_H
