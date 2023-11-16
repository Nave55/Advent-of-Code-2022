#include <bits/stdc++.h>

using namespace std;

void solution(const string &con, const char &del);
string parsefile(const char &del);

int main() {
    string con = parsefile('\n');
    solution(con,'\n');
}

string parsefile(const char &del) {
    string str;
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day7.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();
    stringstream ss {con};
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        if (word.find('$') == 0) word.replace(0,2,"");
        if (word != "ls" && word[0] != 'd' && ! isdigit(word[0])) str += word += '\n';
        if (isdigit(word[0])) str += word.substr(0,word.find(' ')) += '\n';
    }
    return str;

}

void solution(const string &con, const char &del) {
    vector<vector<string>> dir;
    vector<string> tmp_dir;
    set<string> dir_names;
    stringstream ss {con};
    string word;

    while (!ss.eof()) {
        getline(ss, word, del);
        if (word[0] == 'c' && word[3] != '.') {
            string rnd = to_string(rand() % 20000);
            tmp_dir.emplace_back(rnd);
            dir_names.insert(rnd);
        }
        if (word[3] == '.') tmp_dir.pop_back();
        if (isdigit(word[0])) {
            dir.emplace_back(tmp_dir);
            dir.at(dir.size()-1).push_back(word);
        }
    }

    int sum {0};
    vector<int> ttl;
    for (auto i: dir_names) {
        for (auto j: dir) {
            if (find(j.begin(),j.end(),i) != j.end()) {
                sum += stoi(j.at(j.size() - 1));
            }
            else {
                if (sum > 0) {
                    ttl.emplace_back(sum);
                    sum = 0;
                }
            }
        }
    }

    sum = 0;
    for (auto i: ttl) {
        if (i <= 100000) sum += i;
    }
    cout << sum << '\n';

    sort(ttl.begin(), ttl.end());
    
    for (auto i: ttl) {
        if (i >= (ttl.at(ttl.size() - 1) - 40000000)) {
            cout << i << '\n';
            break;
        }
    }

}
