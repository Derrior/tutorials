#include <iostream>
#include <string>
#include <queue>

const int MAX_TURNS_AMOUNT = 1e6;

typedef std::queue<int> Deck;

struct Player {
    Deck cards;
    std::string name;
    Player(std::string _name): name(_name) {
    }

    std::istream& in(std::istream &inputStream, int amountOfCards = 5) {
        int currentCard = 0;
        for (int i = 0; i < amountOfCards; i++) {
            inputStream >> currentCard;
            cards.push(currentCard);
        }
        return inputStream;
    }

    std::ostream& out(std::ostream &outputStream) {
        outputStream << name;
        return outputStream;
    }

    bool isLoser() {
        return cards.empty();
    }

    int pullCard() {
        if (cards.empty()) {
            return -1;
        }
        int card = cards.front();
        cards.pop();
        return card;
    }

    void pushCards(int firstCard, int secondCard) {
        cards.push(firstCard);
        cards.push(secondCard);
    }
};

int SetCardValue(Player &player, int &card) {
    return card = player.pullCard();
}

bool IsGameOn(Player &first, Player &second,
              int &firstPlayerCard, int &secondPlayerCard) {
    bool isFirstDeckEmpty = SetCardValue(first, firstPlayerCard) == -1;
    bool isSecondDeckEmpty = SetCardValue(second, secondPlayerCard) == -1;
    return !(isFirstDeckEmpty || isSecondDeckEmpty);
}

bool Compare(int firstCard, int secondCard) {
    if (firstCard == 0 && secondCard == 9) {
        return false;
    } else if (firstCard == 9 && secondCard == 0) {
        return true;
    }
    return firstCard < secondCard;
}

int Game(Player &first, Player &second) {
    int firstPlayerCard = 0, secondPlayerCard = 0;
    int amountOfTurns = 0;
    while (amountOfTurns < MAX_TURNS_AMOUNT &&
           IsGameOn(first, second, firstPlayerCard, secondPlayerCard)) {
        if (Compare(firstPlayerCard, secondPlayerCard)) {
            second.pushCards(firstPlayerCard, secondPlayerCard);
        } else {
            first.pushCards(firstPlayerCard, secondPlayerCard);
        }
        amountOfTurns++;
    }
    return amountOfTurns;
}

void output(Player &first, Player &second, int amountOfTurns) {
    if (amountOfTurns >= MAX_TURNS_AMOUNT) {
        std::cout << "botva" << std::endl;
    } else if (first.isLoser()) {
        second.out(std::cout) << ' ' << amountOfTurns << std::endl;
    } else {
        first.out(std::cout) << ' ' << amountOfTurns << std::endl;
    }
}

int main() {
    Player first("first"), second("second");
    first.in(std::cin);
    second.in(std::cin);
    int turnsPassed = Game(first, second);
    output(first, second, turnsPassed);
}
