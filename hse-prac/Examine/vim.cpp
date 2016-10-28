#include <iostream>
#include <vector>
#include <string>
#include <fstream>

static const std::string ESCAPE_SYMBOL = "<ESC>";

typedef std::vector<std::string> TCommandRange;

class Vim {
    enum class State {
        Normal = 0,
        Insert = 1,
    };
    std::string text_;
    size_t position_;
    State currentState_;

 public:
    Vim():
        position_(0),
        currentState_(State::Normal)
        {}
    void CommandInInsertMode(const std::string &command) {
        if (command == ESCAPE_SYMBOL) {
            currentState_ = State::Normal;
        } else {
            text_.insert(position_, command);
            position_++;
        }
    }

    void CommandInNormalMode(const std::string &command) {
        if (command == "i") {
            currentState_ = State::Insert;
        } else if (command == "h") {
            if (position_ > 0) {
                --position_;
            }
        } else if (command == "l") {
            if (position_ < text_.length()) {
                position_++;
            }
        }
    }

    void ProcessCommand(const std::string &command) {
        if (currentState_ == State::Normal) {
            CommandInNormalMode(command);
        } else if (currentState_ == State::Insert) {
            CommandInInsertMode(command);
        }
    }

    void ProcessCommandRange(const TCommandRange &commandRange) {
        for (const auto &command : commandRange) {
            ProcessCommand(command);
        }
    }
    std::ostream &OutputText(std::ostream &stream) const {
        return stream << text_ << std::endl;
    }
};

TCommandRange ParseCommandSequence(const std::string &commandSequence) {
    TCommandRange commandRange;
    for (size_t i = 0; i < commandSequence.length(); i++) {
        if (commandSequence[i] == '<') {
            while (i < commandSequence.length() && commandSequence[i] != '>') {
                i++;
            }
            commandRange.push_back(ESCAPE_SYMBOL);
        } else {
            commandRange.push_back(commandSequence.substr(i, 1));
        }
    }
    return commandRange;
}

TCommandRange GetCommandRange() {
    std::string line;
    getline(std::cin, line);
    return ParseCommandSequence(line);
}


int main() {
    std::ofstream out;
    out.open("output.txt");
    Vim editor;
    auto commandRange = GetCommandRange();
    editor.ProcessCommandRange(commandRange);
    editor.OutputText(out);
}
