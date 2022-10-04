#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe
{
    float lenght = 0, diameter = 0;
    string status;
};
struct CS
{
    string name;
    double  shopcount = 0, workshop = 0;
    float effectiveness = 0;
};




void menu(int& option)
{
    cout << "Choose option:\n\n 1.Add pipe 2.Add CS 3.View all objects 4.Edit pipe 5.Edit CS 6.Save 7.Load 0.Exit\n";
    while (!((cin >> option).good()) || (option < 0)) {
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void addPipe(Pipe& p)
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

    do {
        cin >> status;
        if (status == "yes") {
            status = "Pipe_works";
            return status;
        }
        else if (status == "no") {
            status = "Pipe_under_repair";
            return (status);
        }
        else {
            cout << "WRITE YES OR NO!!!\n";
        }
    } while (status != "yes" or status != "no");

    cout << "\n";

}

void addCS(CS& cs)
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

void Viewallobjects(Pipe& p, CS& cs)
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

void editPipe(Pipe& p)
{
    if (p.status != "") {
        WORK(p.status);
    }
    else {
        cout << " The pipe has not been added\n";
    }
}

void editCS(CS& cs)
{


    if (cs.shopcount != 0) {
        do {
            cout << "Change the number of workshops (<= " << cs.shopcount << ")" << endl;
            cin >> cs.workshop;
            cout << "\n";
            cin.clear(); //clean pole vvoda
            cin.ignore(INT_MAX, '\n'); //ignor polya vvoda

        } while (cs.shopcount < cs.workshop or cs.workshop < 1);
        cs.workshop = cs.workshop;
        cs.effectiveness = cs.workshop / cs.shopcount;
    }
    else {
        cout << "ERROR\n";
    }
}


void to_file_all_data(Pipe& p, CS& cs)
{
    ofstream fout;   //ifstream file - otvechaet za chtenie, перед этим библеотеку подключаем fstream and string
    fout.open("savee.txt");

    //if (p.lenght == 0 and p.diameter == 0)
       // fout << "Pipe not found \n";
    //else
    //{
    fout << p.lenght << endl << p.diameter << endl << p.status << "\n";
    //}

    //if (cs.shopcount == 0 and cs.workshop == 0)
      //  fout << "CS not found \n";
    //else
    //{
    fout << cs.name << endl << cs.shopcount << endl << cs.workshop << endl << cs.effectiveness << "\n";
    // }

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
    string status;
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
            WORK(p.status);
            cout << "lenght = " << p.lenght << "\n" << "diameter = " << p.diameter << "\n" << "status = " << p.status << endl;
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

