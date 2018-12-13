class Solution {
public:
	unsigned m_ptr = 0;
	std::string m_str;
	bool matchSpace(){
		while (m_str[m_ptr] == ' ') {m_ptr ++;}
		return true;
	}

	bool matchSign(){
		if (m_str[m_ptr] == '+' || m_str[m_ptr] == '-') { m_ptr++; }
		return true;
	}

	bool isDigit(char c){
		return (c >= '0') && (c <= '9');
	}
	bool matchStarDigits(){
		while (isDigit(m_str[m_ptr])) { m_ptr++; }
		return true;
	}
	bool matchPlusDigits(){
		if (isDigit(m_str[m_ptr])) {
			m_ptr++;
			return matchStarDigits();
		} else {
			return false;
		}
	}
	bool matchDecimal(bool haveDigitsBeforeDecimal){
		if (m_str[m_ptr] == '.') { 
			m_ptr++; 
			// If there is digits before decimal, we can have no digits after
			// else the digits after cannot be empty.
			// This special rule is added to fit test 12 & 13.
			// However, I still believe that test 13 should be false.
			return (haveDigitsBeforeDecimal) ? matchStarDigits(): matchPlusDigits();
		}  else {
			// The presense of Question Mark means that even if there is
			// no match we can return true.
			return haveDigitsBeforeDecimal;
		}
	}
	bool matchExp(){
		if (m_str[m_ptr] == 'e') {
			m_ptr++;
			return matchSign() && matchPlusDigits();
		} else {
			return true;
		}
	}

	bool matchBase(){
		if (!matchPlusDigits()){
			return matchDecimal(false);
		} else {
			return matchDecimal(true);
		}
	}

	bool isNumber(string s) {
		m_str = s;
		bool matchResult = matchSpace() && matchSign() && matchBase() && matchExp() && matchSpace();
		return matchResult && (m_ptr == m_str.size());
	}
};

#ifdef DEBUG
#include "debugUtil.h"
REGISTER_TEST(00){
	std::string s = " 0 ";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(01){
	std::string s = " 0.1  ";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(02){
	std::string s = "-3.452";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(03){
	std::string s = "6666666a";
	bool groundTruth = false;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(04){
	std::string s = "-3.a52";
	bool groundTruth = false;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(05){
	std::string s = " 99e2.5 ";
	bool groundTruth = false;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(06){
	std::string s = "1";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(07){
	std::string s = "-+3";
	bool groundTruth = false;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(08){
	std::string s = "2e10";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(09){
	std::string s = "0.786e23";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(10){
	std::string s = "e1";
	bool groundTruth = false;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(11){
	std::string s = "0000.1001";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(12){
	std::string s = ".";
	bool groundTruth = false;
	return Solution().isNumber(s) == groundTruth;
}
REGISTER_TEST(13){
	std::string s = "3.";
	bool groundTruth = true;
	return Solution().isNumber(s) == groundTruth;
}
#endif