#ifndef BASEDATA_DATAIO_H
#define BASEDATA_DATAIO_H

#include <time.h>
#include <fstream>

class DataIO {
protected:
    std::ifstream fin;
    std::ofstream fout;
public:
    DataIO() = delete;

    DataIO(std::string in, std::string out);

    virtual bool write() = 0;

    virtual bool load() = 0;

};

DataIO::DataIO(std::string in, std::string out)
{

}


#endif //BASEDATA_DATAIO_H
