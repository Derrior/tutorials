#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <map>
#include <utility>


struct Point {
    int x_, y_;
    Point() : x_(0), y_(0) {
    }
    Point(int x, int y) : x_(x), y_(y) {
    }
    bool operator == (const Point &other) const {
        return (x_ == other.x_) && (y_ == other.y_);
    }
    Point& operator += (const Point &other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }
};


static const std::map<std::string, Point> MOVE = {
                                                  {"left", Point(-1, 0)},
                                                  {"right", Point(1, 0)},
                                                  {"up", Point(0, 1)},
                                                  {"down", Point(0, -1)}};

struct PointHash {
    size_t operator () (const Point &p) const {
        return p.x_ ^ ((p.y_ << 1) | 179);
    }
};

const PointHash POINT_HASH();
typedef std::unordered_set<Point, PointHash> CellsSet;

struct ParsedLine {
    std::vector<std::string> words;
    int indentCount;
    ParsedLine(const std::string &line) {
        size_t nonSpaceIndex = 0;
        while (nonSpaceIndex < line.length() && line[nonSpaceIndex] == ' ') {
            nonSpaceIndex++;
        }
        indentCount = nonSpaceIndex / 4;
        std::stringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            words.push_back(word);
        }
    }
    bool HasIndentation() const {
        return indentCount != 0;
    }

    void RemoveIndentation() {
        indentCount--;
    }
    const std::string &back() const {
        return words.back();
    }
    const std::string &get_word(size_t idx) const {
        return words[idx];
    }
};

typedef std::vector<ParsedLine> Program;
class Turtle;


class Turtle {
    Point coords_;

 public:
    Turtle(): coords_() {
    }
    void Execute(Program &program, CellsSet &painted) {
        for (size_t line_index = 0; line_index < program.size(); ++line_index) {
            auto parsed = program[line_index];
            if (parsed.back() == "times") {
                Program subprogram;
                for (++line_index; line_index < program.size() &&
                                   program[line_index].HasIndentation(); line_index++) {
                     subprogram.push_back(program[line_index]);
                     subprogram.back().RemoveIndentation();
                }
                int amountOfIterations = atoi(parsed.get_word(0).c_str());
                for (int i = 0; i < amountOfIterations; ++i) {
                    Execute(subprogram, painted);
                }
            } else if (parsed.back() == "paint") {
                painted.insert(coords_);
            } else {
                coords_ += MOVE.find(parsed.get_word(0))->second;
            }
        }
    }
};

int main() {
    Program p;
    std::string line;
    while (getline(std::cin, line)) {
        p.push_back(ParsedLine(line));
    }
    Turtle turtle;
    CellsSet painted;
    turtle.Execute(p, painted);
    std::cout << painted.size() << std::endl;
}
