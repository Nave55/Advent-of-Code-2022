#include <bits/stdc++.h>
#include "tools.h"

using namespace std;

int main() {
    string str;
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day7.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();

    struct Directory {string path; int size {0};};
    vector<Directory> dir;
    vector<string> tmp_dir;
    set<string> dir_names;
    stringstream ss {con};
    string word;

    while (!ss.eof()) {
        getline(ss, word, '\n');
        if (word[2] == 'c' && word[5] != '.') {
            tmp_dir.push_back(word.substr(3));
            dir_names.insert(strConcat(tmp_dir, '-'));         
        }
        else if (word[5] == '.') tmp_dir.pop_back();
        else if (isdigit(word[0])) {
            auto p = strConcat(tmp_dir, '-');
            auto s  = stoi(word.substr(0,word.find(' ')));
            dir.push_back(Directory{p, s});
        }
    }

    vector<int> ttl;
    for (auto i: dir_names) {
        int sum {0};
        for (auto j: dir) {
            if (j.path.find(i) < j.path.size()) sum += j.size;
        }
        ttl.push_back(sum);
    }
    
    int sum {0};
    sort(ttl.begin(), ttl.end());
    for (auto i: ttl) {
        if (i <= 100'000) sum += i;
        if (i >= (ttl.at(ttl.size() - 1) - 40'000'000)) {
            cout << "Part 1: " << sum << '\n' << "Part 2: " << i << endl;
            break;
        }
    }
}
