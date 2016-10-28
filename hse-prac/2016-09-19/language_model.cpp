#include <unordered_map>
#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <cmath>
#include <list>
#include <map>


typedef std::unordered_map <std::string, int> distributionPart;
const int LIMIT = 7;

struct Distribution {
  private:
    std::vector<distributionPart> distribution;
    char PickNext(const std::string &tail);

  public:
    Distribution(int gramsSize = LIMIT); 
    void LoadText();
    std::string GenerateText(size_t length);
    void PrintModel(int gramIndex);
};


size_t Random(size_t lower, size_t upper);

bool isBadChar(char c) {
    return c < 32;
}


int main() {
    Distribution distribution(LIMIT);
    distribution.LoadText();
    //distribution.PrintModel(LIMIT);
    std::cout << distribution.GenerateText(200);
    return 0;
}


Distribution::Distribution(int gramsSize) {
    distribution.resize(gramsSize + 1);
}


void Distribution::LoadText() {
    std::string line;
    while (getline(std::cin, line)) {
        line += '\n';
        for (size_t i = 0; i < line.length(); ++i) {
            for (size_t length = 1; length < distribution.size(); ++length) {
                if (i + length > line.length()) {
                    break;
                }
                distribution[length][line.substr(i, length)]++;
            }
        }
    }
}



char Distribution::PickNext(const std::string &tail) {
    assert(tail.length() == LIMIT - 1);
    double weightSum = 0;
    std::map<char, int> possibleEndings;
    for (char c = 0; c < 127; ++c) {
        for (int tailLength = 1; tailLength <= LIMIT; tailLength++) {
            auto found = distribution[tailLength].find(tail.substr(LIMIT - tailLength) + c);
            if (found != distribution[tailLength].end()) {
                double currentEndingWeight = pow(tailLength, 7) * (static_cast<double> (found->second)) / (1 << (LIMIT - tailLength));
                possibleEndings[c] += currentEndingWeight;
                weightSum += currentEndingWeight;
            }
        }
    }
    if (weightSum == 0) {
        return 0;
    }
    int choice = Random(0, weightSum - 1);
    for (const auto &ending : possibleEndings) {
        if (choice < ending.second)  {
            return ending.first;
        }
        choice -= ending.second;
    }
    return 0;
}


std::string Distribution::GenerateText(size_t length) {
    std::string text = distribution[LIMIT].begin()->first;

    while (text.length() < length) {
        text.push_back(PickNext(text.substr(text.length() - LIMIT + 1)));
    }
    return text;
}


void Distribution::PrintModel(int gramIndex) {
for (auto &item : distribution[gramIndex]) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

size_t Random(size_t lower, size_t upper) {
    static std::random_device device;
    static std::mt19937 generator(device());
    std::uniform_int_distribution<> distribution(lower, upper);
    return distribution(generator);
}
