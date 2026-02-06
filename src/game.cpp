#include "game.h"
#include <iostream>
#include <limits>

Game::Game() : current_player_('X') {
    board_.fill(' ');
}

void Game::display_board() const {
    std::cout << "\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << " ";
        for (int col = 0; col < 3; ++col) {
            int idx = row * 3 + col;
            char cell = board_[idx];
            if (cell == ' ') {
                std::cout << idx + 1;
            } else {
                std::cout << cell;
            }
            if (col < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (row < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool Game::make_move(int position) {
    if (position < 0 || position > 8 || board_[position] != ' ') {
        return false;
    }
    board_[position] = current_player_;
    return true;
}

char Game::check_winner() const {
    // Rows, columns, diagonals
    constexpr int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // cols
        {0, 4, 8}, {2, 4, 6}              // diags
    };

    for (const auto& line : lines) {
        if (board_[line[0]] != ' ' &&
            board_[line[0]] == board_[line[1]] &&
            board_[line[1]] == board_[line[2]]) {
            return board_[line[0]];
        }
    }
    return ' ';
}

bool Game::is_board_full() const {
    for (char cell : board_) {
        if (cell == ' ') return false;
    }
    return true;
}

void Game::switch_player() {
    current_player_ = (current_player_ == 'X') ? 'O' : 'X';
}

void Game::run() {
    while (true) {
        display_board();
        std::cout << "Player " << current_player_ << ", enter position (1-9): ";

        int input;
        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number 1-9.\n";
            continue;
        }

        if (!make_move(input - 1)) {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        char winner = check_winner();
        if (winner != ' ') {
            display_board();
            std::cout << "Player " << winner << " wins!\n";
            break;
        }

        if (is_board_full()) {
            display_board();
            std::cout << "It's a draw!\n";
            break;
        }

        switch_player();
    }
}
