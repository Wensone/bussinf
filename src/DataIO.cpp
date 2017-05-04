#include "../headers/DataIO.h"

IOResults::IOResults(string in, string out)
{
    valid_in = valid_out = false;
    fin.open(in);
    fout.open(out);

    if (fin.good()) {
        valid_in = true;
    }
    if (fout.good()) {
        valid_out = true;
    }
}

bool IOResults::valid_read()
{
    return valid_in;
}

bool IOResults::valid_write()
{
    return valid_out;
}

bool IOResults::rdreopen(string file)
{
    fin.close();
    fin.open(file);
    valid_in = fin.good();
    return valid_in;
}

bool IOResults::wrreopen(string file)
{
    fout.close();
    fout.open(file);
    valid_out = fout.good();
    return valid_out;
}

