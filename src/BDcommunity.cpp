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
    while ((choose = getopt(argc, argv, "f:hb:i:o:c:a:d:p:s:"))) {
        switch (choose) {
            case 'f' : {
                // open filename and read
                return;
            }
            case 'a' : {
                if (base == 1) {
                    Reader t;
                    //pars reader
                    add_new_record(t);

                } else {
                    Cartoteka t;
                    //pars cartoteka
                    add_new_record(t);
                }

                break;
            }
            case 'd' : {
                if (base == 1) {
                    Reader t;
                    //pars
                    del_copy(t);
                } else {
                    Cartoteka t;
                    //pars
                    del_copy(t);
                }
                break;
            }
            case 'p' : {
                if (base == 1) {
                    Reader t;
                    //pars
                    print_onec(t);
                } else {
                    Cartoteka t;
                    //pars
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
                        cout << "Incorrect" << endl;
                    }
                }

                break;
            }
            case 'h' : {
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
                //parse
                add_new_record(t);
            } else {
                Cartoteka t;
                //parse
                add_new_record(t);
            }
        } else if (command == "deleteRecord") {
            if (base == 1) {
                Reader t;
                //parse
                del_copy(t);
            } else {
                Cartoteka t;
                //parse
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
                //parse
                print_onec(t);
            } else {
                Cartoteka t;
                //parse
                print_onec(t);
            }
        } else if (command == "report") {

        }
    }
}
