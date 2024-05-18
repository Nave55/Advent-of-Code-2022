#ifndef _tools_h_
#define _tools_h_

#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <ostream>

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &arr) {
    os << "[";
    for (size_t i {0}; i < arr.size(); ++i) {
        os << arr[i];
        if (i < arr.size() - 1) {
            os << ",";
        }
    }
    os << "]\n";
    return os;
}

template <typename T>
T join(const std::vector<T> &arr, const char &delim = ',') {
    std::string str {""};
    for (size_t i {0}; i < arr.size(); ++i) {
        if (i < arr.size() - 1) {
            str += arr.at(i);
            str += delim;
        }
        else str += arr.at(i);
    }
    return str;
}

template <typename T>
float avgVal(const std::vector<T> &arr) {
    if (arr.size() != 0)
        return (float) std::accumulate(arr.begin(), arr.end(), 0) / arr.size();
    return 0;
}

template <typename T>
T minVal(const std::vector<T> &arr) {
    if (arr.size() != 0) 
        return *std::ranges::min_element(arr);
    return 0;
}

template <typename T>
T maxVal(const std::vector<T> &arr) {
    if (arr.size() != 0) 
        return *std::ranges::max_element(arr);
    return 0;
}

#endif
