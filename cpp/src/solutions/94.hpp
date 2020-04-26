
#ifdef DEBUG
#include "TreeNodeG.hpp"
typedef TreeNodeG<int> TreeNode;
#endif
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> ret;
    vector<int> left = this->inorderTraversal(root->left);
    for (int i : left) {
      ret.push_back(i);
    }
    ret.push_back(root->val);
    vector<int> right = this->inorderTraversal(root->right);
    for (int i : right) {
      ret.push_back(i);
    }
    return ret;
  }
};
