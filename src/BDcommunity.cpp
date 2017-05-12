#include "../headers/BDcommunity.h"

void BDcommunity::print_Auto()
{
    cout << "1. mark" << endl
         << "2. outMark " << endl
         << "3. inMark" << endl
         << "4. defects" << endl
         << "5. engine" << endl
         << "6. power" << endl
         << "7. year" << endl
         << "8. type" << endl
         << "9. name_auc" << endl
         << "10. date" << endl
         << "11. first_price" << endl
         << "12. end_price" << endl
         << "13. last_sold" << endl;
}

void BDcommunity::print_Shopper()
{

    cout << "1. passport" << endl
         << "2. balance " << endl
         << "3. list_of_car" << endl
         << "4. time_buy" << endl
         << "5. car" << endl
         << "6. prices" << endl
         << "7. data_of_buy" << endl
         << "8. discount" << endl;
}

Shopper BDcommunity::in_Shopper()
{
    string new_pole;
    Shopper shop;
    {

        cout << "Passport : ";
        cin.ignore();
        getline(cin, new_pole);
        shop.setPassport(new_pole);
        cout << "Balance : ";

        getline(cin, new_pole);
        shop.setBalance(new_pole);
        cout << "List of cars : ";
        getline(cin, new_pole);
        shop.setCar(new_pole);
        cout << "Time buy : ";

        getline(cin, new_pole);
        shop.setTime_buy(new_pole);
        cout << "Cars : ";

        getline(cin, new_pole);
        shop.setCar(new_pole);
        cout << "Prices : ";
        getline(cin, new_pole);
        shop.setPrices(new_pole);
        cout << "Date of buy : ";
        getline(cin, new_pole);
        shop.setData_of_buy(new_pole);

        cout << "Discount : ";
        getline(cin, new_pole);
        shop.setDiscount(new_pole);
        cin.clear();
        //s->add_rec(shop);
    }
    return shop;
}

Auto BDcommunity::in_Auto()
{
    string new_pole;
    Auto _auto;
    {

        cout << "mark : ";
        cin.ignore();
        getline(cin, new_pole);
        _auto.setMark(new_pole);
        cout << "outMark : ";
        getline(cin, new_pole);
        _auto.setOutMark(new_pole);
        cout << "inMark : ";
        getline(cin, new_pole);
        _auto.setInMark(new_pole);
        cout << "defects : ";
        getline(cin, new_pole);
        _auto.setDefects(new_pole);
        cout << "engine : ";
        getline(cin, new_pole);
        _auto.setEngine(new_pole);
        cout << "power : ";
        getline(cin, new_pole);
        _auto.setPower(new_pole);
        cout << "Year : ";
        getline(cin, new_pole);
        _auto.setYear(new_pole);
        cout << "type : ";
        getline(cin, new_pole);
        _auto.setType(new_pole);
        cout << "name_auc : ";
        getline(cin, new_pole);
        _auto.setName_auc(new_pole);
        cout << "date : ";
        getline(cin, new_pole);
        _auto.setDate(new_pole);
        cout << "first_price : ";
        getline(cin, new_pole);
        _auto.setFirst_price(new_pole);
        cout << "end_price : ";
        getline(cin, new_pole);
        _auto.setEnd_price(new_pole);
        cout << "last sold : ";
        getline(cin, new_pole);
        _auto.setLast_sold(new_pole);
        cin.clear();
        //a->add_rec(_auto);
    }
    return _auto;
}

int BDcommunity::getBaseNow()
{
    return base;
}

void BDcommunity::change_base()
{
    this->base = (base == 1) ? 2 : 1;
}

