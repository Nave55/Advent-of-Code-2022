#include <bits/stdc++.h>

using namespace std;

string parsefile();
int solution(string con, const size_t &window);

int main() {
    string con = parsefile();
    cout << solution(con, 4) << '\n';
    cout << solution(con, 14) << '\n'; 
}

string parsefile() {
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day6.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();
    return con;
}

int solution(string con, const size_t &window) {
    set<char> s {};
    size_t cnt {window}, i {0};
    
    while (con.size() >= window) {
        s.insert(con[i]);
        if (i == window - 1) {
            if (s.size() == window) return cnt;
            s.clear();
            con.erase(0,1);
            i = -1;
            ++cnt;
        }
        ++i;
    }
    return 0;
}