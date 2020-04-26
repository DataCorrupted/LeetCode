#ifdef DEBUG

#include "TreeNodeG.hpp"
typedef TreeNodeG<int> TreeNode;

#endif

class Codec {
 public:
  /// s[idx] has to be '{'.
  size_t find_match_right_curve(string& s, size_t idx) {
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

  TreeNode* deserialize(string s) {
    if (s == "{ null }") {
      return nullptr;
    }
    size_t val_start = 7;
    size_t val_end = s.find(",");
    size_t left_start = val_end + 8;
    size_t left_end = find_match_right_curve(s, left_start);
    size_t right_start = left_end + 10;
    size_t right_end = find_match_right_curve(s, right_start);
    return new TreeNode(
        std::stoi(s.substr(val_start, val_end - val_start)),
        deserialize(s.substr(left_start, left_end - left_start + 1)),
        deserialize(s.substr(right_start, right_end - right_start + 1)));
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
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
  // Decodes your encoded data to tree.
  // TreeNode* deserialize(string data) { return nullptr; }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#ifdef DEBUG
REGISTER_TEST(example1) {
  // Codec codec;
  TreeNode* root = new TreeNode(
      1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)));
  Codec codec;
  TreeNode* new_root = codec.deserialize(codec.serialize(root));
  bool ret = (*new_root) == (*root);
  delete new_root;
  delete root;
  return ret;
}
#endif