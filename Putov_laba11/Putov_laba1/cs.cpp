#include "cs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "check.h"

using namespace std;
int CS::max_idstation = 0;

istream& operator>> (istream& in, CS& cs)
{
    cout << "\nIndex of cs: " << cs.idcs;
    cout << "\nInput name ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, cs.name);
    cout << "\nNumber of workshops ";
    cs.workshop = correctnumber(0, INT_MAX);
    cout << "\nNumber of working workshops ";
    cs.working_workshop = correctnumber(0, cs.workshop);
    cout << "\nEnter the effectiveness ";
    cs.effectiveness = correctnumber(0, 100);
    return in;
}
ostream& operator<< (ostream& out, CS& cs) {
    out << "\nIndex of CS: " << cs.idcs << "\nCS info:\nName: " << cs.name << "\nNumber of workshops: " << cs.workshop
        << "\nNumber of working workshops: " << cs.working_workshop << "\nEffectiveness: "
        << cs.effectiveness << "%" << endl;
    return out;
}


