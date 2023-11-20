#include <bits/stdc++.h>

using namespace std;

void solution1(const string &s, const char &del);
void solution2(const string &s, const char &del);

int main() {
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day3.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();

    solution1(con,'\n');
    solution2(con,'\n');
}

void solution1(const string &s, const char &del) {
    int sum {0};
    map<char, int> mp;
    for (size_t i {0}; i < 26; i++) {
        char letter = 97 + i;
        char letter_u = 65 + i;
        mp.insert(pair<char,int>(letter,i+1));
        mp.insert(pair<char,int>(letter_u,i+27));
    }

    stringstream ss {s};
    string word;
    while (!ss.eof()) {
        string v_intersection;
        getline(ss, word, del);
        string substr1 = word.substr(0,word.length()/2);
        string substr2 = word.substr(word.length()/2,word.length());
        sort(substr1.begin(), substr1.end());
        sort(substr2.begin(), substr2.end());
        set_intersection(substr1.begin(), substr1.end(), substr2.begin(), substr2.end(), back_inserter(v_intersection));
        sum += mp[v_intersection.at(0)];
    }
    cout << sum << "\n";
}

void solution2(const string &s, const char &del) {
    int sum {0}, cnt {1};
    vector<string> vec {};
    map<char, int> mp;
    for (size_t i {0}; i < 26; i++) {
        char letter = 97 + i;
        char letter_u = 65 + i;
        mp.insert(pair<char,int>(letter,i+1));
        mp.insert(pair<char,int>(letter_u,i+27));
    }

    stringstream ss {s};
    string word;
    while (!ss.eof()) {
        string v_intersection, v_intersection2;
        getline(ss, word, del);
        vec.push_back(word);
        if (cnt % 3 == 0) {
            string substr1 {vec.at(cnt-3)};
            string substr2 {vec.at(cnt-2)}; 
            string substr3 {vec.at(cnt-1)};
            sort(substr1.begin(), substr1.end());
            sort(substr2.begin(), substr2.end());
            sort(substr3.begin(), substr3.end());
            set_intersection(substr1.begin(), substr1.end(), substr2.begin(), substr2.end(), back_inserter(v_intersection));
            set_intersection(v_intersection.begin(), v_intersection.end(), substr3.begin(), substr3.end(), back_inserter(v_intersection2));
            sum += mp[v_intersection2.at(0)];
        }
        cnt++;
    }
    cout << sum << "\n";
}
