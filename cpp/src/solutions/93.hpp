class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    int len = s.size();
    if (len < 4) {
      return vector<string>();
    }
    set<vector<int>> appeared;
    vector<string> ret;
    for (int i = 0; i <= len - 4; i++) {
      for (int j = i + 1; j <= len - 3; j++) {
        for (int k = j + 1; k <= len - 2; k++) {
          if (i + 1 > 4 || j - i > 4 || k - j > 4 || len - k > 4) {
            continue;
          }
          vector<string> ip_str(4, "");
          ip_str[0] = s.substr(0, i + 1);
          ip_str[1] = s.substr(i + 1, j - i);
          ip_str[2] = s.substr(j + 1, k - j);
          ip_str[3] = s.substr(k + 1, len - k);
          vector<int> ip(4, 0);
          bool legimate = true;
          for (int l = 0; l < 4; l++) {
            ip[l] = std::stol(ip_str[l]);
            if (ip[l] > 255 || (ip[l] == 0 && ip_str[l].size() > 1) ||
                (ip[l] > 0 && ip_str[l][0] == '0')) {
              legimate = false;
            }
          }
          if (!legimate) {
            continue;
          } else {
            appeared.insert(ip);
            ret.push_back(std::to_string(ip[0]) + "." + std::to_string(ip[1]) +
                          "." + std::to_string(ip[2]) + "." +
                          std::to_string(ip[3]));
          }
        }
      }
    }
    return ret;
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  string s = "25525511135";
  vector<string> groundTruth({"255.255.11.135", "255.255.111.35"});
  return Solution().restoreIpAddresses(s) == groundTruth;
}
REGISTER_TEST(example2) {
  string s = "0000";
  vector<string> groundTruth({"0.0.0.0"});
  return Solution().restoreIpAddresses(s) == groundTruth;
}
REGISTER_TEST(example3) {
  string s = "010010";
  vector<string> groundTruth({"0.10.0.10", "0.100.1.0"});
  return Solution().restoreIpAddresses(s) == groundTruth;
}
#endif