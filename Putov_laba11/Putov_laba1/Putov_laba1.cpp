#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "check.h"
#include "pipe.h"
#include "cs.h"


void information(unordered_map<int, Pipe>& pipe_group, unordered_map<int, CS>& cs_group) {
    for (auto& pipe : pipe_group) {
        cout << pipe.second << endl;
    }
    for (auto& cs : cs_group) {
        cout << cs.second << endl;
    }
}



int count_not_null_pipe(unordered_map<int, Pipe> pipe_group, int size_) {
    int count = 0;
    for (int i = 0; i < size_; i++)
        if (pipe_group[i].get_length() != 0) count += 1;
    return count;
}

bool check_p_name(Pipe& p, string name) {
    return (p.name.find(name) != string::npos);
}
bool check_p_status(Pipe& p, bool status) {
    return (p.inWork == status);
}

bool check_cs_name(CS& cs, string name) {
    return (cs.name.find(name) != string::npos);
}

bool check_unworking(CS& cs, double p) {
    return (cs.get_unused() >= p);
}

vector<int> search_p(unordered_map <int, Pipe>& pipe_group) {
    vector<int> ids;
    int x;
    cout << "Search pipe by 1.name 2.status" << endl;
    x = correctnumber(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of pipe: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        ids = search_p_by_parametr(pipe_group, check_p_name, name);
    }
    else {
        bool k;
        cout << "Enter status of pipe (0 if repairing, 1 if in work): " << endl;
        k = correctnumber(0, 1);
        ids = search_p_by_parametr(pipe_group, check_p_status, k);
    }
    return ids;
}


void edit_pipe(unordered_map<int, Pipe>& pipe_group) {

    if (pipe_group.size() != 0) {

        int state = -1;
        cout << "1 - Editing all pipes \n2 - User-selected editing \n";
        cout << "Entder the number: ";
        state = correctnumber(1, 2);

        if (state == 2) {

            cout << "1.Choose pipe to edit" << endl;
            int id = correctnumber(0, (int)pipe_group.size());
            if (pipe_group.find(id) != pipe_group.end()) {
                pipe_group[id].edit_Pipe();
                cout << "Pipe was edited" << endl;
            }
            else
                cout << "There is no such pipe";
        }
        if (state == 1) {
            cout << "Choose pipes by 1.filter 2.id" << endl;
            int x = correctnumber(1, 2);
            if (x == 1) {
                auto idp = search_p(pipe_group);
                if (idp.size() != 0) {
                    cout << "Enter new status (0 if repairing, 1 if works)" << endl;
                    bool s;
                    s = correctnumber(0, 1);
                    for (auto& i : idp)
                        pipe_group[i].inWork = s;
                }

                else {
                    cout << "There is no such pipe";

                }
            }


            if (x == 2) {
                unordered_set <int> ids;
                cout << "Enter the number of identifiers of pipe you want to edit" << endl;
                int n;
                int id;
                n = correctnumber(1, (int)pipe_group.size());
                cout << "Enter idetifiers of pipes" << endl;
                for (int i = 0; ids.size() < n; i++) {
                    id = correctnumber(0, Pipe::max_idPipe - 1);
                    if (pipe_group.find(id) != pipe_group.end()) {
                        if (pipe_group.find(id) != pipe_group.end())
                            ids.insert(id);
                    }
                    else
                    {
                        cout << "There is no such pipe" << endl;;
                    }
                }
                cout << "Enter new status (0 if repairing, 1 if works)" << endl;
                bool s;
                s = correctnumber(0, 1);
                for (auto& i : ids) {
                    for (auto& i : ids)
                        pipe_group[i].inWork = s;
                }
            }

        }
    }

}



vector<int> search_cs(unordered_map <int, CS>& cs_group) {
    int x;
    vector <int> id;
    cout << "Search CS by 1.name 2.percentage of unused shops" << endl;
    x = correctnumber(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of CS: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = search_cs_by_parametr(cs_group, check_cs_name, name);

    }
    else {
        double k;
        cout << "Enter the percentage of unused shops" << endl;
        k = correctnumber(0, 100);
        id = search_cs_by_parametr(cs_group, check_unworking, k);
    }
    return id;
}


void editcs(unordered_map<int, CS>& cs_group) {
    vector <int> idcs;
    if (cs_group.size() != 0) {
        cout << "1.Edit one CS 2.Edit CSs 3.Delete CS" << endl;
        int state;
        int x;
        state = correctnumber(1, 3);
        if (state == 1) {
            int id;
            cout << cs_group;
            cout << "Choose CS to edit" << endl;
            id = correctnumber(0, (int)cs_group.size());
            if (cs_group.find(id) != cs_group.end()) {
                cs_group[id].edit_cs();
                cout << "CS was edited";
            }
        }
        if (state == 2) {
            unordered_set <int> ida;
            cout << "Choose  by 1.filter 2.id" << endl;
            int a;
            a = correctnumber(1, 2);
            if (a == 2) {

                cout << cs_group;
                cout << "Enter the number of cs you want to edit" << endl; //kol-vo
                int n;
                n = correctnumber(1, (int)cs_group.size());
                cout << "Enter idetifiers of CSs" << endl;
                for (int i = 0; ida.size() < n; i++) {
                    cin >> x;
                    if (cs_group.find(x) != cs_group.end())
                        ida.insert(x);
                    else {

                        cout << "There is no such cs" << endl;
                    }
                }
                for (auto& id : ida)

                    cs_group[id].edit_cs();
            }

            else {
                auto idp = search_cs(cs_group);
                if (idp.size() != 0) {
                    for (auto& i : idp)
                        cs_group[i].edit_cs();
                }

                else {
                    cout << "There is no such CS";

                }
            }
        }

    }
}


int main()
{
    int option = -1;
    unordered_map<int, Pipe> pipe_group;
    unordered_map<int, CS> cs_group;
    while (option) {
        cout << "\nChoose option:\n 1.Add pipe 2.Add CS 3.View all objects " <<
            "4.Edit pipe 5.Edit CS 6.Save 7.Load 8.Search pipe 9.Search CS 0.Exit\n";
        option = correctnumber(0, 9);
        switch (option) {
        case 1:
        {
            system("cls");
            Pipe p;
            cin >> p;
            system("pause");
            system("cls");
            pipe_group.insert({ p.get_idPipe(), p });
            break;
        }
        case 2:
        {
            system("cls");
            CS cs;
            cin >> cs;
            system("pause");
            system("cls");
            cs_group.insert({ cs.get_id(), cs });
            break;
        }
        case 3: {
            system("cls");
            information(pipe_group, cs_group); //VIEWALLOBJECT
        }
            break;

        case 4:
            
            edit_pipe(pipe_group);
         
            break;

        case 5:

            break;
        }
    }
}
