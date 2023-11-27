#include <bits/stdc++.h>

using namespace std;

void solution(const string &con, const char &del);
string parsefile(const char &del);

template <typename T>
T strConcat(const vector<T> &arr);

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
    struct Directory {
        string path;
        int size {0};
    };
    vector<Directory> dir;
    vector<string> tmp_dir;
    set<string> dir_names;
    stringstream ss {con};
    string word;

    while (!ss.eof()) {
        getline(ss, word, del);
        if (word[0] == 'c' && word[3] != '.') {
            tmp_dir.emplace_back(word.substr(3));
            auto str = strConcat(tmp_dir);
            dir_names.insert(str);         
        }
        if (word[3] == '.') tmp_dir.pop_back();
        if (isdigit(word[0])) {
            auto num = stoi(word.substr(0,word.find(' ')));
            auto str = strConcat(tmp_dir);
            dir.emplace_back(Directory{str, num});
        }
    }
    
    int sum {0};
    vector<int> ttl;
    for (auto i: dir_names) {
        for (auto j: dir) {
            if (j.path.find(i) < j.path.size()) {
                sum += j.size;
            }   
        }
        if (sum > 0) {
            ttl.emplace_back(sum);
            sum = 0;
        }
    }

    sort(ttl.begin(), ttl.end());
    for (auto i: ttl) {
        if (i <= 100000) sum += i;
        if (i >= (ttl.at(ttl.size() - 1) - 40000000)) {
            cout << "Part 1: " << sum << '\n' << "Part 2: " << i << endl;
            break;
        }
    }
}

template <typename T>
T strConcat(const vector<T> &arr) {
    string str {""};
    for (size_t i {0}; i < arr.size(); ++i) {
        if (i < arr.size() - 1) {
            str += arr.at(i);
            str += "-";
        }
        else str += arr.at(i);
    }
    return str;
}
