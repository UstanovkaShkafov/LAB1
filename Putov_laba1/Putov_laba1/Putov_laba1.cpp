#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe
{
    float lenght, diameter;
    string status;

};
struct CS
{
    string name;
    double  shopcount, workshop;
    float effectiveness;
};

Pipe p;
CS cs;
int option = -1;

void menu()
{
    cout << "\nChoose option:\n\n 1.Add pipe 2.Add CS 3.View all objects 4.Edit pipe 5.Edit CS 6.Save 7.Load 0.Exit\n";
    cin >> option;

}

void addPipe()
{
    float lenght, diameter;

    cout << "Enter the length" << endl; //VVOD DLINI
    do {
        cin >> lenght;
        if (lenght <= 0) {
            cout << "Only numbers(> 0)";
            cout << "\n";
            cin.clear(); //clean pole vvoda
            cin.ignore(INT_MAX, '\n'); //ignor polya vvoda
        }
    } while (lenght <= 0);
    cout << "\n";
    p.lenght = lenght;

    cout << "Enter the diameter" << endl; //VVOD DIAMETRA
    do {
        cin >> diameter;
        if (diameter <= 0) {
            cout << "Only numbers(> 0)";
            cout << "\n";
            cin.clear(); //clean pole vvoda
            cin.ignore(INT_MAX, '\n'); //ignor polya vvoda
        }
    } while (diameter <= 0);
    cout << "\n";
    p.diameter = diameter;


}

string WORK(string& status) {
    cout << "Enter the status (pipe is work? yes or no)" << endl; //STATUS 
         //ne vivoditsa

    do {
        cin >> status;
        if (status == "yes") {
            status = "Pipe works";
            return status;
        }
        else if (status == "no") {
            status = "Pipe under repair";
            return (status);
        }
        else {
            cout << "WRITE YES OR NO!!!\n";
        }
    } while (status != "yes" or status != "no");

    cout << "\n";

}

void addCS()
{
    string name;
    double  shopcount, workshop;
    float effectiveness;

    cout << "Enter the title of CS" << endl;
    cin >> name;
    cs.name = name;
    cout << "\n";

    cout << "Enter the number of shop" << endl;
    do {

        cin >> shopcount;
        if (shopcount <= 0 || ((shopcount / trunc(shopcount)) != 1)) {
            cout << "Only numbers(> 0)";
            cout << "\n";
            cin.clear(); //clean pole vvoda
            cin.ignore(INT_MAX, '\n'); //ignor polya vvoda
        }

    } while ((shopcount <= 0) || ((shopcount / trunc(shopcount)) != 1));

    cs.shopcount = shopcount;

    do {

        cout << "Enter the number of workshop (<= " << cs.shopcount << ")" << endl;
        cin >> workshop;
        cout << "Only numbers";
        cout << "\n";
        cin.clear(); //clean pole vvoda
        cin.ignore(INT_MAX, '\n'); //ignor polya vvoda

    } while ((cs.shopcount < workshop) || (workshop < 0) || ((workshop / trunc(workshop)) != 1));

    cs.workshop = workshop;

    cout << "Effectiveness" << endl;
    cout << workshop / shopcount;


    effectiveness = workshop / shopcount;
    cs.effectiveness = effectiveness;
}

void Viewallobjects()
{
    cout << "Your Pipes: " << endl;
    cout << "The length = " << p.lenght << endl;
    cout << "Diameter = " << p.diameter << endl;
    cout << "Status = " << p.status << endl;
    cout << "\n";

    cout << "Your CS: " << endl;
    cout << "Name = " << cs.name << endl;
    cout << "Shopcount = " << cs.shopcount << endl;
    cout << "Workshop = " << cs.workshop << endl;
    cout << "Effectiveness = " << cs.effectiveness << endl;

}

string editPipe(string& status)
{
    cout << "Change the state of the pipe( 1 - work; 0 - don't work)" << endl;

    do {
        cin >> status;
        if (status == "1") {
            status = "Pipe works";
            return status;
        }
        else if (status == "0") {
            status = "Pipe under repair";
            return (status);
        }
        else {
            cout << "You need write 1 or 0!!!\n";
        }
    } while (status != "yes" or status != "no");

    cout << "\n";
}

void editCS(int workshop)
{
    do {

        cout << "Change the number of workshops (<= " << cs.shopcount << ")" << endl;
        cin >> workshop;
        cout << "\n";
        cin.clear(); //clean pole vvoda
        cin.ignore(INT_MAX, '\n'); //ignor polya vvoda

    } while (cs.shopcount < workshop or workshop < 1);

    cs.workshop = workshop;

    cs.effectiveness = cs.workshop / cs.shopcount;
}


void loadData (Pipe& p, CS& cs) {
    ifstream fin;
    string line;
    fin.open("savee.txt");
    getline(fin, line);
    p.lenght = stoi(line);
    fin.close();
    cout << "The sad" << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");
    while (option) {

        menu();
        cout << "\n";
        switch (option)
        {
        case 1:
            system("cls");
            addPipe();
            WORK(p.status);
            cout << "lenght = " << p.lenght << "\n" << "diameter = " << p.diameter << "\n" << "status = " << p.status << endl;
            break;

        case 2:
            system("cls");
            addCS();
            cout << "\n";
            break;
        case 3:
            system("cls");
            Viewallobjects();
            cout << "\n";
            break;
        case 4:
            system("cls");
            editPipe(p.status);
            break;
        case 5:
            system("cls");
            editCS(cs.workshop);
            break;
        case 6: {
            ofstream fout;   //ifstream file - otvechaet za chtenie, перед этим библеотеку подключаем fstream and string
            fout.open("savee.txt");
            fout << p.lenght << endl << p.diameter << endl << p.status << endl << "\n" << cs.name << endl << cs.shopcount << endl << cs.workshop << endl << cs.effectiveness << "%" << endl;
            fout.close();
            cout << "File was saved" << "\n";
            break;
        }

        case 7: {
            //ifstream fin;
            //fin.open("savee.txt");
            //fin >> p.lenght >> p.diameter >> p.status;

        }
        case 0:
            return 0;
            break;

        default: cout << "Not correct number";
            break;
        }
    }



}

