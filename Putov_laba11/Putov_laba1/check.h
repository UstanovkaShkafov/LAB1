#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"

using namespace std;
template <typename T>
T getcorrectnumber(T min, T max) {
    T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < min) || (x > max)) {
        cout << "Error!!! Input numeric value >= " << min << " and =< " << max << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return x;
}

template <typename T>
ostream& operator<< (ostream& out, unordered_map <int, T>& p) {
    out << "Exiting id: ";
    for (auto& [i, obj] : p) {
        out << i << " ";
    }

    out << endl;
    return out;
}





template <typename T>
using filter_p = bool (*) (Pipe& p, T par);


template <typename T>
vector <int> search_p_by_parametr(unordered_map <int, Pipe>& pipe_group, filter_p<T> f, T par) {
    vector <int> idPipe;
    for (auto& pipe : pipe_group) {
        if (f(pipe.second, par))
            idPipe.push_back(pipe.second.get_idPipe());
    }
    return idPipe;
}


