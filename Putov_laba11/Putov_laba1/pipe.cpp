#include "pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "checking.h"
using namespace std;

istream& operator>> (istream& in, Pipe& p)
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