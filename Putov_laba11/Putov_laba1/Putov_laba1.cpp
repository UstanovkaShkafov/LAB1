#include <iostream>
#include <fstream>
#include <string>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "cs.h"
#include "pipe.h"
#include "check.h"
using namespace std;
   
void info(unordered_map<int, Pipe>& pipe_group, unordered_map<int, CS>& cs_group) {
    for (auto& pipe : pipe_group) {
        cout << pipe.second << endl;
    }
    for (auto& cs : cs_group) {
        cout << cs.second << endl;  //info about p/cs's
    }
}




void menu(int& option)
{
    cout << "Choose option:\n\n 1.Add pipe 2.Add CS 3.View all objects 4.Edit pipe 5.Edit CS 6.Save 7.Load 0.Exit\n";
    while (!((cin >> option).good()) || (option < 0)) {
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}




//void addPipe(Pipe& p)
//{
    istream& operator>> (istream & in, Pipe & p)
    {
        cout << "Enter the length" << endl;
        p.lenght = correctnumber(0.0, DBL_MAX);

        cout << "Enter the diameter" << endl;
        p.diameter = correctnumber(0.0, DBL_MAX);

        cout << "Enter the status (1 - yes, 2 - no)\n";
        p.status = correctnumber(1, 2);
        cout << "Pipe added";
        return in;
    }
//}


    istream& operator>> (istream& in, CS& cs)
    {
        cout << "Enter the title of CS" << endl;
        getline(cin, cs.name);
        cout << "\n";

        cout << "Enter the number of shop" << endl;
        cs.shopcount = correctnumber(0, INT_MAX);
        cout << "\n";

        cout << "Enter the number of workshop (<= " << cs.shopcount << ")" << endl;
        cs.workshop = correctnumber(0, cs.shopcount);
        cout << "\n";

        cout << "Effectiveness" << endl;
        cs.effectiveness = correctnumber(0, 100);
        return in;
    }

void Viewallobjects(Pipe& p, CS& cs)
{
    if (p.lenght != 0) {
        cout << "Your Pipes: " << endl;
        cout << "The length = " << p.lenght << endl;
        cout << "Diameter = " << p.diameter << endl;
        if (p.status == 1) {
            cout << "Pipe is work" << endl;
        }
        else
        {
            cout << "Pipe is repaired" << endl;
        }
        cout << "\n";
    }
    else
        cout << "Pipe not found\n" << endl;

    if (cs.shopcount != 0) {
        cout << "Your CS: " << endl;
        cout << "Name = " << cs.name << endl;
        cout << "Shopcount = " << cs.shopcount << endl;
        cout << "Workshop = " << cs.workshop << endl;
        cout << "Effectiveness = " << cs.effectiveness << endl;
    }
    else
        cout << "CS not found\n" << endl;
}

void editPipe(Pipe& p)
{
    if (p.status != 0) {
        cout << "Enter the status (1 - yes, 2 - no)\n";
        checkstatus(p.status);
        cout << "Pipe edited";
    }
    else cout << "CS is not created\n";
}

void editCS(CS& cs)
{
    if (cs.shopcount != 0) {
        cout << "Enter the number of workshop (<= " << cs.shopcount << ")" << endl;

        checkintWork(cs.workshop, cs.shopcount);
        cout << "\n" << "CS edited\n";
    }
    else cout << "CS is not created\n";
}


void to_file_all_data(Pipe& p, CS& cs)
{
    ofstream fout;   //ifstream file - otvechaet za chtenie, перед этим библеотеку подключаем fstream and string
    fout.open("savee.txt");

    fout << p.lenght << endl << p.diameter << endl << p.status << "\n";

    fout << cs.name << endl << cs.shopcount << endl << cs.workshop << endl << cs.effectiveness << "\n";


    fout.close();
}

void from_file_all_date(Pipe& p, CS& cs)
{
    ifstream fin;
    string line;
    fin.open("savee.txt");
    fin >> p.lenght;
    fin >> p.diameter;
    fin >> p.status;
    fin >> cs.name;
    fin >> cs.shopcount;
    fin >> cs.workshop;
    fin >> cs.effectiveness;
    fin.close();
}

int main()
{
    Pipe p;
    CS cs;
    int option = -1;
    setlocale(LC_ALL, "ru");
    while (option) {

        menu(option);
        cout << "\n";

        switch (option)
        {
        case 1:
            system("cls");
            addPipe(p);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            addCS(cs);
            cout << "\n";
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            Viewallobjects(p, cs);
            cout << "\n";
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            editPipe(p);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            editCS(cs);
            system("pause");
            system("cls");
            break;
        case 6: {
            to_file_all_data(p, cs);
            cout << "File was saved" << "\n";
            system("pause");
            system("cls");
            break;
        }

        case 7: {
            from_file_all_date(p, cs);
            cout << "File was uploaded" << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 0:
            return 0;
            break;

        default:
            cout << "Not correct number\n";
            break;
        }
    }


}