void BDcommunity::menu()
{
    cout << "\t\t Menu \t\t\n";

    do {
        cout << "Now base is " << ((base == 1) ? "Shopper" : "Auto") << endl;
        bool in, out;
        this->checkIO(in, out);
        cout << "Input : " << ((in) ? "YES " : " NO ") << "| Output : " << ((out) ? "YES" : "NO") << endl;
        cout << "1. Switch base" << endl
             << "2. Generate" << endl
             << "3. Print all base" << endl
             << "4. load" << endl
             << "5. Write" << endl
             << "6. Delete base" << endl
             << "7. Switch input file" << endl
             << "8. Switch output file" << endl
             << "9. Sort" << endl
             << "10 Add record in base" << endl
             << "11. Delete record" << endl
             << "12. Clear screen" << endl
             << "13. Delete all records by template" << endl
             << "14. Print all records by template" << endl
             << "15. Report" << endl;

        int key;
        cout << "Enter menu point: ";
        cin >> key;
        switch (key) {
            case 1: {
                this->change_base();
                break;
            }
            case 2: {
                this->create();
                break;
            }
            case 3: {
                this->printBase();
                break;
            }
            case 4: {
                if (this->load()) {
                    cout << "Cannot write";
                }
                break;
            }
            case 5: {
                if (this->write()) {
                    cout << "Cannot write" << endl;
                }
                break;
            }
            case 6: {
                this->del_base();
                break;
            }
            case 7: {
                cout << "Enter new path" << endl;
                string file;
                cin >> file;
                this->switch_input(file);
                break;
            }
            case 8 : {
                cout << "Enter new path" << endl;
                string file;
                cin >> file;
                this->switch_output(file);
                break;
            }
            case 9 : {
                system("clear");
                cout << "What is the number:";
                if (base == 1) {
                    print_Shopper();
                } else {
                    print_Auto();
                }
                int n;
                do {
                    cin >> n;
                } while (n < 1 || n > 7);
                this->sort(n);
                break;
            }
            case 10 : {
                if (base == 1) {
                    this->add_new_record(in_Shopper());
                } else {
                    this->add_new_record(in_Auto());
                }
                break;
            }
            case 11 : {
                if (base == 1) {
                    Shopper rd = in_Shopper();
                    if (this->del_record(rd)) {
                        cout << "Deleted success" << endl;
                    }
                } else {
                    Auto cd = in_Auto();
                    if (this->del_record(cd)) {
                        cout << "Deleted success" << endl;
                    }
                }
                this->write();
                break;
            }
            case 12 : {
                this->clear_screen();
                break;
            }
            case 13 : {
                if (base == 1) {
                    Shopper rd = in_Shopper();
                    this->del_copyOne(rd);
                } else {
                    Auto cd = in_Auto();
                    this->del_copyOne(cd);
                }
                break;
            }
            case 14 : {
                if (base == 1) {
                    Shopper t = in_Shopper();
                    this->print_onec(t);
                } else {
                    Auto t = in_Auto();
                    this->print_onec(t);
                }
                break;
            }
            default:
                return;
        }
    } while (true);
}

BDcommunity::BDcommunity()
{
    s = new DB::DataBase<Shopper>("", "");
    a = new DB::DataBase<Auto>("", "");
    base = 1;
}

void BDcommunity::checkIO(bool &in, bool &out)
{
    if (base == 1) {
        out = s->valid_write();
        in = s->valid_read();
    } else {
        in = a->valid_read();
        out = a->valid_write();
    }
}

bool BDcommunity::find(Auto s)
{
    return a->find(s);
}

void BDcommunity::create()
{
    if (base == r) {
        s->generate();
    } else {
        a->generate();
    }
}

void BDcommunity::add_new_record(Auto rec)
{
    a->add_rec(rec);
    a->write_one(rec);
}

void BDcommunity::printBase()
{
    if (base == r) {
        s->print_all();
    } else {
        a->print_all();
    }
}

bool BDcommunity::find(Shopper s)
{
    return this->s->find(s);
}

void BDcommunity::del_copy(Auto &T)
{
    a->del_oneC(T);
}

void BDcommunity::switch_input(string newfilename)
{
    if (base == 1) {
        s->rdreopen(newfilename);
    } else {
        a->rdreopen(newfilename);
    }
}

void BDcommunity::switch_output(string newfilename)
{
    if (base == 1) {
        s->wrreopen(newfilename);
    } else {
        a->wrreopen(newfilename);
    }
}

void BDcommunity::del_copy(Shopper &T)
{
    s->del_oneC(T);
}

void BDcommunity::add_new_record(Shopper rec)
{
    s->add_rec(rec);
    s->write_one(rec);

}

BDcommunity::~BDcommunity()
{
    delete a;
    delete s;
}

void BDcommunity::sort(int n)
{
    if (base == 1) {
        s->switchCase(n);
        s->sorting();
    } else {
        s->switchCase(n);
        a->sorting();
    }
}

void BDcommunity::print_onec(Shopper &t)
{
    s->printC(t);
}

void BDcommunity::del_base()
{
    if (base == 1) {
        s->clean_your_ass();

    } else {
        a->clean_your_ass();
    }
}

void BDcommunity::print_onec(Auto &t)
{
    a->printC(t);
}

bool BDcommunity::del_record(Shopper &t)
{
    return s->del_rec(t);
}

