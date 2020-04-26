#include <sstream>
#include <stack>
#include <string>

template <class T>
struct TreeNodeG {
  T val;
  TreeNodeG *left;
  TreeNodeG *right;
  TreeNodeG(T x) : val(x), left(nullptr), right(nullptr){};
  TreeNodeG(T x, TreeNodeG *left, TreeNodeG *right)
      : val(x), left(left), right(right){};
  ~TreeNodeG() {
    if (left) {
      delete left;
    }
    if (right) {
      delete right;
    }
  }

  stringstream toStringStream() {
    std::stringstream ss;
    std::stack<TreeNodeG *> nodeStack;
    nodeStack.push(this);
    std::stack<int> levelStack;
    levelStack.push(0);

    TreeNodeG *curr = NULL;
    int level = 0;
    while (nodeStack.size() != 0) {
      curr = nodeStack.top();
      nodeStack.pop();
      level = levelStack.top();
      levelStack.pop();

      for (int i = 0; i < level; i++) {
        ss << "|--";
      }
      if (curr) {
        ss << curr->val << "\n";
      } else {
        ss << "null"
           << "\n";
        continue;
      }
      if (!curr->right && !curr->left) {
        continue;
      }
      nodeStack.push(curr->right);
      levelStack.push(level + 1);
      nodeStack.push(curr->left);
      levelStack.push(level + 1);
    }
    return ss;
  }
  string toString() { return toStringStream().str(); }
  friend ostream &operator<<(ostream &o, TreeNodeG *root) {
    o << root->toString();
    return o;
  }

  static bool treesEq(const TreeNodeG *lhs, const TreeNodeG *rhs) {
    if (!lhs && !rhs) {
      return true;
    }
    if (!lhs || !rhs) {
      return false;
    }
    return (lhs->val == rhs->val) &&
           (treesEq(lhs->left, rhs->left) && (treesEq(lhs->right, rhs->right)));
  }
  friend bool operator==(TreeNodeG &lhs, TreeNodeG &rhs) {
    return treesEq(&lhs, &rhs);
  }
};

string serialize(TreeNodeG<int> *root) {
  std::stringstream ss;
  if (!root) {
    ss << "{ null }";
  } else {
    ss << "{ val: " << std::to_string(root->val)
       << ", left: " << serialize(root->left)
       << ", right: " << serialize(root->right) << " }";
  }
  return ss.str();
}
/// s[idx] has to be '{'.
size_t find_match_right_curve(string &s, size_t idx) {
  int num_curve = 0;
  while (true) {
    if (s[idx] == '{') {
      num_curve++;
    }
    if (s[idx] == '}') {
      num_curve--;
    }
    if (num_curve == 0) {
      return idx;
    }
    idx++;
    if (idx == s.size()) {
      return idx - 1;
    }
  }
}

TreeNodeG<int> *deserialize(string s) {
  if (s == "{ null }") {
    return nullptr;
  }
  size_t val_start = 7;
  size_t val_end = s.find(",");
  size_t left_start = val_end + 8;
  size_t left_end = find_match_right_curve(s, left_start);
  size_t right_start = left_end + 10;
  size_t right_end = find_match_right_curve(s, right_start);
  return new TreeNodeG<int>(
      std::stoi(s.substr(val_start, val_end - val_start)),
      deserialize(s.substr(left_start, left_end - left_start + 1)),
      deserialize(s.substr(right_start, right_end - right_start + 1)));
}
