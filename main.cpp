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

signed main() {
  freopen("board.inp", "r", stdin);
  freopen("board.res", "w", stderr);
  vi row(4);
  for (auto &x : row)
    cin >> x;
  pr(row);
  slide(row);
  pr(row);
}
