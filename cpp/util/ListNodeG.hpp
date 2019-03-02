#include <iostream>
#include <vector>
#include <sstream>

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
	stringstream toStringStream() {
		std::stringstream ss;
		ListNodeG* curr = this;
		while (curr){
			ss << curr->val << " " ;
			curr = curr->next;
		}
		ss << "$\n";
		return ss;
	}
	string toString() {
		return toStringStream().str();
	}
	friend ostream& operator << (ostream& o, ListNodeG* node){
		o << node->toString();
		return o;
	}

	// This function cannot be overloaded because both operand is pointer.
	inline static bool listsEq(const ListNodeG* lhs, const ListNodeG* rhs){
		if (!lhs && !rhs) { return true; }
		if (!lhs || !rhs) { return false; }
		return (lhs->val == rhs->val) && (listsEq(lhs->next, rhs->next));
	}
	friend bool operator == (ListNodeG& lhs, ListNodeG& rhs){
		return listsEq(&lhs, &rhs);
	}
};
 
