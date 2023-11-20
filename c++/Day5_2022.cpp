#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;

void solution1(const string &instructions, vvc crates, const char &del);
void solution2(const string &instructions, vvc crates, const char &del);
void parsefile(vvc &crates, string &instructions);

int main() {
    string instructions;
    vvc crates {{}, {}, {}, {}, {}, {}, {}, {}, {}};

    parsefile(crates, instructions);
    solution1(instructions,crates,',');
    solution2(instructions,crates,',');
    
}

void parsefile(vvc &crates, string &instructions) {
    char tmp {' '};
    int cnt {0};
    string ign {"movefrt"}, tmpinstr, str_c;
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day5.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();

    for (auto i: con) {
        if (i == '1') break;
        if (i == tmp) cnt++;
        if (i != tmp) cnt = 0;
        if (i != '[' && i != ']' && i != ' ') str_c += i;
        if (cnt == 4) {
            str_c += '0';
            cnt = 0;
        }
    }

    cnt = 0;
    for (auto i: str_c) {
        if (cnt == 9) cnt = 0;
        if (i == '0') cnt ++;
        if (i != '\n' && i != '0') {
            crates.at(cnt).insert(crates.at(cnt).begin(),i);
            cnt++;
        }
    }

    tmpinstr = con.substr(con.find('m'), con.size());
    for (auto i: tmpinstr) {
    if (ign.find(i) > 6 && i != ' ' && i != '\n')  instructions += i;
    if (i == '\n') instructions+= ',';
    if (i == 'f' || i == 't') instructions += ',';
    }
}

void solution1(const string &instructions, vvc crates, const char &del) {
    int cnt {0}, one {0}, two {0}, three {0};
    stringstream ss {instructions};
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cnt += 1;
        if (cnt == 1) one = stoi(word);
        if (cnt == 2) two = stoi(word);
        if (cnt == 3) {
            cnt = 0;
            three = stoi(word);
            for (int i {0}; i < one; i++) {
                char popped = crates.at(two-1).back();
                crates.at(two-1).pop_back();
                crates.at(three-1).push_back(popped);
            }
        }
    }
    for (int i {0}; i < 9; i++) {
        cout << crates.at(i).back();
    }
    cout << '\n';
}

void solution2(const string &instructions, vvc crates, const char &del) {
    int cnt {0}, one {0}, two {0}, three {0};
    stringstream ss {instructions};
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cnt += 1;
        if (cnt == 1) one = stoi(word);
        if (cnt == 2) two = stoi(word);
        if (cnt == 3) {
            string popped_c; 
            cnt = 0;
            three = stoi(word);
            for (int i {0}; i < one; i++) {
                popped_c.insert(0,string(1,crates.at(two-1).back()));
                crates.at(two-1).pop_back();
            }
            for (int i {0}; i < one; i++) {
                crates.at(three-1).push_back(popped_c.at(i));
            }
        }
    }
    for (int i {0}; i < 9; i++) {
        cout << crates.at(i).back();
    }
    cout << '\n';
}