int BDcommunity::write()
{
    if (base == 1) {
        if (!s->valid_write()) return EXIT_FAILURE;
        s->write();
    } else {
        if (!a->valid_write()) return EXIT_FAILURE;
        a->write();
    }
    return EXIT_SUCCESS;
}

int BDcommunity::load()
{
    if (base == 1) {
        if (!s->valid_read())
            return EXIT_FAILURE;
        s->load();
    } else {
        if (!a->valid_read())
            return EXIT_FAILURE;
        a->load();
    }
    return EXIT_SUCCESS;
}

bool BDcommunity::del_record(Auto &t)
{
    return a->del_rec(t);
}


void BDcommunity::clear_screen()
{
    system(clr);
}

void BDcommunity::console(int argc, char **argv)
{
    opterr = 0;
    int choose = 0;
	ifstream f;
    while ((choose = getopt(argc, argv, "f:hb:i:o:c:a:d:p:s:lw"))) {
        switch (choose) {
            case 'f' : {
                readInstruction(optarg);
                return;
            }
            case 'l' : {
                load();
                break;
            }
            case 'w' : {
                write();
                break;
            }
            case 'a' : {
                if (base == 1) {
                    Shopper t;
					
					t = parse_Shopper(optarg);
					add_new_record(t);

                } else {
                    Auto t;
                    t = parse_Auto(optarg);
                    add_new_record(t);
                }

                break;
            }
            case 'd' : {
                if (base == 1) {
                    Shopper t;
					t = parse_Shopper(optarg);
                    del_copy(t);
                } else {
                    Auto t;
					t = parse_Auto(optarg);
                    del_copy(t);
                }
                break;
            }
            case 'p' : {
                if (base == 1) {
                    Shopper t;
					t = parse_Shopper(optarg);
                    print_onec(t);
                } else {
                    Auto t;
					t = parse_Auto(optarg);
                    print_onec(t);
                }
                break;
            }
            case 's' : {
                sort(atoi(optarg));
                break;
            }
            case 'b' : {
                int b = atoi(optarg);
                if (base != b) change_base();
                break;
            }
            case 'i' : {
                switch_input(optarg);
                break;
            }
            case 'o' : {
                switch_output(optarg);
                break;
            }
            case 'c' : {
                switch (atoi(optarg)) {
                    case 1 : {
                        this->create();
                        break;
                    }
                    case 2 : {
                        this->printBase();
                        break;
                    }
                    case 3 : {
                        del_base();
                        break;
                    }
                    case 4 : {
                        //report
                        break;
                    }
                    default: {
                        cout << "Incorrect (" << optarg << ")"  << endl;
                    }
                }

                break;
            }
            case 'h' : {
                // f:hb:i:o:c:a:d:p:s:lw
                cout << "Template Shopper : FIO /..." << endl;
                cout << "Template Auto : FIO /..." << endl;
                cout << "-f filename for read by file" << endl;
                cout << "-b 1/2 choose base(Shopper/Auto)" << endl;
                cout << "-i file/t -o file - choose input and output files"  << endl;
                cout << "-a templates - add new record" << endl;
                cout << "-p templates - print all records by templates" << endl;
                cout << "-s number_of_sort(1-7)" << endl;
                cout << "-l - load" << endl;
                cout << "-w - write" << endl;
                cout << "Parametrs c :" << endl;
                cout << "1. Generate" << endl
                     << "2. Print all base" << endl
                     << "3. Delete base" << endl
                     << "4. Report" << endl;
            }
            default:
                return;
        }
    }
}

void BDcommunity::del_copyOne(Shopper &T)
{
    s->del_oneC(T);
}

void BDcommunity::del_copyOne(Auto &T)
{
    a->del_oneC(T);
}

void BDcommunity::readInstruction(char *file)
{
    ifstream instructioin(file);

    string command;

    while (!instructioin.eof()) {
        instructioin >> command;

        if (command == "base") {
            int n;
            instructioin >> n;
            if (base != n) change_base();
        } else if (command == "input") {
            string fname;
            instructioin >> fname;
            switch_input(fname);
        } else if (command == "output") {
            string fname;
            instructioin >> fname;
            switch_output(fname);
        } else if (command == "addRecord") {
            if (base == 1) {
                Shopper t;
				t = parse_Shopper(instructioin);
                add_new_record(t);
            } else {
                Auto t;
				t = parse_Auto(instructioin);
                add_new_record(t);
            }
        } else if (command == "deleteRecord") {
            if (base == 1) {
                Shopper t;
				t = parse_Shopper(instructioin);
                del_copy(t);
            } else {
                Auto t;
				t = parse_Auto(instructioin);
                del_copy(t);
            }
        } else if (command == "delBase") {
            del_base();
        } else if (command == "load") {
            load();
        } else if (command == "write") {
            write();
        } else if (command == "sort") {
            int n;
            instructioin >> n;
            sort(n);
        } else if (command == "PrintBase") {
            printBase();
        } else if (command == "Print") {
            if (base == 1) {
                Shopper t;
				t = parse_Shopper(instructioin);
                print_onec(t);
            } else {
                Auto t;
				t = parse_Auto(instructioin);
                print_onec(t);
            }
        } else if (command == "report") {

        }
    }
    instructioin.close();
	
}

