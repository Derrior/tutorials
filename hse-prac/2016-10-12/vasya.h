#include <exception>
#include <iostream>
#include <vector>

#include <cstdint>

// Make a code review.

class ITicTacToe {
public:
    virtual ~ITicTacToe() = default;
    virtual uint32_t GetPlayerCount() = 0;           //
    virtual uint32_t GetCurrentPlayerID() = 0;       //
    virtual uint32_t GetRowCount() = 0;              // Getters shall be const
    virtual uint32_t GetColumnCount() = 0;           //
    virtual uint32_t GetMarksInARowForTheWin() = 0;  //

    // Make turn for the current player.
    //
    // @param row                       Row where current player will put his mark.
    // @param column                    Column where current player will put hist mark.
    //
    // @returns                         Non-zero if current player won the game with this turn.
    //
    // @throws std::runtime_exception   If input was invalid (cell was already occupied, or cell is
    //                                  outside the grid).
    virtual uint32_t MakeTurn(int row, int column) = 0;

    // Get mark in cell with (`row`, `column`) coordinates.
    //
    // @throws std::out_of_range        If input was invalid.
    virtual int operator()(int row, int column) = 0;  // shold be const
};

// https://en.wikipedia.org/wiki/M,n,k-game
//
// Tic-tac-toe game with grid of size M*N and where player wins if there are K marks of
// his own color in a row, horizontally, vertically, or diagonally.
//
class QuadraticMNKGame : public ITicTacToe {
    uint32_t size_;
    uint32_t player_count_;              // choose one style to write names
    uint32_t colors_in_a_row_for_the_win_;
    std::vector<std::vector<int>> grid_; // zero for the empty cell
    int current_player_;

public:
    QuadraticMNKGame(
        const int size,
        const int player_count,
        const int colors_in_a_row_for_the_win)
        : size(size_) // doesn't have field named size
        , player_count_(player_count)
        , colors_in_a_row_for_the_win_(colors_in_a_row_for_the_win)
        , grid_(size) /* your grid's size is size x 0) */ {
    }
    // you have not overrided function from parent class
    uint32_t GetRowCount() const {  // point out, that it is virtual function, write 'override'
        return size_;
    }

    uint32_t GetColumnCount() const {  // point out, that it is virtual function, write 'override'
        return size_;
    }

    uint32_t GetPlayerCount() const {  // point out, that it is virtual function, write 'override'
        return player_count_;
    }

    uint32_t GetCurrentPlayerID() const {  // point out, that it is virtual function, write 'override'
        return current_player_;
    }

    uint32_t GetMarksInARowForTheWin() const {  // point out, that it is virtual function, write 'override'
        return colors_in_a_row_for_the_win_;
    }
    int MakeTurn(int row, int column) {  // point out, that it is virtual function, write 'override'
                                         // bad overrideing (returned value is uint32_t in parent and int in child)
                                         // return value is boolean 
        if (grid_[row][column]) {
            throw std::runtime_error("cell is already occupied");
        }

        grid_[row][column] = current_player_;
        // you haven't change current player
        return CheckIfPlayerWins(current_player_); // it's bool, yes or no
    }

    virtual int operator()(int row, int column) {  // point out, that it is virtual function, write 'override'
                                                   // should be const
        return grid_[row][column];
    }

private:
    bool CheckIfPlayerWins(const uint32_t player) const {
        for (uint32_t i = 0; i < size_; ++i) {
            for (uint32_t j = 0; j < size_; ++j) {
                if (player == grid_[i][j] &&
                    (CheckHorizontal(i, j) ||
                     CheckVertical(i, j) ||
                     CheckDiagonal(i, j) ||
                     CheckAntiDiagonal(i, j)))

                    return true;
                }
            }
        } // here is the end of function block
        return false;
    }

    // following 4 functions may be one
    // check if there is a winning combination to the right
    bool CheckHorizontal(const uint32_t row, const uint32_t column) const {
        if (column + colors_in_a_row_for_the_win_ >= size_) {
            return false;
        }

        for (uint32_t i = 1; i < colors_in_a_row_for_the_win_; ++i) {
            if (grid_[row][i - 1] != grid_[row][i]) {
                return false;
            }
        }
        return true;
    }

    // check if there is a winning combination down
    bool CheckVertical(const uint32_t row, const uint32_t column) const {
        if (row + colors_in_a_row_for_the_win_ > size_) {
            return false;
        }
        // write these functions in one style
        for (uint32_t j = row + 1; j < row + colors_in_a_row_for_the_win_; ++j) {
            if (grid_[j - 1][column] != grid_[j][column]) {
                return false;
            }
        }
        return true;
    }

    // check if there is a winning combination down and to the right
    bool CheckDiagonal(const uint32_t row, const uint32_t column) const {
        if (column + colors_in_a_row_for_the_win_ >= size_ ||
            row + colors_in_a_row_for_the_win_ >= size_) {
            return false;
        }

        const auto player_color = grid_[row][column];
        for (uint32_t i = 1; i < colors_in_a_row_for_the_win_; ++i) {
            if (player_color != grid_[row + i][column + i]) {
                return false;
            }
        }
        return true;
    }

    // check if there is a winning combination down and to the left
    bool ChckAntiDiagonal(const uint32_t row, const uint32_t column) const { //misspelling chck -> check
        if (column - colors_in_a_row_for_the_win_ < 0 || // comparsion between signed and unsigned int
            row + colors_in_a_row_for_the_win_ >= size_) {

            return false;
        }

        const auto player_color = grid_[row][column];
        for (uint32_t i = 1; i < colors_in_a_row_for_the_win_; ++i) {
            if (player_color != grid_[row + i][column - i]) {
                return false;
            }
        }
        return true;
    }
};

std::ostream& operator << (std::ostream& out, const ITicTacToe& game) {
    for (size_t i = 0; i < game.GetRowCount(); ++i) {
        for (size_t j = 0; j < game.GetColumnCount(); ++i) {  // wrong index
            if (j) {
                std::cout << ' ';
            }
            std::cout << game(i, j) << std::endl;  // your table outputs like one column
        }
        std::cout << '\n';
    }
    return out;
}
