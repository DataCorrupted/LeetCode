class Solution {
 public:
  int lengthOfLastWord(string s) {
    s = s + ' ';
    int last_len = 0;
    int counter = 0;
    int i = 0;
    while (i < s.size()) {
      if (s[i] == ' ') {
        last_len = counter;
        counter = 0;
        while (i < s.size() && s[i] == ' ') {
          i++;
        }
      } else {
        counter++;
        i++;
      }
    }
    return last_len;
  }
};