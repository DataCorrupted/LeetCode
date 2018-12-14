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

class Solution{
public:
	bool isSameTree(TreeNode* p, TreeNode* q){
		// Both are empty;
		if (!p && !q) { return true; }
		// One of the is empty;
		if (!p || !q) { return false; }
		// Both is not empty;
		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

#ifdef DEBUG
#include "debugUtil.h"

REGISTER_TEST(0){
	TreeNode* p = 
			new TreeNode(1,
				new TreeNode(2),
				new TreeNode(3)
			);
	TreeNode* q = 
			new TreeNode(1,
				new TreeNode(2),
				new TreeNode(3)
			);
	bool groundTruth = true;
	bool result = Solution().isSameTree(p, q);
	delete p; delete q;
	return result == groundTruth;
}
REGISTER_TEST(1){
	TreeNode* p = 
			new TreeNode(1,
				NULL,
				new TreeNode(2)
			);
	TreeNode* q = 
			new TreeNode(1,
				new TreeNode(2),
				NULL
			);
	bool groundTruth = false;
	bool result = Solution().isSameTree(p, q);
	delete p; delete q;
	return result == groundTruth;
}
REGISTER_TEST(2){
	TreeNode* p = 
			new TreeNode(1,
				new TreeNode(2),
				new TreeNode(1)
			);
	TreeNode* q = 
			new TreeNode(1,
				new TreeNode(1),
				new TreeNode(2)
			);
	bool groundTruth = false;
	bool result = Solution().isSameTree(p, q);
	delete p; delete q;
	return result == groundTruth;
}
#endif