Shopper BDcommunity::parse_Shopper(ifstream &os) {
    /*
	Shopper rd;

	string fio;
	string address;
	string email;
	string book_list; // список взятых книг
	string time_take; // время взятия
	string time_using; // срок пользования
	string book_genre;
	
	getline(os, fio, '/');
	getline(os, address, '/');
	getline(os, email, '/');
	getline(os, book_list, '/');
	getline(os, time_take, '/');
	getline(os, time_using, '/');
	getline(os, book_genre, '\n');
	
	rd.setFio(fio);
	rd.setAddress(address);
	rd.setEmail(email);
	rd.setBook_list(book_list);
	rd.setTime_take(time_take);
	rd.setTime_using(time_using);
	rd.setBook_genre(book_genre);
	
	return rd;
     */
}

Auto BDcommunity::parse_Auto(ifstream &os) {
    /*
	Auto a;
	
	string author; // автор
	string name; // название
	string publishing; // издательство
	string year; // год издания
	string section; // радел(спец. литература, хобби, хуеби)
	string avail; // наличие
	string valuation; // оценка
	
	getline(os, author, '/');
	getline(os, name, '/');
	getline(os, publishing, '/');
	getline(os, year, '/');
	getline(os, section, '/');
	getline(os, avail, '/');
	getline(os, valuation, '\n');
	
	a.setAuthor(author);
	a.setName(name);
	a.setPublishing(publishing);
	a.setYear(year);
	a.setSection(section);
	a.setAvail(avail);
	a.setValuation(valuation);
	
	return a;
     */
}

Shopper BDcommunity::parse_Shopper(string s) {
    /*
	Shopper rd;
	
	string fio;
	string address;
	string email;
	string book_list; // список взятых книг
	string time_take; // время взятия
	string time_using; // срок пользования
	string book_genre;
	
	int i = 0;
	while(s[i] != '/'){
		fio += s[i];
	}
	i++;
	while(s[i] != '/'){
		address += s[i];
	}
	i++;
	while(s[i] != '/'){
		email += s[i];
	}
	i++;
	while(s[i] != '/'){
		book_list += s[i];
	}
	i++;
	while(s[i] != '/'){
		time_take += s[i];
	}
	i++;
	while(s[i] != '/'){
		time_using += s[i];
	}
	i++;
	while(s[i] != '\0'){
		book_genre += s[i];
	}
	
	rd.setFio(fio);
	rd.setAddress(address);
	rd.setEmail(email);
	rd.setBook_list(book_list);
	rd.setTime_take(time_take);
	rd.setTime_using(time_using);
	rd.setBook_genre(book_genre);
	
	return rd;
     */
}

Auto BDcommunity::parse_Auto(string s) {/*
	Auto a;
	
	string author; // автор
	string name; // название
	string publishing; // издательство
	string year; // год издания
	string section; // радел(спец. литература, хобби, хуеби)
	string avail; // наличие
	string valuation; // оценка
	
	int i = 0;
	while(s[i] != '/'){
		author += s[i];
	}
	i++;
	while(s[i] != '/'){
		name += s[i];
	}
	i++;
	while(s[i] != '/'){
		publishing += s[i];
	}
	i++;
	while(s[i] != '/'){
		year += s[i];
	}
	i++;
	while(s[i] != '/'){
		section += s[i];
	}
	i++;
	while(s[i] != '/'){
		avail += s[i];
	}
	i++;
	while(s[i] != '\0'){
		valuation += s[i];
	}
	
	a.setAuthor(author);
	a.setName(name);
	a.setPublishing(publishing);
	a.setYear(year);
	a.setSection(section);
	a.setAvail(avail);
	a.setValuation(valuation);
	
	return a;*/
}

void BDcommunity::report()
{

}
