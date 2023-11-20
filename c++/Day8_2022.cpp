#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void solution1(const string &rows, const string & columns, const char &del, const int &len);
void parsefile(string &rows, string &columns, int &len);

int main() {
    string rows, columns;
    int len {1};
    parsefile(rows, columns, len);
    solution1(rows, columns, '\n', len);
}

void parsefile(string &rows, string &columns, int &len) {
    ifstream myfile ("C:/Users/navez/Anaconda Proj/C++ Projects/AoC/Advent_2022_Files/Day8.txt");
    stringstream instream;
    instream << myfile.rdbuf(); 
    string con = instream.str();
    myfile.close();
    for (auto i: con) {
        rows += i;
        if (i == '\n') ++len;
    }

    for (int i {0}; i < len; ++i) {
        if (i != 0) columns += '\n';
        stringstream ss {con};
        string word;
        while (!ss.eof()) {
            getline(ss, word,'\n');
            columns += word[i];
        }
    }
}

void solution1(const string &rows, const string & columns, const char &del, const int &len) {
    vvi matrix; 
    for (int i {0}; i < len; ++i) {
        vi tmp_mat {};
        for (int j {0}; j < len; ++j) {
            tmp_mat.emplace_back(1);
        }
        matrix.emplace_back(tmp_mat);
    }
    auto matrix2 {matrix};

    stringstream ss {rows}, ss_c {columns};
    string word, word_c;
    int cnt {0};

    while (!ss.eof()) {
        getline(ss, word, del);
        auto r_word {word};
        reverse(r_word.begin(), r_word.end());
        getline(ss_c, word_c, del);
        auto r_word_c {word_c};
        reverse(r_word_c.begin(), r_word_c.end());
        int pos {len - 2};

        for (int j {1}; j < len - 1; ++j) {
            bool visible {false}, visible_r {false}, visible_c {false}, visible_c_r {false};
            bool broke {false}, broke_r {false}, broke_c {false}, broke_c_r {false};
            int final_pos {0}, final_pos_r {0}, final_pos_c {0}, final_pos_c_r {0};
            for (int i {j+1}; i < len; ++i) {
                if (cnt == 0 || cnt == len - 1) break;

                if (stoi(string(1,word[j])) > (stoi(string(1,word[i])))) {
                    visible = true;
                    if (! broke) final_pos = i - j;
                }
                else {
                    if (! broke) final_pos = i - j;
                    broke  = true;
                    visible = false;
                }

                if (stoi(string(1,r_word[j])) > (stoi(string(1,r_word[i])))) {
                    visible_r = true;
                    if (! broke_r) final_pos_r = i - j;
                }
                else {
                    if (! broke_r) final_pos_r = i - j;
                    broke_r = true;
                    visible_r = false;
                }  

                if (stoi(string(1,word_c[j])) > (stoi(string(1,word_c[i])))) {
                    visible_c = true;
                    if (! broke_c) final_pos_c = i - j;
                }
                else {
                    if (! broke_c) final_pos_c = i - j;
                    broke_c = true;
                    visible_c = false;
                }   

                if (stoi(string(1,r_word_c[j])) > (stoi(string(1,r_word_c[i])))) {
                    visible_c_r = true;
                    if (! broke_c_r) final_pos_c_r = i - j;
                }
                else {
                    if (! broke_c_r) final_pos_c_r = i - j;
                    broke_c_r = true;
                    visible_c_r = false;
                }   
            }
            matrix2[cnt][j] *= final_pos;
            matrix2[cnt][pos] *= final_pos_r;
            matrix2[j][cnt] *= final_pos_c;
            matrix2[pos][cnt] *= final_pos_c_r;
            if (visible && ! broke) matrix[cnt][j] += 1;
            if (visible_r && ! broke_r) matrix[cnt][pos] += 1;
            if (visible_c && ! broke_c) matrix[j][cnt] += 1;
            if (visible_c_r && ! broke_c_r) matrix[pos][cnt] += 1;
            --pos;
        }
        ++cnt;
    }

    int ttl {0};
    for (auto i: matrix) {
        for (auto j: i) {
            if (j > 1) ++ttl;
        }
    }

    int best {0};
    for (auto i: matrix2) {
        for (auto j: i) {
            if (j >= best) best = j;
        }
    }

    cout << "Part 1: " << ttl + len * 4  - 4 << '\n' << "Part 2: " << best << '\n';
}
