// #include "utils.cpp"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

typedef vector<int> vi;
typedef vector<string> vs;

struct Game {
  vector<vector<int>> board;
  Game() : board(4, vector<int>(4)) {
    random_populate();
    random_populate();
  }
  bool has_game_ended() {
    for (auto &row : board)
      for (auto &cell : row)
        if (cell == 0)
          return false;
    return true;
  }
  void random_populate() {
    while (1) {
      int r = rand() % 4, c = rand() % 4;
      if (board[r][c] == 0) {
        if (rand() % 2)
          board[r][c] = 4;
        else
          board[r][c] = 2;
        return;
      }
    }
  }

  // NOTE: only 1 generic action exists: slide left
  void slide_left(vi &list) {
    vi tmp;
    for (auto &x : list) {
      if (x == 0)
        continue;
      if (tmp.empty() || tmp.back() != x)
        tmp.push_back(x);
      else {
        tmp.pop_back();
        tmp.push_back(-1 * (x + x));
      }
    }
    for (auto &x : tmp)
      x = abs(x);
    list = tmp;
    while (list.size() < 4)
      list.push_back(0);
  }
  bool move_up() {
    for (int col = 0; col < 4; col++) {
      vi tmp;
      for (int row = 0; row < 4; row++) {
        tmp.push_back(board[row][col]);
      }
      slide_left(tmp);
      for (int row = 0; row < 4; row++) {
        board[row][col] = tmp[row];
      }
    }
    return move_end();
  }
  bool move_down() {
    for (int col = 0; col < 4; col++) {
      vi tmp;
      for (int row = 3; row >= 0; row--) {
        tmp.push_back(board[row][col]);
      }
      slide_left(tmp);
      for (int row = 3; row >= 0; row--) {
        board[row][col] = tmp[3 - row];
      }
    }
    return move_end();
  }
  bool move_right() {
    for (int row = 0; row < 4; row++) {
      vi tmp;
      for (int col = 3; col >= 0; col--) {
        tmp.push_back(board[row][col]);
      }
      slide_left(tmp);
      for (int col = 3; col >= 0; col--) {
        board[row][col] = tmp[3 - col];
      }
    }
    return move_end();
  }
  bool move_left() {
    for (int row = 0; row < 4; row++) {
      vi tmp;
      for (int col = 0; col < 4; col++) {
        tmp.push_back(board[row][col]);
      }
      slide_left(tmp);
      for (int col = 0; col < 4; col++) {
        board[row][col] = tmp[col];
      }
    }
    return move_end();
  }
  bool move_end() {
    if (has_game_ended()) {
      return true;
    } else {
      random_populate();
      return false;
    }
  }

  /**
   * @brief prints the current state of the game board to the console.
   * Each cell is displayed with its value if non-zero, or a dot (.) if empty.
   */
  void print_board() {
    for (auto &row : board) {
      for (const int &cell : row) {
        if (cell)
          cout << cell << '\t';
        else
          cout << ".\t";
      }
      cout << endl;
    }
  }
};

signed main() {
  // freopen("board.inp", "r", stdin);
  // freopen("board.res", "w", stderr);
  srand(time(0));
  Game mygame;
  while (1) {
    mygame.print_board();
    char opt;
    cout << "Choose move (L,R,U,D): ";
    cin >> opt;
    bool game_ended;
    switch (opt) {
    case 'L': {
      game_ended = mygame.move_left();
      break;
    }
    case 'R': {
      game_ended = mygame.move_right();
      break;
    }
    case 'U': {
      game_ended = mygame.move_up();
      break;
    }
    case 'D': {
      game_ended = mygame.move_down();
      break;
    }
    }
    if (game_ended) {
      cout << "\t--- Game Ended --- \n";
      return 0;
    }
  }
}
