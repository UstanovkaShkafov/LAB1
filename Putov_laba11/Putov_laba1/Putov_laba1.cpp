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


void to_file_all_data()
{
    ofstream fout;   //ifstream file - otvechaet za chtenie, перед этим библеотеку подключаем fstream and string
    fout.open("savee.txt");

    if (p.lenght == 0 and p.diameter == 0)
        fout << "Pipe not found \n";
    else
    {
        fout << "YOUR PIPE: \n" << p.lenght << endl << p.diameter << endl << p.status << "\n";
    }

    if (cs.shopcount == 0 and cs.workshop == 0)
        fout << "CS not found \n";
    else
    {
        fout << "\n" << "YOUR CS: \n" << cs.name << endl << cs.shopcount << endl << cs.workshop << endl << cs.effectiveness << "\n";
    }
    
    fout.close();
}

void from_file_all_date()
{
    ifstream fin;
    fin.open("savee.txt");
    cout << "Lenth: \n";
    fin >> p.lenght;
    fin >> p.diameter;
    fin >> p.status;
    fin.close();
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
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            addCS();
            cout << "\n";
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            Viewallobjects();
            cout << "\n";
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            editPipe(p.status);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            editCS(cs.workshop);
            system("pause");
            system("cls");
            break;
        case 6: {
            to_file_all_data();
            cout << "File was saved" << "\n";
            system("pause");
            system("cls");
            break;
        }

        case 7: {
            from_file_all_date();
            cout << "File was uploaded" << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 0:
            return 0;
            break;

        default: cout << "Not correct number";
            break;
        }
    }



}

