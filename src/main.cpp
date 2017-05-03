#include "../headers/DataBase.h"
#include "../headers/Reader.h"
#include "../headers/BDcommunity.h"
#include "../headers/Cartoteka.h"

int main()
{
    Cartoteka card;
    Reader read;
/*
	DB::DataBase<Reader> lol("../Genname/gen_data", "lol");
    lol.load();
	// lol.print_all();
    lol.write();
    ifstream a("lol");
    lol.sorting();
    Reader find;
    find.setFio("Брагин Виктор Пётрович");
    Reader kek = lol.find(find);
    cout << kek << endl;
    // lol.print_all();
    */
    
//    BDcommunity<Cartoteka, Reader> bdc(card, read);
    DB::DataBase<Cartoteka> lol("../Gencard/gen_data", "../Gencard/gen_card");
    lol.generate();
    lol.sorting();
    lol.print_all();

    
}