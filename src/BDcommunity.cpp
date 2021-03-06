#include <map>
#include "../headers/BDcommunity.h"

void BDcommunity::print_Cartoteka()
{
    cout << "1. Author" << endl
         << "2. Name " << endl
         << "3. publishing" << endl
         << "4. Year" << endl
         << "5. Section" << endl
         << "6. Avail" << endl
         << "7. Valuation" << endl;
}

void BDcommunity::print_Reader()
{
    cout << "1. FIO" << endl
         << "2. Address " << endl
         << "3. E-mail" << endl
         << "4. Book list" << endl
         << "5. Time take" << endl
         << "6. Time using" << endl
         << "7. Book genre" << endl;
}

Reader BDcommunity::enter_Reader()
{
    string new_pole;
    Reader NewReader;
    {

        cout << "FIO : ";
        cin.ignore();
        getline(cin, new_pole);
        NewReader.setFio(new_pole);
        cout << "Address : ";

        getline(cin, new_pole);
        NewReader.setAddress(new_pole);
        cout << "Email : ";
        getline(cin, new_pole);
        NewReader.setEmail(new_pole);
        cout << "Book list : ";

        getline(cin, new_pole);
        NewReader.setBook_list(new_pole);
        cout << "Book genre : ";

        getline(cin, new_pole);
        NewReader.setBook_genre(new_pole);
        cout << "Time taking : ";
        getline(cin, new_pole);
        NewReader.setTime_take(new_pole);
        cout << "Time using : ";
        getline(cin, new_pole);
        NewReader.setTime_using(new_pole);
        cin.clear();
        //reader->add_rec(NewReader);
    }
    return NewReader;
}

Cartoteka BDcommunity::enter_Cartoteka()
{
    string new_pole;
    Cartoteka NewRecord;
    {

        cout << "Author : ";
        cin.ignore();
        getline(cin, new_pole);
        NewRecord.setAuthor(new_pole);
        cout << "Name : ";
        getline(cin, new_pole);
        NewRecord.setName(new_pole);
        cout << "Avail : ";
        getline(cin, new_pole);
        NewRecord.setAvail(new_pole);
        cout << "Publishing : ";
        getline(cin, new_pole);
        NewRecord.setPublishing(new_pole);
        cout << "Setciton : ";
        getline(cin, new_pole);
        NewRecord.setSection(new_pole);
        cout << "Valution : ";
        getline(cin, new_pole);
        NewRecord.setValuation(new_pole);
        cout << "Year : ";
        getline(cin, new_pole);
        NewRecord.setYear(new_pole);
        cin.clear();
        //card->add_rec(NewRecord);
    }
    return NewRecord;
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
        cout << "Now base is " << ((base == 1) ? "Reader" : "Cartoteka") << endl;
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
                cout << "What is the pole:";
                if (base == 1) {
                    print_Reader();
                } else {
                    print_Cartoteka();
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
                    this->add_new_record(enter_Reader());
                } else {
                    this->add_new_record(enter_Cartoteka());
                }
                break;
            }
            case 11 : {
                if (base == 1) {
                    Reader rd = enter_Reader();
                    if (this->del_record(rd)) {
                        cout << "Deleted success" << endl;
                    }
                } else {
                    Cartoteka cd = enter_Cartoteka();
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
                    Reader rd = enter_Reader();
                    this->del_copyOne(rd);
                } else {
                    Cartoteka cd = enter_Cartoteka();
                    this->del_copyOne(cd);
                }
                break;
            }
            case 14 : {
                if (base == 1) {
                    Reader t = enter_Reader();
                    this->print_onec(t);
                } else {
                    Cartoteka t = enter_Cartoteka();
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
    reader = new DB::DataBase<Reader>("", "");
    card = new DB::DataBase<Cartoteka>("", "");
    base = 1;
}

void BDcommunity::checkIO(bool &in, bool &out)
{
    if (base == 1) {
        out = reader->valid_write();
        in = reader->valid_read();
    } else {
        in = card->valid_read();
        out = card->valid_write();
    }
}

bool BDcommunity::find(Cartoteka s)
{
    return card->find(s);
}

void BDcommunity::create()
{
    if (base == r) {
        reader->generate();
    } else {
        card->generate();
    }
}

void BDcommunity::add_new_record(Cartoteka rec)
{
    card->add_rec(rec);
    card->write_one(rec);
}

void BDcommunity::printBase()
{
    if (base == r) {
        reader->print_all();
    } else {
        card->print_all();
    }
}

bool BDcommunity::find(Reader s)
{
    return reader->find(s);
}

void BDcommunity::del_copy(Cartoteka &T)
{
    card->del_oneC(T);
}

void BDcommunity::switch_input(string newfilename)
{
    if (base == 1) {
        reader->rdreopen(newfilename);
    } else {
        card->rdreopen(newfilename);
    }
}

void BDcommunity::switch_output(string newfilename)
{
    if (base == 1) {
        reader->wrreopen(newfilename);
    } else {
        card->wrreopen(newfilename);
    }
}

void BDcommunity::del_copy(Reader &T)
{
    reader->del_oneC(T);
}

void BDcommunity::add_new_record(Reader rec)
{
    reader->add_rec(rec);
    reader->write_one(rec);

}

BDcommunity::~BDcommunity()
{
    delete card;
    delete reader;
}

void BDcommunity::sort(int n)
{
    if (base == 1) {
        reader->switchCase(n);
        reader->sorting();
    } else {
        reader->switchCase(n);
        card->sorting();
    }
}

void BDcommunity::print_onec(Reader &t)
{
    reader->printC(t);
}

void BDcommunity::del_base()
{
    if (base == 1) {
        reader->clean_your_ass();

    } else {
        card->clean_your_ass();
    }
}

void BDcommunity::print_onec(Cartoteka &t)
{
    card->printC(t);
}

bool BDcommunity::del_record(Reader &t)
{
    return reader->del_rec(t);
}

int BDcommunity::write()
{
    if (base == 1) {
        if (!reader->valid_write()) return EXIT_FAILURE;
        reader->write();
    } else {
        if (!card->valid_write()) return EXIT_FAILURE;
        card->write();
    }
    return EXIT_SUCCESS;
}

int BDcommunity::load()
{
    if (base == 1) {
        if (!reader->valid_read())
            return EXIT_FAILURE;
        reader->load();
    } else {
        if (!card->valid_read())
            return EXIT_FAILURE;
        card->load();
    }
    return EXIT_SUCCESS;
}

bool BDcommunity::del_record(Cartoteka &t)
{
    return card->del_rec(t);
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
                    Reader t;
					
					t = parse_reader(optarg);
					add_new_record(t);

                } else {
                    Cartoteka t;
                    t = parse_card(optarg);
                    add_new_record(t);
                }

                break;
            }
            case 'd' : {
                if (base == 1) {
                    Reader t;
					t = parse_reader(optarg);
                    del_copy(t);
                } else {
                    Cartoteka t;
					t = parse_card(optarg);
                    del_copy(t);
                }
                break;
            }
            case 'p' : {
                if (base == 1) {
                    Reader t;
					t = parse_reader(optarg);
                    print_onec(t);
                } else {
                    Cartoteka t;
					t = parse_card(optarg);
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
                cout << "Template Reader : FIO /..." << endl;
                cout << "Template Cartoteka : FIO /..." << endl;
                cout << "-f filename for read by file" << endl;
                cout << "-b 1/2 choose base(Reader/Cartoteka)" << endl;
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

void BDcommunity::del_copyOne(Reader &T)
{
    reader->del_oneC(T);
}

void BDcommunity::del_copyOne(Cartoteka &T)
{
    card->del_oneC(T);
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
                Reader t;
				t = parse_reader(instructioin);
                add_new_record(t);
            } else {
                Cartoteka t;
				t = parse_card(instructioin);
                add_new_record(t);
            }
        } else if (command == "deleteRecord") {
            if (base == 1) {
                Reader t;
				t = parse_reader(instructioin);
                del_copy(t);
            } else {
                Cartoteka t;
				t = parse_card(instructioin);
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
                Reader t;
				t = parse_reader(instructioin);
                print_onec(t);
            } else {
                Cartoteka t;
				t = parse_card(instructioin);
                print_onec(t);
            }
        } else if (command == "report") {

        }
    }
    instructioin.close();
	
}

