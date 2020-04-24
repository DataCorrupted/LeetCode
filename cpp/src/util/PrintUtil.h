#ifndef PRINT_UTIL
#define PRINT_UTIL

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream &operator<<(ostream &o, const vector<T> &v);
template <class T>
ostream &operator<<(ostream &o, const vector<vector<T>> &v);
template <class K, class V>
ostream &operator<<(ostream &o, const map<K, V> &m);
template <class P1, class P2>
ostream &operator<<(ostream &o, const pair<P1, P2> &p);

template <class T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << '[';
  for (unsigned i = 0; i < v.size(); i++) {
    o << v[i];
    if (i != v.size() - 1) {
      o << ", ";
    }
  }
  o << "]\n";
  return o;
}

template <class T>
ostream &operator<<(ostream &o, const vector<vector<T>> &v) {
  o << "[\n";
  for (unsigned i = 0; i < v.size(); i++) {
    o << " " << v[i];
  }
  o << "]\n";
  return o;
}

template <class K, class V>
ostream &operator<<(ostream &o, const map<K, V> &m) {
  o << "{";
  for (auto iter = m.begin(); iter != m.end(); ++iter) {
    o << iter->first << ": " << iter->second;
    auto next = iter;
    if (++next != m.end()) {
      o << ",  ";
    }
  }
  o << "}\n";
  return o;
}

template <class P1, class P2>
ostream &operator<<(ostream &o, const pair<P1, P2> &p) {
  o << "(" << p.first << "," << p.second << ")"
    << " ";
  return o;
}

#endif