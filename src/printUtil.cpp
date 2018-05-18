#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

template <class T>
ostream& operator << (ostream& o, vector<T> v){
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
ostream& operator << ( ostream& o, vector<vector<T>> v){
	o << "[\n";
	for (int i=0; i<v.size(); i++){
		o << " " << v[i];
	}
	o << "]\n";
	return o;
}
