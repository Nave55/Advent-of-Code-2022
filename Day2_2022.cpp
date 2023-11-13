#include <bits/stdc++.h>

using namespace std;

void solution(const string &s, const char &del);

int main() {
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day2.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();
    solution(con,'\n');
}

void solution(const string &s, const char &del) {
    int sum {0}, sum2 {0};
    map<string, int> mp;
    map<string, string> mp2;

    mp["AX"] = 4; mp["AY"] = 8; mp["AZ"] = 3;
    mp["BX"] = 1; mp["BY"] = 5; mp["BZ"] = 9;
    mp["CX"] = 7; mp["CY"] = 2; mp["CZ"] = 6;

    mp2["AX"] = "AZ"; mp2["AY"] = "AX"; mp2["AZ"] = "AY";
    mp2["BX"] = "BX"; mp2["BY"] = "BY"; mp2["BZ"] = "BZ";
    mp2["CX"] = "CY"; mp2["CY"] = "CZ"; mp2["CZ"] = "CX";

    stringstream ss {s};
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        sum += mp.at(word.replace(1,1,""));
        sum2 += mp.at(mp2.at(word));
    }
    cout << sum << "\n" << sum2 << "\n";
}