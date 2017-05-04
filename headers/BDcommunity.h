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
        cout << "Enter starting input and output file by Readers" << endl;
        string in, out;
        cin >> in >> out;
        reader = new DB::DataBase<Reader>(in, out);

        cout << "Enter starting input and output file by Cartoteka" << endl;
        cin >> in >> out;
        card = new DB::DataBase<Cartoteka>(in, out);

        cout << "Enable commands :" << endl;
        // commands
        cout << "starting base for edition" << endl;
        base = 1;
    }

    ~BDcommunity()
    {
        delete card;
        delete reader;
    }

    int getBaseNow()
    {
        return base;
    }

    // выбираем базу для работы
    void change_base()
    {
        cout << "Enter numbedr Base :" << endl
             << "1.Reader\n2.Cartoteka" << endl;
        do {
            cin >> base;
            if (base != r || base != c) {
                cout << "Incorrect number of bd" << endl;
            }
        } while (base < r || base > c);

    }

    void create()
    {
        switch (base) {
            case r : {
                reader->generate();
                break;
            }

            case c : {
                card->generate();
                break;
            }
        }
    }

    void printBase()
    {
        switch (base) {
            case r : {
                reader->print_all();
                break;
            }
            case c : {
                card->print_all();
                break;
            }
        }
    }

    void switch_input()
    {
        cout << "Enter new input filename" << endl;
        string newfilename;
        cin >> newfilename;
        if (base == 1) {
            reader->rdreopen(newfilename);
        } else {
            card->rdreopen(newfilename);
        }
    }

    void switch_output()
    {
        cout << "Enter new output filename" << endl;
        string newfilename;
        cin >> newfilename;
        if (base == 1) {
            reader->wrreopen(newfilename);
        } else {
            card->wrreopen(newfilename);
        }
    }

    void add_new_record()
    {
        string new_pole;
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
        }
    }

    void sort()
    {
        cout << "What are you want sort?" << endl;
        if (base == 1) {
            // list number of pole
            int n;
            cin >> n;
            while (!Reader::setNumber(n)) {
                cout << "Incorrect value" << endl;
            }
            reader->sorting();
        } else {
            // list number of pole
            int n;
            cin >> n;
            while(!Cartoteka::setPole(n)) {
                cout << "Incorrect value" << endl;
                card->sorting();
            }
        }
    }
	
	void find(){
		cout << "Enter search key" << endl;
		string search_key;
		cin.ignore();
		getline(cin, search_key);
		if(base == 1){
			Reader search;
			search;
			//reader->find(search_key);
		}
	}

    //find
    //delete
    //write
    //load
    //printOne


    int menu()
    {
		cout << "\t\t Menu \t\t\n";
		
		do{
			cout << "1. " << endl
					<< "2. " << endl
					<< "3. " << endl
					<< "4. " << endl
					<< "5. " << endl
					<< "6. " << endl
					<< "7. " << endl;
			int key;
			cout << "Enter menu point: ";
			cin >> key;
			switch (key){
				case 1: {
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					break;
				}
				case 6: {
					break;
				}
				case 7: {
					break;
				}
				default: return 0;
			}
		}while(true);
    }

};


#endif //BASEDATA_BDCOMMUNITY_H
