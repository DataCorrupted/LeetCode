#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

template <class T>
ostream& operator << (ostream& o, vector<T>& v){
	o << '[';
	for (int i=0; i<v.size(); i++){
		o << v[i];
		if (i != v.size() - 1) {
			o << ", ";
		}
	}	
	o << "]\n";
	return o;
}

template <class T>
ostream& operator << ( ostream& o, vector<vector<T>>& v){
	o << "[\n";
	for (int i=0; i<v.size(); i++){
		o << " " << v[i];
	}
	o << "]\n";
	return o;
}

template <class K, class V>
ostream& operator << ( ostream& o, map<K, V>& m){
	o << "{";
	for (auto iter = m.begin(); iter != m.end(); ++iter){
		o << iter->first << ": " << iter->second ;
		auto next = iter;
		if (++next != m.end()) { o << ",  "; }
	}
	o << "}\n";
	return o;
}