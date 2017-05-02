#ifndef BASEDATA_DATAIO_H
#define BASEDATA_DATAIO_H

#include <time.h>
#include <fstream>

class DataIO {
protected:
	std::string fin;
	std::string fout;
	bool in, out;
public:
	DataIO(std::string in, std::string out);
	
	bool change_in(std::string new_in);
	
	bool change_out(std::string new_out);
	
	bool fin_open();
	
	bool fout_open();
	
	virtual bool write() = 0;
	
	virtual bool load() = 0;
	
};

DataIO::DataIO(std::string sin, std::string sout) {
	this->in = this->out = false;
	std::ifstream sfin(sin);
	std::ofstream sfout(sout);
	if (sfin.good()) {
		in = true;
		fin = sin;
	}
	if (sfout.good()) {
		out = true;
		fout = sout;
	}
	sfin.close();
	sfout.close();
}

bool DataIO::change_in(std::string new_in) {
	std::ofstream sfin(new_in);
	bool t = false;
	if (sfin.good()) {
		in = true;
		fin = new_in;
		t = true;
	}
	sfin.close();
	return t;
}

bool DataIO::change_out(std::string new_out) {
	std::ofstream sfout(new_out);
	bool t = false;
	if (sfout.good()) {
		out = true;
		fout = new_out;
		t = !t;
	}
	sfout.close();
	return t;
}

bool DataIO::fin_open() {
	return in;
}

bool DataIO::fout_open() {
	return out;
}


#endif //BASEDATA_DATAIO_H
