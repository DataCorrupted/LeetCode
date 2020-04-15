class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> unreach;
        for (string s: deadends) {
            unreach.insert(s);
        }
        if (unreach.find("0000") != unreach.end()) {
            return -1;
        }
        if (unreach.find(target) != unreach.end()) {
            return -1;
        }
        queue<std::pair<string, int>> Q; 
        Q.push(std::pair<string, int>("0000", 0));

        while (!Q.empty()) {
            auto pair = Q.front();
            string curr = pair.first;
            int idx = pair.second;
            if (curr == target) {
                return idx;
            }
            Q.pop();
            for (int i=0; i<4; i++){
                string tmp = curr;
                char c = curr[i];
                if (c == '0') {
                    tmp[i] = '9';
                } else {
                    tmp[i] = c - 1;
                }
                if (unreach.find(tmp) == unreach.end()) {
                    Q.push(std::pair<string, int>(tmp, idx+1));
                    unreach.insert(tmp);
                }

                if (c == '9') {
                    tmp[i] = '0';
                } else {
                    tmp[i] = c + 1;
                }
                if (unreach.find(tmp) == unreach.end()) {
                    Q.push(std::pair<string, int>(tmp, idx+1));
                    unreach.insert(tmp);
                }
            }
        }
        return -1;
    }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  vector<string> deadends({"0201","0101","0102","1212","2002"});
  string target = "0202";
  int groundTruth = 6;
  return Solution().openLock(deadends, target) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<string> deadends({"8888"});
  string target = "0009";
  int groundTruth = 1;
  return Solution().openLock(deadends, target) == groundTruth;
}
REGISTER_TEST(example3) {
  vector<string> deadends({"8887","8889","8878","8898","8788","8988","7888","9888"});
  string target = "8888";
  int groundTruth = -1;
  return Solution().openLock(deadends, target) == groundTruth;
}
REGISTER_TEST(example4) {
  vector<string> deadends({"0000"});
  string target = "8888";
  int groundTruth = -1;
  return Solution().openLock(deadends, target) == groundTruth;
}

#endif