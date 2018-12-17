#include <string>
#include <sstream>

template <class T>
struct IntervalG{
	T start;
	T end;
	IntervalG() : start(0), end(0) {}
	IntervalG(int s, int e) : start(s), end(e) {}	
	~IntervalG(){}

	stringstream toStringStream() {
		std::stringstream ss;
		ss << '[' << start << '-' << end << ']';
		return ss;
	}
	string toString() {
		return toStringStream().str();
	}
	friend ostream& operator << (ostream& o, IntervalG* root){
		o << root->toString();
		return o;
	}

	static bool intervalsEq(const IntervalG* lhs, const IntervalG* rhs){
		return (lhs->start == rhs->start) && (rhs->end == rhs->end);
	}
	friend bool operator == (const IntervalG& lhs, const IntervalG& rhs){
		return intervalsEq(&lhs, &rhs);
	}
};

