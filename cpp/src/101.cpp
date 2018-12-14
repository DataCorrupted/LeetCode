#ifdef DEBUG
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x, TreeNode* left = NULL, TreeNode* right = NULL): val(x), left(left), right(right) {};
	~TreeNode(){
		if (left)  { delete left; }
		if (right) { delete right; }
	}
};
#endif

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		// Unimplemented.
		return root;
	}
};

#ifdef DEBUG
#include "debugUtil.h"

REGISTER_TEST(empty){
	TreeNode* root = NULL;
	bool groundTruth = true;
	bool result = Solution().isSymmetric(root);
	delete root;
	return result == groundTruth;
}
REGISTER_TEST(0){
	TreeNode* root = 
		new TreeNode(1
			new TreeNode(2,
				new TreeNode(3),
				new TreeNode(4)),
			new TreeNode(2, 
				new TreeNode(4),
				new TreeNode(3))
		);
	bool groundTruth = true;
	bool result = Solution().isSymmetric(root);
	delete root;
	return result == groundTruth;
}
REGISTER_TEST(1){
	TreeNode* root = 
		new TreeNode(1
			new TreeNode(2,
				NULL,
				new TreeNode(3)),
			new TreeNode(2, 
				NULL,
				new TreeNode(3))
		);
	bool groundTruth = true;
	bool result = Solution().isSymmetric(root);
	delete root;
	return result == groundTruth;	
}
#endif