Reader BDcommunity::parse_reader(ifstream &os) {
	Reader rd;

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
}

Cartoteka BDcommunity::parse_card(ifstream &os) {
	Cartoteka card;
	
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
	
	card.setAuthor(author);
	card.setName(name);
	card.setPublishing(publishing);
	card.setYear(year);
	card.setSection(section);
	card.setAvail(avail);
	card.setValuation(valuation);
	
	return card;
}

Reader BDcommunity::parse_reader(string s) {
	Reader rd;
	
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
}

Cartoteka BDcommunity::parse_card(string s) {
	Cartoteka card;
	
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
	
	card.setAuthor(author);
	card.setName(name);
	card.setPublishing(publishing);
	card.setYear(year);
	card.setSection(section);
	card.setAvail(avail);
	card.setValuation(valuation);
	
	return card;
}

void BDcommunity::report()
{
    map<string, int> janr;
    int atake = 0;
    unsigned size = 0;

    auto e = reader->end();
    for (auto p = reader->begin(); p != e; ++p) {
        ++size;
        string name = p->getBook_genre();
        while (name.size()) {
            unsigned long k = name.find("|");
            string ss = name.substr(0, k);
            if (k == string::npos) name.clear();
            else name.erase(0, k + 1);
            janr[ss] += 1;
            ++atake;
        }
    }
    cout << "Average taking books " << atake / size << endl;
    auto z = card->end();
    size = 0;
    atake = 0;
    for (auto p = card->begin(); p != z; ++p) {
        atake += atoi(p->getValuation().c_str());
        ++size;
    }
    cout << "Average valutation " << atake / size << endl;
    cout << "Jars population : " << endl;
    for (auto p = janr.begin(); p != janr.end(); ++p) {
        cout << p->first << ' ' << p->second << endl;
    }

}
