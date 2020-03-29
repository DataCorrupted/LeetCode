class Solution {
 public:
  int myAtoi(string str) {
    if (str.size() == 0) {
      return 0;
    }
    int head = 0;
    while (head < str.size() && str[head] == ' ') {
      head++;
    }
    if (head == str.size()) {
      return 0;
    }

    int sign = (str[head] == '-') ? -1 : 1;
    if (str[head] == '-' || str[head] == '+') {
      head++;
    }
    if (head == str.size()) {
      return 0;
    }

    int i = head;
    long ans = 0;
    bool overflow = false;
    int digit = 0;
    while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
      digit = (int)(str[i] - '0');
      ans = ans * 10 + digit;
      if (ans > 2147483647) {
        overflow = true;
        break;
      }
      i++;
    }
    if (overflow) {
      return (sign == -1) ? -2147483648 : 2147483647;
    } else {
      return ans * sign;
    }
  }
};