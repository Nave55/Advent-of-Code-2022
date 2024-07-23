#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include "tl/getlines.hpp"
#include "tl/to.hpp"

int solution(const std::string &con, size_t window);

int main() {
    std::ifstream file ("C:/Users/navez/Cpp_Projects/AoC/Advent_2022_Files/Day6.txt");
    auto lines = tl::views::getlines(file) | tl::to<std::vector<std::string>>();
    std::cout << solution(lines[0], 4) << std::endl;
    std::cout << solution(lines[0], 14) << std::endl; 
}

int solution(const std::string &lines, size_t window) {
    for (size_t i {0}; i < lines.size() - window + 1; i++) {
        std::set<char> s {};
        for (size_t j {i}; j < i + window; j++) s.insert(lines[j]);
        if (s.size() == window) return i + window;
    }
    return 0;   
}
