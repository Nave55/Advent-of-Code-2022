#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include "tl/getlines.hpp"
#include "tl/to.hpp"

auto solution(const std::string &con, size_t window) -> int;

int main() {
    std::ifstream file ("C:/Users/navez/Cpp_Projects/AoC/Advent_2022_Files/Day6.txt");
    std::string line;
    file >> line;
    std::printf("Part 1: %d\nPart 2: %d\n", solution(line, 4), solution(line, 14));
}

auto solution(const std::string &line, size_t window) -> int {
    for (size_t i {0}; i < line.size() - window + 1; i++) {
        std::set<char> s {};
        for (size_t j {i}; j < i + window; j++) s.insert(line[j]);
        if (s.size() == window) return i + window;
    }
    return 0;   
}
