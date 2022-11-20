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

class CS
{
public: static int max_idd;
      CS() {
          idcs = max_idd++;
      }
      friend istream& operator>> (istream& in, CS& p);
      friend ostream& operator<< (ostream& out, CS& cs);
      string name = "";
      int get_id() { return idcs; }
      //void save_cs(ofstream& file);
      //void edit_cs();
      //void load_cs(ifstream& file);
 
      //double get_unused() { return (((double)workshop - (double)working_workshop) / (double)workshop) * 100; }


private:
    int  workshop, working_workshop, idcs;
    double effectiveness;
    
};