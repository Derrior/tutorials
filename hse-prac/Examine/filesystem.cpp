#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

const char DIRECTORY_SEPARATOR = '/';

typedef std::set<std::string> TDirectoriesSet;
typedef std::vector<std::string> TFilePath;

std::vector<std::string> Split(std::string text, char separator) {
    std::vector<std::string> splittedNow(1);
    for (char c : text) {
        splittedNow.back().push_back(c);
        if (c == separator) {
            splittedNow.push_back(std::string());
        }
    }
    return splittedNow;
}

bool getFilePath(TFilePath &filePath) {
    std::string filename;
    bool isInputSucceed = getline(std::cin, filename).good();
    if (isInputSucceed) {
        filePath = Split(filename, DIRECTORY_SEPARATOR);
    }
    return isInputSucceed;
}


void addDirectories(TDirectoriesSet &directoriesFound, const
                     TFilePath & currentFilePath) {
    std::string CurrentDirectoryPath;
    for (size_t depth = 0; depth + 1 < currentFilePath.size();
        depth++) {
        CurrentDirectoryPath += currentFilePath[depth];
        directoriesFound.insert(CurrentDirectoryPath);
    }
}

TDirectoriesSet ProcessInput() {
    TFilePath currentFilePath;
    TDirectoriesSet directoriesAlreadyFound;
    while (getFilePath(currentFilePath)) {
        addDirectories(directoriesAlreadyFound, currentFilePath);
    }
    return directoriesAlreadyFound;
}

void OutputDirs(const TDirectoriesSet &DirectoriesSet) {
    for (const auto & DirectoryName : DirectoriesSet) {
        std::cout << DirectoryName << '\n';
    }
}

int main() {
    TDirectoriesSet DirectoriesFound = ProcessInput();
    OutputDirs(DirectoriesFound);
}
