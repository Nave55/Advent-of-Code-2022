#include <bits/stdc++.h>

int main() {
    std::vector<int> vec;
    std::ifstream myfile ("C:/Users/navez/Cpp_Projects/AoC/Advent_2022_Files/Day1.txt");
    if (myfile.is_open()) {
        std::string line;
        int ttl {0};
        while (std::getline(myfile, line)) {
            if (line != "") ttl += std::stoi(line);
            else {
                vec.push_back(std::move(ttl));
                ttl = 0;
            }
        }
        myfile.close();
    } 
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end(), std::greater<int> {});
    auto part1 = vec.at(0);
    auto part2 = std::accumulate(vec.begin(), vec.begin() + 3, 0, [](int a, int b) {return a + b;});
    printf("Part 1: %d\nPart 2: %d", part1, part2);
}
