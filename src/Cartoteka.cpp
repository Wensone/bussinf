#include "../headers/Cartoteka.h"

list <Cartoteka> Cartoteka::GenCard(){
	srand( (unsigned)time(NULL) );
	Cartoteka card;
	list<Cartoteka> lst;
	
	string author;
	string name;
	string publ;
	string year;
	string section;
	string avail;
	string val;
	
	ifstream afin("../Gencard/author");
	ifstream nfin("../Gencard/name");
	ifstream pfin("../Gencard/publ");
	ifstream yfin("../Gencard/year");
	ifstream sfin("../Gencard/section");
	ifstream avfin("../Gencard/avail");
	ifstream vfin("../Gencard/val");
	
	ofstream fout("gen_card");
	
	int aut;
	int nm;
	int pbl;
	int yer;
	int sct;
	int avl;
	int vl;
	
	afin >> aut;
	nfin >> nm;
	pfin >> pbl;
	yfin >> yer;
	sfin >> sct;
	avfin >> avl;
	vfin >> vl;
	
	string a[aut],
			b[nm],
			c[pbl],
			d[yer],
			f[sct],
			g[avl],
			e[vl];
	
	int i;
	i = 0;
	while(i < aut){
		if(afin.eof()) break;
		
		getline(afin, a[i]);
		
		i++;
	}
	
	i = 0;
	while(i < nm){
		if(nfin.eof()) break;
		
		getline(nfin, b[i]);
		i++;
	}
	
	i = 0;
	while(i < pbl){
		if(pfin.eof()) break;
		
		getline(pfin, c[i]);
		i++;
	}
	
	i = 0;
	while(i < yer){
		if(yfin.eof()) break;
		
		getline(yfin, d[i]);
		i++;
	}
	
	i = 0;
	while(i < sct){
		if(sfin.eof()) break;
		
		getline(sfin, f[i]);
		i++;
	}
	
	i = 0;
	while(i < avl){
		if(avfin.eof()) break;
		
		getline(avfin, g[i]);
		i++;
	}
	
	i = 0;
	while(i < vl){
		if(vfin.eof()) break;
		
		getline(vfin, e[i]);
		i++;
	}
	
	i = 0;
	while(i < 60){
		card.author = a[10 + rand() % 50];
		card.name = b[10 + rand() % 50];
		card.publishing = c[1 + rand() % 18];
		card.year = d[10 + rand() % 50];
		card.section = f[1 + rand() % 20];
		card.avail = g[10 + rand() % 50];
		card.valuation = e[10 + rand() % 50];
		
		lst.push_back(card);
		fout << card << endl;
		i++;
	}
	
	return lst;
}

bool Cartoteka::operator () (Cartoteka &a, Cartoteka &b) {
	// compare function
	
	return a.author < b.author;
}

ostream & operator << (ostream &os, const Cartoteka &o){
	os << o.author << "/"
	   << o.name << "/"
	   << o.publishing << "/"
	   << o.year << "/"
	   << o.section << "/"
	   << o.avail << "/"
	   << o.valuation;
	return os;
}

void Cartoteka::operator () (string filename) {

}