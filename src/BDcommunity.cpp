#include <map>
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
            case 15 : {
                this->report();
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
                        this->report();
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
            report();
        }
    }
    instructioin.close();
	
}

Shopper BDcommunity::parse_Shopper(ifstream &os) {
	Shopper shp;
    
    string passport; // серия и номер паспорта				// int
    string balance; // баланс покупателя					// int
    string list_of_car; // список автомобилей				// str
    string time_buy; // время покупки						// str
    string car; // покупаемая машина						// str
    string prices;	// цена									// int
    string data_of_buy; // дата покупки						// int
    string discount; // скидон								// int
	
	getline(os, passport, '/');
	getline(os, balance, '/');
	getline(os, list_of_car, '/');
	getline(os, time_buy, '/');
	getline(os, car, '/');
	getline(os, prices, '/');
	getline(os, data_of_buy, '/');
	getline(os, discount, '\n');
	
	shp.setPassport(passport);
	shp.setBalance(balance);
	shp.setList_of_car(list_of_car);
	shp.setTime_buy(time_buy);
	shp.setCar(car);
	shp.setPrices(prices);
	shp.setData_of_buy(data_of_buy);
	shp.setDiscount(discount);
	
	return shp;
}

Auto BDcommunity::parse_Auto(ifstream &os) {
	Auto ato;
	
	string mark; // марка авто						стр
	string outMark; // оценка внешнего вида			инт
	string inMark; // оценка внутреннего вида		инт
	string defects; // дефекты						стр
	string engine; // двигатель						стр
	string power; // мощьность						инт
	string year; // год								инт
	string type; // Тип								стр
	string name_auc; // Название аукциона продажи	стр
	string date; // дата продажи					инт
	string first_price; // начальная цена			инт
	string end_price; // цена продажи				инт
	string last_sold; // Проследняя продажа			инт
	
	getline(os, mark, '/');
	getline(os, outMark, '/');
	getline(os, inMark, '/');
	getline(os, defects, '/');
	getline(os, engine, '/');
	getline(os, power, '/');
	getline(os, year, '/');
	getline(os, type, '/');
	getline(os, name_auc, '/');
	getline(os, date, '/');
	getline(os, first_price, '/');
	getline(os, end_price, '/');
	getline(os, last_sold, '\n');
	
	ato.setMark(mark);
	ato.setOutMark(outMark);
	ato.setInMark(inMark);
	ato.setDefects(defects);
	ato.setEngine(engine);
	ato.setPower(power);
	ato.setYear(year);
	ato.setType(type);
	ato.setName_auc(name_auc);
	ato.setDate(date);
	ato.setFirst_price(first_price);
	ato.setEnd_price(end_price);
	ato.setLast_sold(last_sold);
	
	return ato;
}

Shopper BDcommunity::parse_Shopper(string s) {
    Shopper shp;
    
    string passport; // серия и номер паспорта				// int
    string balance; // баланс покупателя					// int
    string list_of_car; // список автомобилей				// str
    string time_buy; // время покупки						// str
    string car; // покупаемая машина						// str
    string prices;	// цена									// int
    string data_of_buy; // дата покупки						// int
    string discount; // скидон								// int
    
	int i = 0;
	while(s[i] != '/'){
        passport += s[i];
	}
	i++;
	while(s[i] != '/'){
        balance += s[i];
	}
	i++;
	while(s[i] != '/'){
        list_of_car += s[i];
	}
	i++;
	while(s[i] != '/'){
        time_buy += s[i];
	}
	i++;
	while(s[i] != '/'){
        car += s[i];
	}
	i++;
	while(s[i] != '/'){
        prices += s[i];
	}
	i++;
	while(s[i] != '/'){
        data_of_buy += s[i];
	}
    i++;
    while(s[i] != '\0'){
        discount += s[i];
    }
    
    shp.setPassport(passport);
    shp.setBalance(balance);
    shp.setList_of_car(list_of_car);
    shp.setTime_buy(time_buy);
    shp.setCar(car);
    shp.setPrices(prices);
    shp.setData_of_buy(data_of_buy);
    shp.setDiscount(discount);
	
	return shp;
}

Auto BDcommunity::parse_Auto(string s) {
    Auto ato;
    
    string mark; // марка авто						стр
    string outMark; // оценка внешнего вида			инт
    string inMark; // оценка внутреннего вида		инт
    string defects; // дефекты						стр
    string engine; // двигатель						стр
    string power; // мощьность						инт
    string year; // год								инт
    string type; // Тип								стр
    string name_auc; // Название аукциона продажи	стр
    string date; // дата продажи					инт
    string first_price; // начальная цена			инт
    string end_price; // цена продажи				инт
    string last_sold; // Проследняя продажа			инт
	
	int i = 0;
	while(s[i] != '/'){
        mark += s[i];
	}
	i++;
	while(s[i] != '/'){
        outMark += s[i];
	}
	i++;
	while(s[i] != '/'){
        inMark += s[i];
	}
	i++;
	while(s[i] != '/'){
        defects += s[i];
	}
	i++;
	while(s[i] != '/'){
        engine += s[i];
	}
    i++;
    while(s[i] != '/'){
        power += s[i];
    }
    i++;
    while(s[i] != '/'){
        year += s[i];
    }
    i++;
    while(s[i] != '/'){
        type += s[i];
    }
    i++;
    while(s[i] != '/'){
        name_auc += s[i];
    }
    i++;
    while(s[i] != '/'){
        date += s[i];
    }
    i++;
    while(s[i] != '/'){
        first_price += s[i];
    }
    i++;
    while(s[i] != '/'){
        end_price += s[i];
    }
    i++;
    while(s[i] != '\0'){
        last_sold += s[i];
    }
    
    ato.setMark(mark);
    ato.setOutMark(outMark);
    ato.setInMark(inMark);
    ato.setDefects(defects);
    ato.setEngine(engine);
    ato.setPower(power);
    ato.setYear(year);
    ato.setType(type);
    ato.setName_auc(name_auc);
    ato.setDate(date);
    ato.setFirst_price(first_price);
    ato.setEnd_price(end_price);
    ato.setLast_sold(last_sold);
    
    return ato;
}

void BDcommunity::report()
{
    int aprice = 0;
    int adiscount = 0;
    int abalance = 0;
    map<string, int> car_count;
    for (auto p = a->begin(); p != a->end(); ++p) {
        aprice += atoi(p->getEnd_price().c_str());
        car_count[p->getMark()] += 1;
    }
    for (auto p = s->begin(); p != s->end(); ++p) {
        adiscount += atoi(p->getDiscount().c_str());
        abalance += atoi(p->getBalance().c_str());
    }

    cout << "Average price : " << aprice / a->getSize() << endl;
    cout << "Average discount : " << adiscount / s->getSize() << endl;
    cout << "Average balance : " << abalance / s->getSize() << endl;
    for (auto p = car_count.begin(); p != car_count.end(); ++p) {
        cout << p->first << ' ' << p->second << endl;
    }
}
