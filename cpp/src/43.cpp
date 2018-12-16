class Solution {
public:
	string add(string num1, string num2){
		if (num1.size() < num2.size()){
			std::swap(num1, num2);
		}
		num2 = string(num1.size() - num2.size(), '0') + num2;
		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());
		string ans;
		int m = 0, cur = 0;
		for (unsigned i=0; i<num1.size(); i++){
			char c1 = num1[i], c2 = num2[i];
			cur = c1 - 48 + c2 - 48 + m;
			m = cur / 10;
			cur %= 10;
			ans += (char) (cur + 48);
		}
		if (m != 0) { ans += (char) (m + 48); }
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
	string mul(string num, int k){
		std::reverse(num.begin(), num.end());
		string ans;
		int m = 0, cur = 0;
		for (unsigned i=0; i<num.size(); i++){
			char c = num[i];
			cur = (c - 48) * k + m;
			m = cur / 10;
			cur %= 10;
			ans += (char) (cur + 48);
		}
		if (m != 0) { ans += (char) (m + 48); }
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") { return "0"; }
		string ans;
		std::reverse(num1.begin(), num1.end());
		for (unsigned i = 0; i<num1.size(); i++){
			ans = add(ans, mul(num2, num1[i]-48) + string(i, '0'));
		}
		return ans;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(test_add_0){
	string num1("3"), num2("997");
	string groundTruth("1000");
	return Solution().add(num1, num2) == groundTruth;
}
REGISTER_TEST(test_add_1){
	string num1("123"), num2("956");
	string groundTruth("1079");
	return Solution().add(num1, num2) == groundTruth;
}
REGISTER_TEST(test_mul_0){
	int k = 4;
	string num("253");
	string groundTruth("1012");
	return Solution().mul(num, k) == groundTruth;
}
REGISTER_TEST(test_mul_1){
	int k = 9;
	string num("123");
	string groundTruth("1107");
	return Solution().mul(num, k) == groundTruth;
}
REGISTER_TEST(example_1){
	string num1("2"), num2("3");
	string groundTruth("6");
	return Solution().multiply(num1, num2) == groundTruth;
}
REGISTER_TEST(example_2){
	string num1("123"), num2("456");
	string groundTruth("56088");
	return Solution().multiply(num1, num2) == groundTruth;
}
REGISTER_TEST(example_3){
	string num1("123"), num2("0");
	string groundTruth("0");
	return Solution().multiply(num1, num2) == groundTruth;
}
#endif