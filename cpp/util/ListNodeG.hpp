#include <iostream>
#include <vector>

template <class T>
struct ListNodeG {
	T val;
	ListNodeG *next;
	ListNodeG(T x, ListNodeG* n = NULL) : val(x), next(n) {};
	~ListNodeG(){
		if (next) { delete next; }
	}

	static ListNodeG<T>* vectorToListNode(std::vector<T> valVec){
		std::vector<ListNodeG<int>*> nodeVec;
		for (T x: valVec){
			nodeVec.push_back(new ListNodeG(x));
		}
		for (unsigned i = 1; i < valVec.size(); i++){
			nodeVec[i-1]->next = nodeVec[i];
		}
		return (nodeVec.size() == 0) ? NULL: nodeVec[0];
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
 
