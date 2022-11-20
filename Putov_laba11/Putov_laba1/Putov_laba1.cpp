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
  




void menu(int& option)
{
    cout << "Choose option:\n\n 1.Add pipe 2.Add CS 3.View all objects 4.Edit pipe 5.Edit CS 6.Save 7.Load 0.Exit\n";
    while (!((cin >> option).good()) || (option < 0)) {
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void Viewallobjects(unordered_map<int, Pipe>& PipeGroup, unordered_map<int, CS>& CsGroup) {
    for (auto& pipe : PipeGroup) {
        cout << pipe.second << endl;
    }
    for (auto& cs : CsGroup) {
        cout << cs.second << endl;  //Viewallobjects
    }
}



//void addPipe(Pipe& p)
//{
   
//}


   



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
    int option = -1;
    unordered_map<int, Pipe> PipeGroup;
    unordered_map<int, CS> CsGroup;
    setlocale(LC_ALL, "ru");
    while (option) {
        cout << "\nChoose option:\n 1.Add pipe 2.Add CS 3.View all objects " <<
            "4.Edit pipe 5.Edit CS 6.Save 7.Load 8.Search pipe 9.Search CS 0.Exit\n";
        cout << "\n";

        sSwitch (option)
        {
        case 1:
            //system("cls");
            Pipe p;
            cin >> p;
            PipeGroup.insert({ p.get_id(), p });
            //system("pause");
            //system("cls");
            break;
        case 2:
            //system("cls");
            CS cs;
            cin >> cs;
            //system("pause");
            //system("cls");
            CsGroup.insert({ cs.get_id(), cs });
            break;
        case 3:
            system("cls");
            Viewallobjects(PipeGroup, CsGroup);
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