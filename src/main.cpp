#include "../headers/DataBase.h"
#include "../headers/Reader.h"

int main()
{
	DB::DataBase<Reader> lol("../Genname/gen_data", "lol");
    lol.load();
	lol.print_all();
    lol.write();
    ifstream a("lol");
    Reader l("Емельянов Арсений Семёнович", "aa");
    lol.sorting(l);

}