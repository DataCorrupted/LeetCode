/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef DEBUG
#include<TreeNodeG.hpp>
typedef TreeNodeG<int> TreeNode;
#endif

class Solution {
private:
    TreeNode* locate(TreeNode* root, int x) {
        if (root == nullptr) {
            return nullptr;
        }
        if (x == root->val) {
            return root;
        } else {
            TreeNode* left = locate(root->left, x);
            if (left) { return left; }
            TreeNode* right = locate(root->right, x);
            if (right) { return right; }
        }
        return nullptr;
    }
    int count(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + count(root->right) + count(root->left);
        }
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* pick = locate(root, x);
        int his_parent_max = count(pick);
        if (root->val == x) {
            his_parent_max ++;
        }
        int my_parent_max = n - his_parent_max;
        
        int left_count = count(pick->left);
        int right_count = count(pick->right);
        int my_child_max = std::max(left_count, right_count);
        int his_child_max = n - my_child_max;
        cout << my_parent_max << " " << his_parent_max << " " << my_child_max << " " << his_child_max;
        return (my_parent_max > his_parent_max) || (my_child_max > his_child_max);
    }
};

#ifdef DEBUG
REGISTER_TEST(example0) {
  TreeNode *root = new TreeNode(1, 
    new TreeNode(2,
        new TreeNode(4,
            new TreeNode(8),
            new TreeNode(9)
        ),
        new TreeNode(5,
            new TreeNode(10),
            new TreeNode(11)
        )
    ), 
    new TreeNode(3,
        new TreeNode(6),
        new TreeNode(7)
    )
  );
  int n = 11;
  int x = 3;
  bool groundTruth = true;
  bool result = Solution().btreeGameWinningMove(root, n, x);
  delete root;
  return result == groundTruth;
}
REGISTER_TEST(example1) {
  TreeNode *root = new TreeNode(1, 
    new TreeNode(2,
        new TreeNode(4),
        new TreeNode(5)
    ), 
    new TreeNode(3)
  );
  int n = 5;
  int x = 2;
  bool groundTruth = false;
  bool result = Solution().btreeGameWinningMove(root, n, x);
  delete root;
  return result == groundTruth;
}
REGISTER_TEST(example2) {
  TreeNode *root = new TreeNode(1, 
    new TreeNode(2,
        new TreeNode(4,
            new TreeNode(8),
            new TreeNode(9)
        ),
        new TreeNode(5)
    ), 
    new TreeNode(3,
        new TreeNode(6),
        new TreeNode(7)
    )
  );
  int n = 9;
  int x = 2;
  bool groundTruth = false;
  bool result = Solution().btreeGameWinningMove(root, n, x);
  delete root;
  return result == groundTruth;
}
#endif