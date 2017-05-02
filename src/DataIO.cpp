#include "../headers/DataIO.h"

IOResults::IOResults(string in, string out) {
	ifstream fin(in);
	ofstream fout(out);
	valid_in = valid_out = false;
	
	if (fin.good()) {
		valid_in = true;
		this->in = in;
	}
	if (fout.good()) {
		valid_out = true;
		this->out = out;
	}
	fin.close();
	fout.close();
}

bool IOResults::valid_read() {
	return valid_in;
}

bool IOResults::valid_write() {
	return valid_out;
}

bool IOResults::rdreopen(string file) {
	ifstream fin(file);
	valid_in = fin.good();
	fin.close();
	return valid_in;
}

bool IOResults::wrreopen(string file) {
	ofstream fout(file);
	valid_out = fout.good();
	fout.close();
	return valid_out;
}
