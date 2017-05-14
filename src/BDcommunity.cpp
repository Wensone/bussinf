#include <map>
#include "../headers/BDcommunity.h"

void BDcommunity::prtin_sick()
{
    cout << "1. name" << endl
         << "2. symptoms " << endl
         << "3. procedure" << endl
         << "4. medics" << endl;
}

void BDcommunity::print_medic()
{

    cout << "1. name" << endl
         << "2. amt " << endl
         << "3. permutability" << endl
         << "4. shelf_life" << endl
         << "5. prices" << endl;
}

medic BDcommunity::in_Medic()
{
    string new_pole;
    medic m;
    {

        cout << "name : ";
        cin.ignore();
        getline(cin, new_pole);
        m.setName(new_pole);
        cout << "Amt : ";

        getline(cin, new_pole);
        m.setAmt(new_pole);
        cout << "Permutablity : ";
        getline(cin, new_pole);
        m.setPermutability(new_pole);
        cout << "Price: ";

        getline(cin, new_pole);
        m.setPrices(new_pole);
        cout << "Shelf life: ";

        getline(cin, new_pole);
        m.setShelf_life(new_pole);
        cout << "Solded: ";
        getline(cin, new_pole);
        m.setSold(new_pole);
    }
    return m;
}

sick BDcommunity::in_Sick()
{
    string new_pole;
    sick s;
    {

        cout << "name : ";
        cin.ignore();
        getline(cin, new_pole);
        s.setName(new_pole);
        cout << "symptoms : ";
        getline(cin, new_pole);
        s.setSymptoms(new_pole);
        cout << "procedure : ";
        getline(cin, new_pole);
        s.setProcedure(new_pole);
        cout << "medics : ";
        getline(cin, new_pole);
        s.setMedics(new_pole);
        cin.clear();
    }
    return s;
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
        cout << "Now base is " << ((base == 1) ? "medic" : "sick") << endl;
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
             << "15. Report" << endl
             << "16. Heal" << endl;

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
                    print_medic();
                } else {
                    prtin_sick();
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
                    this->add_new_record(in_Medic());
                } else {
                    this->add_new_record(in_Sick());
                }
                break;
            }
            case 11 : {
                if (base == 1) {
                    medic rd = in_Medic();
                    if (this->del_record(rd)) {
                        cout << "Deleted success" << endl;
                    }
                } else {
                    sick cd = in_Sick();
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
                    medic rd = in_Medic();
                    this->del_copyOne(rd);
                } else {
                    sick cd = in_Sick();
                    this->del_copyOne(cd);
                }
                break;
            }
            case 14 : {
                if (base == 1) {
                    medic t = in_Medic();
                    this->print_onec(t);
                } else {
                    sick t = in_Sick();
                    this->print_onec(t);
                }
                break;
            }
            case 15 : {
                this->report();
                break;
            }
            case 16 : {
                string name_bolezn;
                cout << "Enter name of sick" << endl;
                cin >> name_bolezn;
                this->heal(name_bolezn);
                break;
            }
            default:
                return;
        }
    } while (true);
}

BDcommunity::BDcommunity()
{
    m = new DB::DataBase<medic>("", "");
    s = new DB::DataBase<sick>("", "");
    base = 1;
}

void BDcommunity::checkIO(bool &in, bool &out)
{
    if (base == 1) {
        out = m->valid_write();
        in = m->valid_read();
    } else {
        in = s->valid_read();
        out = s->valid_write();
    }
}

bool BDcommunity::find(sick &s)
{
    return this->s->find(s);
}

void BDcommunity::create()
{
    if (base == r) {
        m->generate();
    } else {
        s->generate();
    }
}

void BDcommunity::add_new_record(sick rec)
{
    s->add_rec(rec);
    s->write_one(rec);
}

void BDcommunity::printBase()
{
    if (base == r) {
        m->print_all();
    } else {
        s->print_all();
    }
}

bool BDcommunity::find(medic &s)
{
    return this->m->find(s);
}

void BDcommunity::del_copy(sick &T)
{
    s->del_oneC(T);
}

void BDcommunity::switch_input(string newfilename)
{
    if (base == 1) {
        m->rdreopen(newfilename);
    } else {
        s->rdreopen(newfilename);
    }
}

