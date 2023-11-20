#include <bits/stdc++.h>

using namespace std;

void solution(const string &s, const char &del);

int main() {
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day1.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();

    solution(con,'\n');
}

void solution(const string &s, const char &del) {
    int sum {0};
    vector<int> vec {};
    stringstream ss {s};
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        if (word.length() > 0) sum += stoi(word);
        else {
            vec.push_back(sum);
            sum = 0;
        }
    }
    nth_element(vec.begin(), vec.begin() + 1, vec.end(), greater<int> {});
    cout << vec.at(0) << "\n" << vec.at(0) + vec.at(1) + vec.at(2) << "\n";
}
