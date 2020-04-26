#ifdef DEBUG

#include "TreeNodeG.hpp"
typedef TreeNodeG<int> TreeNode;

#endif

class Solution {
 private:
  TreeNode *left;
  TreeNode *right;

 public:
  bool isSubTreeSymmetric(TreeNode *left, TreeNode *right) {
    // Both are NULL;
    if (!left && !right) {
      return true;
    }
    // One of then are NULL;
    if (!left || !right) {
      return false;
    }
    // Both are not NULL
    return (left->val == right->val) &&
           isSubTreeSymmetric(left->left, right->right) &&
           isSubTreeSymmetric(left->right, right->left);
  }
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    return isSubTreeSymmetric(root->left, root->right);
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(empty) {
  TreeNode *root = NULL;
  bool groundTruth = true;
  bool result = Solution().isSymmetric(root);
  delete root;
  return result == groundTruth;
}
REGISTER_TEST(0) {
  TreeNode *root =
      new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                   new TreeNode(2, new TreeNode(4), new TreeNode(3)));
  bool groundTruth = true;
  bool result = Solution().isSymmetric(root);
  delete root;
  return result == groundTruth;
}
REGISTER_TEST(1) {
  TreeNode *root = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(3)),
                                new TreeNode(2, NULL, new TreeNode(3)));
  bool groundTruth = false;
  bool result = Solution().isSymmetric(root);
  delete root;
  return result == groundTruth;
}
#endif
