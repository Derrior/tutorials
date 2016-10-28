#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::unordered_map<std::string, std::vector<int> > Dict;

Dict input() {
    Dict inputted;
    int dictLength = 0, vectorsLength = 0;
    std::cin >> dictLength >> vectorsLength;
    std::string key;
    std::vector<int> value(vectorsLength);
    for (int i = 0; i < dictLength; i++) {
        std::cin >> key;
        for (int &v : value) {
            std::cin >> v;
        }
        inputted[key] = value;
    }
    return inputted;
}

int scalar(std::vector<int> &first, std::vector<int> &second) {
    int multiplication = 0;
    for (size_t i = 0; i < first.size(); i++) {
        multiplication += first[i] * second[i];
    }
    return multiplication;
}

bool IsInDict(Dict & dict, std::string& key) {
    return dict.find(key) != dict.end();
}

int main() {
    Dict dict = input();
    std::string first, second;
    std::cin >> first >> second;
    if (!(IsInDict(dict, first) && IsInDict(dict, second))) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << scalar(dict[first], dict[second]) << std::endl;
    }
}
