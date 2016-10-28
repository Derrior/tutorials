#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>

typedef std::map<char, char> TReplaceDictionary;

TReplaceDictionary InputReplaceDictionary() {
    std::string toReplace, replaceWith;
    getline(std::cin, toReplace);
    getline(std::cin, replaceWith);
    std::map<char, char> replaceDictionary;
    for (size_t i = 0; i < toReplace.length(); i++) {
        replaceDictionary[toReplace[i]] = replaceWith[i];
    }
    return replaceDictionary;
}

std::string ProcessLine(const std::string &line, const TReplaceDictionary &
                replaceDictionary) {
    std::string afterReplace(line.length(), 0);
    transform(line.begin(), line.end(), afterReplace.begin(),
            [&replaceDictionary](char c) {
                auto charEntry = replaceDictionary.find(c);
                if (charEntry != replaceDictionary.end()) {
                    c = charEntry->second;
                }
                return c;
            });
    return afterReplace;
}

void ProcessText(const TReplaceDictionary &replaceDictionary) {
    std::string line;
    while (getline(std::cin, line)) {
        std::cout << ProcessLine(line, replaceDictionary) << '\n';
    }
}

int main() {
    TReplaceDictionary replaceDictionary = InputReplaceDictionary();
    ProcessText(replaceDictionary);
}
