#include "pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "check.h"
using namespace std;

int Pipe::max_id = 0;

istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n Index of pipe: " << p.idp;

    cout << "Enter the length" << endl;
    p.lenght = getcorrectnumber(0.0, DBL_MAX);

    cout << "Enter the diameter" << endl;
    p.diameter = getcorrectnumber(0.0, DBL_MAX);

    cout << "Enter the status (1 - yes, 0 - no)\n"; // SSSSS
    p.status = getcorrectnumber(1, 0);
    cout << status_check(p.status);
    cout << "Pipe added";
    return in;
}

ostream& operator<< (ostream& out, Pipe& p) {
    out << "\nIndex of pipe: " << p.idp << "\nPipe info: " << "\nName: " << p.name << "\nLenght: "
        << p.lenght << "\nDiameter : " << p.diameter
        << "\nStatus: " << status_check(p.status) << endl;
    return out;
}