#include <set>
#include <fstream>
#include <iostream>

template <typename TClass,
          typename Compare = std::less<TClass>,
          typename Alloc = std::allocator<TClass>>

class SerializableSet : public std::set<TClass, Compare, Alloc> {
    
    std::string fileToWrite;
    
  public:
    SerializableSet(std::string filename) : fileToWrite(filename) {
        std::ifstream in;
        in.open(filename);
        TClass currElem = 0;
        while (in >> currElem) {
            this->insert(currElem);
        }
    }

    ~SerializableSet() {
        std::ofstream out;
        out.open(fileToWrite);
        for (auto elem : *this) {
            out << elem << '\0';
        }
    }
};

int main() {
    SerializableSet<int> S("file");
}
