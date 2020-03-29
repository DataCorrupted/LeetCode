class Solution {
 public:
  int romanToInt(string s) {
    if (s.size() == 0) {
      return 0;
    }
    map<char, int> r_map;
    r_map['I'] = 1;
    r_map['V'] = 5;
    r_map['X'] = 10;
    r_map['L'] = 50;
    r_map['C'] = 100;
    r_map['D'] = 500;
    r_map['M'] = 1000;

    int ans = r_map[s[s.size() - 1]];
    for (int i = 0; i < s.size() - 1; i++) {
      const char curr = s[i];
      const char next = s[i + 1];

      if (r_map[curr] >= r_map[next]) {
        ans += r_map[curr];
      } else {
        ans -= r_map[curr];
      }
    }
    return ans;
  }
};