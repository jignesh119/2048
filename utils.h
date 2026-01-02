//----- Some very handy helper macros to quickly log stuff to console ----
#pragma once
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// macros to log arrays, matrices
#define debarr(a, n)                                                           \
  std::cout << #a << " : ";                                                    \
  for (int i = 0; i < n; i++)                                                  \
    std::cerr << a[i] << " ";                                                  \
  std::cerr << std::endl;

#define debmat(mat, row, col)                                                  \
  std::cout << #mat << " :\n";                                                 \
  for (int i = 0; i < row; i++) {                                              \
    for (int j = 0; j < col; j++)                                              \
      std::cerr << mat[i][j] << " ";                                           \
    std::cerr << std::endl;                                                    \
  }

#define pr(...) ::utils::dbs(#__VA_ARGS__, __VA_ARGS__)

// NOTE:
// Stream operator overloading for common containers remain at global level for
// argument dependent lookup pairs
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::pair<S, T> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

// vector
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &p) {
  os << "[ ";
  for (auto const &it : p)
    os << it << " ";
  return os << "]";
}

// unordered set
template <class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &p) {
  os << "[ ";
  for (auto const &it : p)
    os << it << " ";
  return os << "]";
}

// unordered map
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<S, T> &p) {
  os << "[ ";
  for (auto const &it : p)
    os << it << " ";
  return os << "]";
}

// set
template <class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &p) {
  os << "[ ";
  for (auto const &it : p)
    os << it << " ";
  return os << "]";
}

// multiset
template <class T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &p) {
  os << "[ ";
  for (auto const &it : p)
    os << it << " ";
  return os << "]";
}

// map
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::map<S, T> &p) {
  os << "[ ";
  for (auto const &it : p)
    os << it << " ";
  return os << "]";
}

// some helper templates inside the "utils" namespace
namespace utils {
template <class T> void dbs(std::string str, T t) {
  std::cerr << str << " : " << t << "\n";
}

template <class T, class... S> void dbs(std::string str, T t, S... s) {
  int idx = static_cast<int>(str.find(','));
  std::cerr << str.substr(0, static_cast<size_t>(idx)) << " : " << t << ",";
  dbs(str.substr(static_cast<size_t>(idx + 1)), s...);
}

// Print a range [a, b) like iterators
template <class It> void prc(It a, It b) {
  std::cerr << "[";
  for (It i = a; i != b; ++i) {
    if (i != a)
      std::cerr << ", ";
    std::cerr << *i;
  }
  std::cerr << "]\n";
}
} // namespace utils
