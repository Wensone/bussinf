#include "../headers/DataBase.h"
#include "../headers/Reader.h"

int main()
{
	DB::DataBase<Reader> lol("lol", "lol");
	lol.print_all();
}