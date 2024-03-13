#include "tl/getlines.hpp"
#include "tl/to.hpp"
#include <bits/stdc++.h>
#include "tools.h"

int main() {
    std::ifstream file("C:/Users/navez/Cpp_Projects/AoC/Advent_2022_Files/Day7.txt");
    auto lines = tl::views::getlines(file) | tl::to<std::vector>();

    struct Directory {std::string path; int size {0};};
    std::vector<Directory> dir;
    std::vector<std::string> tmp_dir;
    std::set<std::string> dir_names;

    for (auto word: lines) {
        if (word[2] == 'c' && word[5] != '.') {
            tmp_dir.push_back(std::move(word.substr(5)));
            dir_names.insert(join(tmp_dir, '-'));         
        }
        else if (word[5] == '.') tmp_dir.pop_back();
        else if (isdigit(word[0])) {
            auto p = join(tmp_dir, '-');
            auto s  = std::stoi(word.substr(0,word.find(' ')));
            dir.push_back(Directory{std::move(p), std::move(s)});
        }
    }
        
    std::vector<int> ttl;
    for (auto i: dir_names) {
        int sum {0};
        for (auto j: dir) {
            if (j.path.find(i) < j.path.size()) sum += j.size;
        }
        ttl.push_back(std::move(sum));
    }

    auto filter1 = ttl | std::ranges::views::filter([](auto x) {return x <= 100'000;});
    auto filter2 = ttl | std::ranges::views::filter([ttl](auto x) {return x >= ttl[0] - 40'000'000;})
                       | tl::to<std::vector>();

    auto pt1 = std::accumulate(filter1.begin(), filter1.end(), 0);
    auto pt2 = minVal(filter2);

    printf("Part 1: %d\nPart 2: %d", pt1, pt2);
}
