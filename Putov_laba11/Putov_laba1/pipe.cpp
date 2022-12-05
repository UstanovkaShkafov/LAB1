#include "Pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "check.h"
using namespace std;



string status_check(bool x)
{
    if (x == true)
        return ("Pipe works");
    else if (x == false)
        return ("Pipe is repairing");
}


int Pipe::max_idPipe = 0;

istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n Index of pipe: " << p.idPipe;
    cout << "\nInput name ";

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    getline(cin, p.name);
    cout << "\nInput lenght ";
    p.length = getcorrectnumber(0.1, DBL_MAX);
    cout << "\nInput diameter ";
    p.diameter = getcorrectnumber(0.1, DBL_MAX);
    cout << "\nChoose status of pipe (0 if repairing, 1 if works) ";
    p.inWork = getcorrectnumber(0, 1);
    cout << status_check(p.inWork) << endl;
    return in;
}

ostream& operator<< (ostream& out, Pipe& p) {
    out << "\nIndex of pipe: " << p.idPipe << "\nPipe info: " << "\nName: " << p.name << "\nLenght: "
        << p.length << "\nDiameter : " << p.diameter
        << "\nStatus: " << status_check(p.inWork) << endl;
    return out;
}

bool is_there_idPipe(unordered_map<int, Pipe> pipe_group, int id, int size_) {
    for (int i = 0; i < size_; i++)
        if (pipe_group[i].get_idPipe() == id && pipe_group[i].get_length() != 0) return true;
    return false;
}


void Pipe::edit_Pipe() {
    cout << "Status: " << status_check(inWork) << endl;
    cout << "Enter new status of pipe (0 if in repairing, 1 if works)" << endl;
    inWork = getcorrectnumber(0, 1);
    cout << status_check(inWork) << endl;;

}
void Pipe::load_pipe(ifstream& file) {
    file >> idPipe;
    getline(file, name);
    getline(file, name);
    file >> length;
    file >> diameter;
    file >> inWork;
}



