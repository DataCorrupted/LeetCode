#ifdef DEBUG
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <TreeNodeG.hpp>
typedef TreeNodeG<int> TreeNode;
#endif

class Solution {
 public:
  void rightSideView(TreeNode *node, unsigned depth, vector<int> &vec) {
    if (depth == vec.size()) {
      vec.push_back(node->val);
    }
    if (node->right) {
      rightSideView(node->right, depth + 1, vec);
    }
    if (node->left) {
      rightSideView(node->left, depth + 1, vec);
    }
  }
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    if (root) {
      rightSideView(root, 0, result);
    }
    return result;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                                new TreeNode(3, nullptr, new TreeNode(4)));
  vector<int> groundTruth({1, 3, 4});
  vector<int> result = Solution().rightSideView(root);
  delete root;
  return result == groundTruth;
}
REGISTER_TEST(example2) {
  TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr),
                                new TreeNode(3));
  vector<int> groundTruth({1, 3, 4});
  vector<int> result = Solution().rightSideView(root);
  delete root;
  return result == groundTruth;
}
#endif