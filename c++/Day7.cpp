#include "tl/getlines.hpp"
#include "tl/to.hpp"
#include "tools.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
#include <set>


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
            dir.emplace_back(Directory{p, s});
        }
    }
        
    std::vector<int> ttl;
    for (auto i: dir_names) {
        int sum {0};
        for (auto j: dir) {
            if (j.path.find(i) < j.path.size()) sum += j.size;
        }
        ttl.push_back(sum);
    }

    auto filter1 = ttl | std::ranges::views::filter([](auto x) {return x <= 100'000;});
    auto filter2 = ttl | std::ranges::views::filter([ttl](auto x) {return x >= ttl[0] - 40'000'000;});

    auto pt1 = std::accumulate(filter1.begin(), filter1.end(), 0);
    auto pt2 = *std::ranges::min_element(filter2);

    std::cout <<"Part 1: " << pt1 << "\nPart 2: " << pt2 << std::endl;
}
