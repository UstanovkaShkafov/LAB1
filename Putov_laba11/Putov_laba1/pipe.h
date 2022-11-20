#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"
#include "cs.h"

using namespace std;

class Pipe
{
	public:
        static int max_id;
        string name = "";
        bool status = 0;
        Pipe() {
            idp = max_id++;
        }

        friend istream& operator>> (istream& in, Pipe& p);
        friend ostream& operator<< (ostream& out, Pipe& p);
        int get_id() { return idp; }

    private:
        double lenght = 0, diameter = 0;
        int idp = 0;
};