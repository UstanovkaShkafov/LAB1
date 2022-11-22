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


void viewallobject(unordered_map<int, Pipe>& pipe_group, unordered_map<int, CS>& cs_group) {
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
    cout << "Search pipe by 1. Name 2. Working status" << endl;
    x = getcorrectnumber(1, 2);
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
        cout << "Enter status of pipe (0 - repairing ; 1 - in work): " << endl;
        k = getcorrectnumber(0, 1);
        ids = search_p_by_parametr(pipe_group, check_p_status, k);
    }
    return ids;
}


void edit_pipe(unordered_map<int, Pipe>& pGroup) {

    if (pGroup.size() != 0) {

        int state = -1;
        cout << "1 - Editing all pipes \n2 - User-selected editing \n";
        cout << "Enter the number: ";
        state = getcorrectnumber(1, 2);

        if (state == 2) {

            cout << "1.Choose pipe to edit" << endl;
            int id = getcorrectnumber(0, (int)pGroup.size());
            if (pGroup.find(id) != pGroup.end()) {
                pGroup[id].edit_Pipe();
                cout << "Pipe was edited" << endl;
            }
            else
                cout << "There is no such pipe";
        }
        if (state == 1) {
            cout << "Choose pipes by 1.filter 2.id" << endl;
            int x = getcorrectnumber(1, 2);

            if (x == 1) {
                auto idp = search_p(pGroup);
                if (idp.size() != 0) {
                    cout << "Enter new status (0 - repairing ; 1 - works)" << endl;
                    bool s;
                    s = getcorrectnumber(0, 1);
                    for (auto& i : idp)
                        pGroup[i].inWork = s;
                }

                else {
                    cout << "There is no such pipe";

                }
            }
            if (x == 2) {
                unordered_set <int> ids;
                cout << "Enter the number of pipes to edit" << endl;
                int n;
                int id;
                n = getcorrectnumber(1, (int)pGroup.size());
                cout << "Enter pipe IDs" << endl;
                for (int i = 0; ids.size() < n; i++) {
                    id = getcorrectnumber(0, Pipe::max_idPipe - 1);
                    if (pGroup.find(id) != pGroup.end()) {
                        if (pGroup.find(id) != pGroup.end())
                            ids.insert(id);
                    }
                    else
                    {
                        cout << "There is no such pipe" << endl;;
                    }
                }
                cout << "Enter new status (0 - repairing ; 1 - works)" << endl;
                bool s;
                s = getcorrectnumber(0, 1);
                for (auto& i : ids) {
                    for (auto& i : ids)
                        pGroup[i].inWork = s;
                }
            }

        }
    }

}


template <typename T>
using filter_cs = bool(*) (CS& cs, T par);
template <typename T>
vector <int> search_cs_by_parametr(unordered_map <int, CS>& cs_group, filter_cs<T> f, T par) {
    vector <int> id;
    for (auto& cs : cs_group) {
        if (f(cs.second, par))
            id.push_back(cs.second.get_id());
    }
    return id;
}

vector<int> search_cs(unordered_map <int, CS>& cs_group) {
    int x;
    vector <int> id;
    cout << "Search CS by 1.name 2.percentage of unused shops" << endl;
    x = getcorrectnumber(1, 2);
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
        k = getcorrectnumber(0, 100);
        id = search_cs_by_parametr(cs_group, check_unworking, k);
    }
    return id;
}