void BDcommunity::switch_output(string newfilename)
{
    if (base == 1) {
        m->wrreopen(newfilename);
    } else {
        s->wrreopen(newfilename);
    }
}

void BDcommunity::del_copy(medic &T)
{
    m->del_oneC(T);
}

void BDcommunity::add_new_record(medic rec)
{
    m->add_rec(rec);
    m->write_one(rec);

}

BDcommunity::~BDcommunity()
{
    delete s;
    delete m;
}

void BDcommunity::sort(int n)
{
    if (base == 1) {
        m->switchCase(n);
        m->sorting();
    } else {
        m->switchCase(n);
        s->sorting();
    }
}

void BDcommunity::print_onec(medic &t)
{
    m->printC(t);
}

void BDcommunity::del_base()
{
    if (base == 1) {
        m->clean_your_ass();

    } else {
        s->clean_your_ass();
    }
}

void BDcommunity::print_onec(sick &t)
{
    s->printC(t);
}

bool BDcommunity::del_record(medic &t)
{
    return m->del_rec(t);
}

int BDcommunity::write()
{
    if (base == 1) {
        if (!m->valid_write()) return EXIT_FAILURE;
        m->write();
    } else {
        if (!s->valid_write()) return EXIT_FAILURE;
        s->write();
    }
    return EXIT_SUCCESS;
}

int BDcommunity::load()
{
    if (base == 1) {
        if (!m->valid_read())
            return EXIT_FAILURE;
        m->load();
    } else {
        if (!s->valid_read())
            return EXIT_FAILURE;
        s->load();
    }
    return EXIT_SUCCESS;
}

bool BDcommunity::del_record(sick &t)
{
    return s->del_rec(t);
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
    while ((choose = getopt(argc, argv, "f:hb:i:o:c:s:d:p:m:lw"))) {
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
                    medic t;

                    t = parse_Medic(optarg);
                    add_new_record(t);

                } else {
                    sick t;
                    t = parse_Sick(optarg);
                    add_new_record(t);
                }

                break;
            }
            case 'd' : {
                if (base == 1) {
                    medic t;
                    t = parse_Medic(optarg);
                    del_copy(t);
                } else {
                    sick t;
                    t = parse_Sick(optarg);
                    del_copy(t);
                }
                break;
            }
            case 'p' : {
                if (base == 1) {
                    medic t;
                    t = parse_Medic(optarg);
                    print_onec(t);
                } else {
                    sick t;
                    t = parse_Sick(optarg);
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
                        cout << "Incorrect (" << optarg << ")" << endl;
                    }
                }

                break;
            }
            case 'h' : {
                // f:hb:i:o:c:s:d:p:m:lw
                cout << "Template medic : FIO /..." << endl;
                cout << "Template sick : FIO /..." << endl;
                cout << "-f filename for read by file" << endl;
                cout << "-b 1/2 choose base(medic/sick)" << endl;
                cout << "-i file/t -o file - choose input and output files" << endl;
                cout << "-s templates - add new record" << endl;
                cout << "-p templates - print all records by templates" << endl;
                cout << "-m number_of_sort(1-7)" << endl;
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

void BDcommunity::del_copyOne(medic &T)
{
    m->del_oneC(T);
}

void BDcommunity::del_copyOne(sick &T)
{
    s->del_oneC(T);
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
                medic t;
                t = parse_Medic(instructioin);
                add_new_record(t);
            } else {
                sick t;
                t = parse_Sick(instructioin);
                add_new_record(t);
            }
        } else if (command == "deleteRecord") {
            if (base == 1) {
                medic t;
                t = parse_Medic(instructioin);
                del_copy(t);
            } else {
                sick t;
                t = parse_Sick(instructioin);
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
                medic t;
                t = parse_Medic(instructioin);
                print_onec(t);
            } else {
                sick t;
                t = parse_Sick(instructioin);
                print_onec(t);
            }
        } else if (command == "report") {
            report();
        }
    }
    instructioin.close();

}

