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
};
