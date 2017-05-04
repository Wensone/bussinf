#ifndef BASEDATA_BDCOMMUNITY_H
#define BASEDATA_BDCOMMUNITY_H

#include <iostream>
#include <string>
#include "Cartoteka.h"

using namespace std;

class BDcommunity {
private:
    DB::DataBase<Reader> *reader;
    DB::DataBase<Cartoteka> *card;
    int base;
    enum Type_base {
        r = 1, c = 2
    };
public:
    BDcommunity()
    {
        reader = new DB::DataBase<Reader>("", "");
        card = new DB::DataBase<Cartoteka>("", "");
        base = 1;
    }

    ~BDcommunity()
    {
        delete card;
        delete reader;
    }

    void print_Cartoteka();

    void print_Reader();

    Reader enter_Reader();

    Cartoteka enter_Cartoteka();

    int getBaseNow()
    {
        return base;
    }

    void change_base()
    {
        this->base = (base == 1) ? 2 : 1;
    }

    void checkIO(bool &in, bool &out)
    {
        if (base == 1) {
            out = reader->valid_write();
            in = reader->valid_read();
        } else {
            in = card->valid_read();
            out = card->valid_write();
        }
    }

    void create()
    {
        if (base == r) {
            reader->generate();
        } else {
            card->generate();
        }
    }

    void printBase()
    {
        if (base == r) {
            reader->print_all();
        } else {
            card->print_all();
        }
    }

    void switch_input(string newfilename)
    {
        if (base == 1) {
            reader->rdreopen(newfilename);
        } else {
            card->rdreopen(newfilename);
        }
    }

    void switch_output(string newfilename)
    {
        if (base == 1) {
            reader->wrreopen(newfilename);
        } else {
            card->wrreopen(newfilename);
        }
    }

    void add_new_record(Reader rec)
    {
        /*string new_pole;
        if (base == 1) {
            Reader NewReader;
            cout << "FIO : ";
            cin >> new_pole;
            NewReader.setFio(new_pole);
            cout << "Address : ";
            cin >> new_pole;
            NewReader.setAddress(new_pole);
            cout << "Email : ";
            cin >> new_pole;
            NewReader.setEmail(new_pole);
            cout << "Book list : ";
            cin >> new_pole;
            NewReader.setBook_list(new_pole);
            cout << "Book genre : ";
            cin >> new_pole;
            NewReader.setBook_genre(new_pole);
            cout << "Time taking : ";
            cin >> new_pole;
            NewReader.setTime_take(new_pole);
            cout << "Time using : ";
            cin >> new_pole;
            NewReader.setTime_using(new_pole);
            reader->add_rec(NewReader);
        } else {
            Cartoteka NewRecord;
            cout << "Author : ";
            cin >> new_pole;
            NewRecord.setAuthor(new_pole);
            cout << "Name : ";
            cin >> new_pole;
            NewRecord.setName(new_pole);
            cout << "Avail : ";
            cin >> new_pole;
            NewRecord.setAvail(new_pole);
            cout << "Publishing : ";
            cin >> new_pole;
            NewRecord.setPublishing(new_pole);
            cout << "Setciton : ";
            cin >> new_pole;
            NewRecord.setSection(new_pole);
            cout << "Valution : ";
            cin >> new_pole;
            NewRecord.setValuation(new_pole);
            cout << "Year : ";
            cin >> new_pole;
            NewRecord.setYear(new_pole);
            card->add_rec(NewRecord);
        }*/
        reader->add_rec(rec);
    }

    void add_new_record(Cartoteka rec)
    {
        card->add_rec(rec);
    }

    void sort(int n)
    {
        if (base == 1) {
            reader->switchCase(n);
            reader->sorting();
        } else {
            reader->switchCase(n);
            card->sorting();
        }
    }

    bool find(Reader s)
    {
        return reader->find(s);
    }

    bool find(Cartoteka s)
    {
        return card->find(s);
    }

    bool del_record(Reader &t)
    {
        return reader->del_rec(t);
    }

    bool del_record(Cartoteka &t)
    {
        return card->del_rec(t);
    }

    void del_copy(Reader &T)
    {
        reader->del_oneC(T);
    }

    void del_copy(Cartoteka &T)
    {
        card->del_oneC(T);
    }
    int write()
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

    int load()
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

    void print_onec(Reader &t)
    {
        reader->printC(t);
    }

    void print_onec(Cartoteka &t)
    {
        card->printC(t);
    }

    void del_base()
    {
        if (base == 1) {
            reader->clean_your_ass();
        } else {
            card->clean_your_ass();
        }
    }


    void menu()
    {
        cout << "\t\t Menu \t\t\n";

        do {
            cout << "Now base is " << ((base == 1) ? "Reader" : "Cartoteka") << endl;
            bool in, out;
            this->checkIO(in, out);
            cout << "Input : " << ((in) ? "YES " : " NO ") << "| Output : "  << ((out) ? "YES" : "NO") << endl;
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
                 << "11. Delete record" << endl;

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
                    if(base == 1){
                        print_Reader();
                    } else {
                        print_Cartoteka();
                    }
                    int n;
                    do{
                        cin >> n;
                    }while(n < 1 || n > 7);
                    this -> sort(n);
                    break;
                }
                case 10 : {
                    if(base == 1){
                        this->add_new_record(enter_Reader());
                    } else {
                        this->add_new_record(enter_Cartoteka());
                    }
                    break;
                }
                case 11 : {
                    if(base == 1){
                        Reader rd = enter_Reader();
                        this->del_record(rd);
                    } else {
                        Cartoteka cd = enter_Cartoteka();
                        this->del_record(cd);
                    }
                    break;
                }
                default:
                    return;
            }
        } while (true);
    }

};

void BDcommunity::print_Cartoteka()
{
    cout << "1. Author"  << endl
         << "2. Name " << endl
         << "3. Publishing" << endl
         << "4. Year" << endl
         << "5. Section" << endl
         << "6. Avail" << endl
         << "7. Valuation" << endl;
}

void BDcommunity::print_Reader()
{
    cout << "1. FIO"  << endl
         << "2. Address " << endl
         << "3. E-mail" << endl
         << "4. Book list" << endl
         << "5. Time take" << endl
         << "6. Time using"<< endl
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


#endif //BASEDATA_BDCOMMUNITY_H
