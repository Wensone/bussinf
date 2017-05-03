#include "../headers/DataBase.h"
#include "../headers/Reader.h"

int main()
{

	DB::DataBase<Reader> lol("../Genname/gen_data", "lol");
    lol.load();
	//lol.print_all();
    lol.write();
    ifstream a("lol");
    lol.sorting();
    Reader find;
    find.setFio("Брагин Виктор Пётрович");
    Reader kek = lol.find(find);
    cout << kek << endl;
//    lol.print_all();
}