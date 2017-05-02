#ifndef DATA
#define DATA

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class IOResults {
protected:
	string in;
	string out;
	bool valid_in;
	bool valid_out;

public:
	IOResults() {};
	
	IOResults(string in, string out);
	
	bool valid_read();
	
	bool valid_write();
	
	bool rdreopen(string file);
	
	bool wrreopen(string file);
	
	virtual void write() = 0;
	
	virtual void read() = 0;
};


#endif //BASEDATA_DATAIO_H
