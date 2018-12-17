#include <stack>
#include <string>
#include <sstream>

template <class T>
struct TreeNodeG{
	T val;
	TreeNodeG* left;
	TreeNodeG* right;
	TreeNodeG(T x, TreeNodeG* left = NULL, TreeNodeG* right = NULL): val(x), left(left), right(right) {};
	~TreeNodeG(){
		if (left)  { delete left; }
		if (right) { delete right; }
	}

	stringstream toStringStream() {
		std::stringstream ss;
		std::stack<TreeNodeG*> nodeStack; 	nodeStack.push(this);
		std::stack<int> levelStack; 		levelStack.push(0);

		TreeNodeG* curr = NULL;
		int level = 0;
		while (nodeStack.size() != 0){
			curr = nodeStack.top(); 	nodeStack.pop();
			level = levelStack.top();	levelStack.pop();

			for (int i=0; i<level; i++){
				ss << "|--";
			}
			if (curr) {
				ss << curr->val << "\n";
			} else {
				ss << "null" << "\n";
				continue;
			}
			if (!curr->right && !curr->left) { continue; }
			nodeStack.push(curr->right);	levelStack.push(level+1);
			nodeStack.push(curr->left); 	levelStack.push(level+1);
		}		
		return ss;
	}
	string toString() {
		return toStringStream().str();
	}
	friend ostream& operator << (ostream& o, TreeNodeG* root){
		o << root->toString();
		return o;
	}

	static bool treesEq(const TreeNodeG* lhs, const TreeNodeG* rhs){
		if (!lhs && !rhs) { return true; }
		if (!lhs || !rhs) { return false; }
		return (lhs->val == rhs->val) && (treesEq(lhs->left, rhs->left) && (treesEq(lhs->right, rhs->right)));
	}
	friend bool operator == (TreeNodeG& lhs, TreeNodeG& rhs){
		return listsEq(&lhs, &rhs);
	}
};

