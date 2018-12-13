class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string ans;
		if (a.size() > b.size()){ swap(a, b); }
		while (a.size() < b.size()){ a += '0'; }
		
		int m = 0;
		for (int i=0; i<a.size(); i++){
			int temp = (a[i] - '0') + (b[i] - '0') + m;
			m = temp / 2;
			ans += ((temp % 2) + '0');
		}
		if (m == 1){ ans += '1'; }
		reverse(ans.begin(), ans.end());
		return ans;
	}
};