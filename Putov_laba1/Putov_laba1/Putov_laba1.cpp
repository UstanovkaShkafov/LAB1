#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pipe
{
    float lenght = 0, diameter = 0;
    int status = 0;
};
struct CS
{
    string name;
    int  shopcount = 0, workshop = 0;
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

void checkfloat(float& input)
{
    while (!((cin >> input).good()) || (input <= 0)) {
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void checkfloat2(float& input)
{
    while (!((cin >> input).good()) || (input < 0)) {
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void checkint(int& input)
{
    while (!((cin >> input).good()) || (input <= 0)) {
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void checkint2(int& input, int& zavod)
{
    while (!((cin >> input).good()) || (input < 0) || (input > zavod)) { //ne rabotaet
        cout << "\nError. Try again\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}


void checkstatus(int& status)
{
    do {
        checkint(status);

        if (status == 1) {
            cout << "Pipe is working\n";
        }
        else if (status == 2) {
            cout << "Pipe is being repaired\n";
        }
        else {
            cout << "\nError. Try again\n";
        }

    } while ((status != 1) and (status != 2));
}



void addPipe(Pipe& p)
{

    cout << "Enter the length" << endl; //VVOD DLINI
    checkfloat(p.lenght);

    cout << "Enter the diameter" << endl; //VVOD DIAMETRA
    checkfloat(p.diameter);

    cout << "Enter the status (1 - pipe work, 2 - pipe repaired)\n";
    checkstatus(p.status);
}



void addCS(CS& cs)
{
    cout << "Enter the title of CS" << endl;
    getline(cin >> ws, cs.name);
    cout << "\n";

    cout << "Enter the number of shop" << endl;
    checkint(cs.shopcount);
    cout << "\n";

    cout << "Enter the number of workshop (<= " << cs.shopcount << ")" << endl;
    checkint2(cs.workshop, cs.shopcount); //chota ne rabotaet

    cout << "\n";

    cout << "Effectiveness" << endl;
    checkfloat2(cs.effectiveness);
}

void Viewallobjects(Pipe& p, CS& cs)
{
    if (p.lenght != 0) {
        cout << "Your Pipes: " << endl;
        cout << "The length = " << p.lenght << endl;
        cout << "Diameter = " << p.diameter << endl;
        if (status == 1) {
            cout << "Status = Pipe work" << endl;
        }
        else {
            cout << "Status = Pipe repaired" << endl;
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
        cout << "CS not found" << endl;
}

void editPipe(Pipe& p)
{
    if (p.status != 0) {
        cout << "Enter the status (1 - pipe work, 2 - pipe repaired)\n";
        checkstatus(p.status);
        cout << "Pipe edited";
    }
    else cout << "CS is not created";
}

void editCS(CS& cs)
{
    if (cs.shopcount != 0) {
        cout << "Enter the number of workshop (<= " << cs.shopcount << ")" << endl;

        checkint2(cs.workshop, cs.shopcount);
        cout << "\n" << "CS edited\n";
    }
    else cout << "CS is not created\n";
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