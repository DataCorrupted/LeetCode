#include <iostream>

template <class T>
struct ListNodeG {
	T val;
	ListNodeG *next;
	ListNodeG(T x, ListNodeG* n = NULL) : val(x), next(n) {};
	~ListNodeG(){
		if (next) { delete next; }
	}

	// This function cannot be overloaded because both operand is pointer.
	static bool listsEq(const ListNodeG* lhs, const ListNodeG* rhs){
		if (!lhs && !rhs) { return true; }
		if (!lhs || !rhs) { return false; }
		return (lhs->val == rhs->val) && (listsEq(lhs->next, rhs->next));
	}

	friend ostream& operator << (ostream& o, const ListNodeG* node){
		o << node->val << " ";
		if (node->next){
			o << node->next;
		} else{
			o << "$\n";
		}
		return o;
	}
};
 
