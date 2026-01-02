// #include "utils.cpp"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

typedef vector<int> vi;
typedef vector<string> vs;

signed main() {
  freopen("ip.txt", "r", stdin);
  int n;
  cin >> n;
  vi arr(n);
  for (auto &x : arr)
    cin >> x;
  pr(arr);
}
