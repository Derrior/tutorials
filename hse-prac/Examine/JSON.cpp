#include <string>

class Serializer {
 public:
    virtual void BeginArray() = 0;
    virtual void EndArray() = 0;
    virtual void AddArrayItem(const &std::string elem) = 0;
};

class JSONSerializer: public Serializer {
    void BeginArray() override {
        std::cout << '[';
    }
    void EndArray() override {
        std::cout << ']';
    }
}
