#include <bits/stdc++.h>

using namespace std;

void solution(const string &s, const char &del);

int main() {
    string str;
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day4.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();

    for (auto i: con) {
        if (i == '-' || i == '\n') str += ',';
        else str += i;
    }

    solution(str,',');
}

void solution(const string &s, const char &del) {
    int sum {0}, sum2 {0};
    vector<int> vec {};
    
    stringstream ss {s};
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        vec.push_back(stoi(word));
        if (vec.size() == 4) {
            if ((vec.at(0) >= vec.at(2) && vec.at(1) <= vec.at(3)) || 
            (vec.at(2) >= vec.at(0) && vec.at(3) <= vec.at(1))) sum++;

            if ((vec.at(0) >= vec.at(2) && vec.at(0) <= vec.at(3)) || 
            (vec.at(1) >= vec.at(2) && vec.at(1) <= vec.at(3)) || 
            (vec.at(2) >= vec.at(0) && vec.at(2) <= vec.at(1)) || 
            (vec.at(3) >= vec.at(1) && vec.at(3) <= vec.at(0))) sum2++;

            vec.clear();
        }
    }
    cout << sum << "\n" << sum2 << "\n";
}
