#ifdef DEBUG
#include "TreeNodeG.hpp"

typedef TreeNodeG<int> TreeNode;

#endif

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (!root) {
      return result;
    }
    vector<TreeNode *> curr;
    vector<TreeNode *> next = {root};
    while (next.size() != 0) {
      next.swap(curr);
      next.clear();
      result.push_back(vector<int>());
      vector<int> &resultCurrLine = result[result.size() - 1];

      for (TreeNode *node : curr) {
        resultCurrLine.push_back(node->val);
        if (node->left) {
          next.push_back(node->left);
        }
        if (node->right) {
          next.push_back(node->right);
        }
      }
    }
    return result;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(sample) {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  vector<vector<int>> groundTruth = {
      {3},
      {9, 20},
      {15, 7},
  };
  auto result = Solution().levelOrder(root);
  delete root;
  return result == groundTruth;
}
REGISTER_TEST(empty) {
  TreeNode *root = NULL;
  vector<vector<int>> groundTruth;
  auto result = Solution().levelOrder(root);
  return result == groundTruth;
}
#endif
