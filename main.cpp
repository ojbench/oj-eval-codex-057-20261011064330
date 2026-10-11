#include <bits/stdc++.h>

using namespace std;

struct Student {
    string id;
    string name;
    int score;
    int order; // insertion order for stable sorting
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students; // stored in insertion order
    unordered_map<string, size_t> id_index; // map id -> position in students vector
    unordered_map<string, size_t> name_index; // map name -> position
    string line;
    int cmd;
    while (cin >> cmd) {
        if (cmd == 1) { // add student
            string sid, sname;
            int sscore;
            cin >> sid >> sname >> sscore;
            if (id_index.find(sid) != id_index.end()) {
                cout << "FAILED\n";
            } else {
                Student st{sid, sname, sscore, (int)students.size()};
                students.push_back(st);
                size_t pos = students.size() - 1;
                id_index[sid] = pos;
                name_index[sname] = pos;
                cout << "SUCCESS\n";
            }
        } else if (cmd == 2) { // display all
            for (const auto &st : students) {
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 3) { // query by id
            string sid; cin >> sid;
            size_t pos = id_index.at(sid);
            const auto &st = students[pos];
            cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
        } else if (cmd == 4) { // query by name
            string sname; cin >> sname;
            size_t pos = name_index.at(sname);
            const auto &st = students[pos];
            cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
        } else if (cmd == 5) { // sort by id ascending
            stable_sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
                return a.id < b.id;
            });
            // rebuild indexes after sorting
            id_index.clear();
            name_index.clear();
            for (size_t i = 0; i < students.size(); ++i) {
                id_index[students[i].id] = i;
                name_index[students[i].name] = i;
            }
            for (const auto &st : students) {
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 6) { // sort by score descending, stable for equal scores
            stable_sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
                return a.score > b.score;
            });
            // rebuild indexes after sorting
            id_index.clear();
            name_index.clear();
            for (size_t i = 0; i < students.size(); ++i) {
                id_index[students[i].id] = i;
                name_index[students[i].name] = i;
            }
            for (const auto &st : students) {
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 7) { // exit
            cout << "END\n";
            break;
        }
    }
    return 0;
}

