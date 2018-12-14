#ifdef DEBUG
#include "TreeNodeG.hpp"

typedef TreeNodeG<int> TreeNode;

#endif

class Solution {
public:
	int maxDepthVal = 0;
	void DFSTraverse(TreeNode* node, int curDepth){
		if (node) { 
			DFSTraverse(node->left, curDepth+1);
			DFSTraverse(node->right, curDepth+1);
		} else {
			if (curDepth > maxDepthVal){
				maxDepthVal = curDepth;
			}
		}
	}
	int maxDepth(TreeNode* root) {
		DFSTraverse(root, 0);
		return maxDepthVal;
	}
};


#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(empty){
	TreeNode* root = NULL;
	int groundTruth = 0;
	auto result = Solution().maxDepth(root);
	return result == groundTruth;
}
REGISTER_TEST(sample0){
	TreeNode* root = 
		new TreeNode(3,
			new TreeNode(9),
			new TreeNode(20,
				new TreeNode(15),
				new TreeNode(7)
			)
		);
	int groundTruth = 3;
	auto result = Solution().maxDepth(root);
	delete root;
	return result == groundTruth;
}
#endif