medic BDcommunity::parse_Medic(ifstream &os)
{
    /*
	medic rd;

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

sick BDcommunity::parse_Sick(ifstream &os)
{
    /*
	sick s;
	
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
	
	s.setAuthor(author);
	s.setName(name);
	s.setPublishing(publishing);
	s.setYear(year);
	s.setSection(section);
	s.setAvail(avail);
	s.setValuation(valuation);
	
	return s;
     */
}

medic BDcommunity::parse_Medic(string s)
{
    /*
	medic rd;
	
	string fio;
	string address;
	string email;
	string book_list; // список взятых книг
	string time_take; // время взятия
	string time_using; // срок пользования
	string book_genre;
	
	int i = 0;
	while(m[i] != '/'){
		fio += m[i];
	}
	i++;
	while(m[i] != '/'){
		address += m[i];
	}
	i++;
	while(m[i] != '/'){
		email += m[i];
	}
	i++;
	while(m[i] != '/'){
		book_list += m[i];
	}
	i++;
	while(m[i] != '/'){
		time_take += m[i];
	}
	i++;
	while(m[i] != '/'){
		time_using += m[i];
	}
	i++;
	while(m[i] != '\0'){
		book_genre += m[i];
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

sick BDcommunity::parse_Sick(string s)
{/*
	sick s;
	
	string author; // автор
	string name; // название
	string publishing; // издательство
	string year; // год издания
	string section; // радел(спец. литература, хобби, хуеби)
	string avail; // наличие
	string valuation; // оценка
	
	int i = 0;
	while(m[i] != '/'){
		author += m[i];
	}
	i++;
	while(m[i] != '/'){
		name += m[i];
	}
	i++;
	while(m[i] != '/'){
		publishing += m[i];
	}
	i++;
	while(m[i] != '/'){
		year += m[i];
	}
	i++;
	while(m[i] != '/'){
		section += m[i];
	}
	i++;
	while(m[i] != '/'){
		avail += m[i];
	}
	i++;
	while(m[i] != '\0'){
		valuation += m[i];
	}
	
	s.setAuthor(author);
	s.setName(name);
	s.setPublishing(publishing);
	s.setYear(year);
	s.setSection(section);
	s.setAvail(avail);
	s.setValuation(valuation);
	
	return s;*/
}

void BDcommunity::report()
{
    int asold = 0;
    int aamnt = 0;
    int aprice = 0;
    int pribil = 0;
    for (auto p = m->begin(); p != m->end(); ++p) {
        asold += atoi(p->getSold().c_str());
        aamnt += atoi(p->getAmt().c_str());
        aprice += atoi(p->getPrices().c_str());
        pribil += (atoi(p->getSold().c_str()) * atoi(p->getPrices().c_str()));
    }
    asold /= m->getSize();
    aamnt /= m->getSize();
    aprice /= m->getSize();
    cout << "Average solded " << asold << endl;
    cout << "Average amnt " << aamnt << endl;
    cout << "Average price " << aprice << endl;
    cout << "Pribil " << pribil << endl;
}

void BDcommunity::heal(string bolezn)
{
    sick z;
    z.setName(bolezn);
    if (!find(z)) {
        cout << "Not founded sick" << endl;
        return;
    } else {
        cout << z << endl;
    }
    string medicaments = z.getMedics();

    while (medicaments.size() > 0) {
        medic medic1;
        unsigned long ss = medicaments.find(' ');
        if (ss == string::npos) break;
        string name = medicaments.substr(0, ss);
        ss = medicaments.find(", ");
        if (ss != string::npos) {
            medicaments.erase(0, ss + 2);
        } else {
            medicaments.clear();
        }
        medic1.setName(name);
        if (find(medic1)) {
            cout << name << endl;
            if (atoi(medic1.getAmt().c_str()) > 0) {
                cout << "You can take it" << endl;
                for (auto p = m->begin(); p != m->end(); ++p) {
                    if (medic1 == *p) {
                        p->setSold(to_string(atoi(p->getSold().c_str()) + 1));
                        p->setAmt(to_string(atoi(p->getAmt().c_str()) - 1));
                        break;
                    }
                }
            } else {
                cout << "Not enought" << endl;
            }
        } else {
            cout << "Not founded " << name << endl;
        }
    }
}
