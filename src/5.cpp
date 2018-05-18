class Solution {
public:
	const vector<int> generateMaxPaliVec(const string str) const{
		vector<int> p;
		int max_reach = 0;
		int max_pos = 0;
		for (int i=0; i<str.size(); i++){
			if (max_reach > i){
				p.push_back(min(p[2*max_pos - i], max_reach - i));
			} else {
				p.push_back(1);
			}
			while (i - p[i] >= 0 && i + p[i] < str.size() 
			  && str[i + p[i]] == str[i - p[i]]){
				p[i] ++;
			}
			if (p[i] + i > max_reach){
				max_reach = p[i] + i;
				max_pos = i;
			}
		}
		return p;
	}
	string longestPalindrome(string s) const {
		string extended_str;
		for (int i=0; i<s.size(); i++){
			extended_str += '_';
			extended_str += s[i];
		}
		extended_str += '_';
		const vector<int> pali_vec = generateMaxPaliVec(extended_str);
		const int max_pos = 
			distance(pali_vec.begin(), max_element(pali_vec.begin(), pali_vec.end()));
		// Max reach includes the central one.
		const int max_reach = pali_vec[max_pos] - 1;
		const int begin = max_pos / 2 - max_reach / 2;
		const int len = (max_reach / 2) * 2 + (max_pos & 0x1);
		return s.substr(begin, len);
	}
};