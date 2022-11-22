#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
using namespace std;

class CS
{

    public: static int max_idstation;
        CS() {
            idcs = max_idstation++;
        }
        string get_name() { return name; };
        int get_id() { return idcs; }
        double get_unused() { return (((double)workshop - (double)working_workshop) / (double)workshop) * 100; }
        string name = "";
        void edit_cs();
        void save_cs(ofstream& file);
        void load_cs(ifstream& file);

        friend istream& operator>> (istream& in, CS& p);
        friend ostream& operator<< (ostream& out, CS& cs);

    private:
        int  workshop, working_workshop, idcs;
        double effectiveness;


};

