// #include "utils.cpp"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

typedef vector<int> vi;
typedef vector<string> vs;

// lets assume only 1 action exists: slide left
void slide(vi &row) {
  vi tmp;
  for (auto &x : row) {
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
  row = tmp;
  while (row.size() < 4)
    row.push_back(0);
}

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
    while (!has_game_ended() && 1) {
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
  void move_up() {}
  void move_down() {}
  void move_right() {}
  void move_left() {}
};

signed main() {
  // freopen("board.inp", "r", stdin);
  // freopen("board.res", "w", stderr);
  // vi row(4);
  // for (auto &x : row)
  //   cin >> x;
  // pr(row);
  // slide(row);
  // pr(row);
  srand(time(0));
  Game mygame;
  cout << mygame.board;
}
