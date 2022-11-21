#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Pipe
{
private:
    int idPipe;
    float length;
    float diameter;

public:

    string name = "";
    bool inWork;
    static int max_idPipe;

    Pipe() {
        idPipe = max_idPipe++;
    }

    int get_idPipe() { return idPipe; };
    float get_length() { return length; };
    // float get_diameter() { return diameter; };
     //bool get_inWork() { return inWork; };
    void edit_Pipe();


    friend istream& operator>> (istream& in, Pipe& p);
    friend ostream& operator<< (ostream& out, Pipe& p);

};

