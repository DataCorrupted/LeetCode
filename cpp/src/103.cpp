#ifdef DEBUG
#include "TreeNodeG.hpp"

typedef TreeNodeG<int> TreeNode;

#endif

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) { return result; }
		vector<TreeNode*> curr;
		vector<TreeNode*> next = {root};
		bool doReverse = false;
		while (next.size() != 0){
			next.swap(curr);
			next.clear();

			result.push_back(vector<int>());
			vector<int>& resultCurrLine = result[result.size() - 1];

			for (TreeNode* node: curr){
				resultCurrLine.push_back(node->val);
				if (node->left) { next.push_back(node->left); }
				if (node->right) { next.push_back(node->right); }
			}
			if (doReverse) { 
				std::reverse(resultCurrLine.begin(), resultCurrLine.end()); 
			}
			doReverse = !doReverse;
		}
		return result;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(empty){
	TreeNode* root = NULL;
	vector<vector<int>> groundTruth;
	auto result = Solution().zigzagLevelOrder(root);
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
	vector<vector<int>> groundTruth = {
		{3},
		{20,9},
		{15,7},
	};
	auto result = Solution().zigzagLevelOrder(root);
	delete root;
	return result == groundTruth;
}
REGISTER_TEST(sample1){
	TreeNode* root = 
		new TreeNode(1,
			new TreeNode(2,
				new TreeNode(4),
				NULL
			),
			new TreeNode(3,
				NULL,
				new TreeNode(5)
			)
		);
	vector<vector<int>> groundTruth = {
		{1},
		{3, 2},
		{4, 5},
	};
	auto result = Solution().zigzagLevelOrder(root);
	delete root;
	return result == groundTruth;
}
#endif
