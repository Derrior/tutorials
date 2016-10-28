#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

typedef std::vector<std::string> Text;

Text Input() {
    std::string raw;
    Text inputtedData;
    while (getline(std::cin, raw)) {
        inputtedData.push_back(raw);
    }
    return inputtedData;
}

void Processing(Text &text) {
    sort(text.begin(), text.end());
    text.resize(unique(text.begin(), text.end()) - text.begin());
}

void Output(const Text &text) {
    for (const auto &raw : text) {
        std::cout << raw << '\n';
    }
}

int main() {
    Text text = Input();
    Processing(text);
    Output(text);
}
