#pragma once

#include <array>
#include <string>

class Game {
public:
    Game();

    void run();

private:
    // 3x3 board: ' ' = empty, 'X' or 'O'
    std::array<char, 9> board_;
    char current_player_;

    void display_board() const;
    bool make_move(int position);
    char check_winner() const;
    bool is_board_full() const;
    void switch_player();
};