void edit_cs(unordered_map<int, CS>& cs_group) {
    vector <int> idcs;
    if (cs_group.size() != 0) {
        cout << "1.Edit one CS 2.Edit CSs" << endl;
        int state;
        int x;
        state = getcorrectnumber(1, 3);
        if (state == 1) {
            int id;
            cout << cs_group;
            cout << "Choose CS to edit" << endl;
            id = getcorrectnumber(0, (int)cs_group.size());
            if (cs_group.find(id) != cs_group.end()) {
                cs_group[id].edit_cs();
                cout << "CS was edited";
            }
        }
        if (state == 2) {
            unordered_set <int> ida;
            cout << "Choose  by 1.filter 2.id" << endl;
            int a;
            a = getcorrectnumber(1, 2);
            if (a == 2) {

                cout << cs_group;
                cout << "Enter the number of cs you want to edit" << endl; //kol-vo
                int n;
                n = getcorrectnumber(1, (int)cs_group.size());
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

void Pipe::save_pipe(ofstream& file) {
    file << idPipe << endl << name << endl << length << endl << diameter << endl << inWork << endl;
}

void CS::save_cs(ofstream& file) {
    file << idcs << endl << name << endl
        << workshop << endl << working_workshop << endl << effectiveness << endl;
}

void SaveToFile(unordered_map<int, Pipe>& pGroup, unordered_map<int, CS>& cGroup) {
    ofstream file;
    string name;
    cout << "Enter the file name to save " << endl;
    cin >> name;
    file.open(name + ".txt");
    if (!file)
        cout << "Error" << endl;
    else {
        file << pGroup.size() << endl;
        for (auto pipe : pGroup)
            pipe.second.save_pipe(file);

        file << cGroup.size() << endl;
        for (auto cs : cGroup)
            cs.second.save_cs(file);
    }
}

void Pipe::load_pipe(ifstream& file) {
    file >> idPipe;
    getline(file, name);
    file >> length;
    file >> diameter;
    file >> inWork;
}

void CS::load_cs(ifstream& file) {
    file >> idcs;
    getline(file, name);
    getline(file, name);
    file >> workshop;
    file >> working_workshop;
    file >> effectiveness;
}

void DownloadFromFile(unordered_map<int, Pipe>& pGroup, unordered_map<int, CS>& cGroup) {
    string x;
    int len1, len2;
    Pipe newP;
    CS newCS;
    cout << "Enter the name of file  " << endl;
    cin >> x;
    ifstream file;
    file.open(x + ".txt");
    if (!file)
        cout << "There is no such file";
    else {
        Pipe::max_idPipe = 0;
        CS::max_idstation = 0;
        pGroup.clear();
        cGroup.clear();
        file >> len1 >> len2;
        for (int i = 0; i < len1; i++) {
            newP.load_pipe(file);
            pGroup.insert({ newP.get_idPipe(),newP });
            if (Pipe::max_idPipe <= newP.get_idPipe())
                Pipe::max_idPipe = newP.get_idPipe() + 1;

        }
        for (int i = 0; i < len2; i++) {
            newCS.load_cs(file);
            cGroup.insert({ newCS.get_id(),newCS });
            if (CS::max_idstation <= newCS.get_id())
                CS::max_idstation = newCS.get_id() + 1;

        }
    }
}

void DelPipe(unordered_map<int, Pipe> pGroup) {
    cout << "1. Remove one pipe 2.Remove some pipes" << endl;
    int Remove;
    Remove = getcorrectnumber(1, 2);
    if (Remove == 1) {
        cout << pGroup;
        cout << "Enter id of pipe you want to delete" << endl;
        int n;
        n = getcorrectnumber(0, Pipe::max_idPipe - 1);
        while (pGroup.find(n) == pGroup.end()) {
            cout << "There is no such pipe" << endl;
            n = getcorrectnumber(0, Pipe::max_idPipe - 1);
        }
        pGroup.erase(pGroup.find(n));
    }
    else {
        unordered_set <int> ids;
        cout << "1.Delete by filter 2.Delete by id" << endl;
        int DelBy = getcorrectnumber(1, 2);
        if (DelBy == 2) {
            cout << pGroup;
            cout << "Enter the number of pipes to edit" << endl;;
            int n = getcorrectnumber(1, (int)pGroup.size());
            cout << "Enter idetifiers of pipes" << endl;

            while (ids.size() < n)
            {
                int x = getcorrectnumber(0, Pipe::max_idPipe - 1);
                if (pGroup.find(x) != pGroup.end())
                    ids.insert(x);
                else
                    cout << "There is no such pipe" << endl;
            }
            for (auto& id : ids) {
                pGroup.erase(pGroup.find(id));
            }
        }

        else {
            auto idp = search_p(pGroup);
            if (idp.size() != 0) {
                for (auto& i : idp) {
                    pGroup.erase(pGroup.find(i));
                }
                cout << "Pipe was deleted";
            }
            else {
                cout << "There is no such pipe";
            }
        }
    }
}


void selectPipesByFilter(unordered_map<int, Pipe> pGroup) {
    if (pGroup.size() != 0) {
        auto x = search_p(pGroup);
        if (x.size() != 0) {
            for (auto& i : x)
                cout << pGroup[i] << endl;
        }
        else
            cout << "There is no such pipe" << endl;
    }
    else
        cout << "There is no pipe to find" << endl;
    
}



int main()
{
    int option = -1;
    unordered_map<int, Pipe> YourPipes;
    unordered_map<int, CS> YourCS;
    while (option) {
        cout << "\nChoose option:\n 1.Add pipe 2.Add CS 3.View all objects " << "4.Edit pipe 5.Edit CS 6.Save 7.Load 8.Search pipe 9.Search CS 10. Remove the pipe 11. Delete cs \n 0.Exit\n";
        option = getcorrectnumber(0, 9);
        switch (option) {
        case 1:
        {
            system("cls");
            Pipe p;
            cin >> p;
            system("pause");
            system("cls");
            YourPipes.insert({ p.get_idPipe(), p });
            break;
        }
        case 2:
        {
            system("cls");
            CS cs;
            cin >> cs;
            system("pause");
            system("cls");
            YourCS.insert({ cs.get_id(), cs });
            break;
        }
        case 3: {
            system("cls");
            viewallobject(YourPipes, YourCS); //VIEWALLOBJECT 
        }
            break;

        case 4:
            
            edit_pipe(YourPipes);
         
            break;

        case 5:
            
            edit_cs(YourCS);

            break;

        case 6: 
            SaveToFile(YourPipes, YourCS);
            cout << "File saved";
            system("pause");
            break;

        case 7:
            DownloadFromFile(YourPipes, YourCS);
            system("pause");
            break;

        case 8:
            selectPipesByFilter(YourPipes);
            break;

        case 9:

            break;

        case 10:
            DelPipe(YourPipes);
            system("pause");
            break;

        case 11:

            break;
        }

       
    }
}
