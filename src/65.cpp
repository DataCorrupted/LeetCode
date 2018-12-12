class Solution {
public:
	int m_ptr = 0;
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
		int curr = m_ptr;
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

	static bool test0(){
		std::string s = " 0 ";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test1(){
		std::string s = " 0.1  ";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test2(){
		std::string s = "-3.452";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test3(){
		cout << "test3 is composed of more tests(test 4-13)." << endl;
		cout << "test4 passed ... " << boolalpha << Solution::test4() << endl;
		cout << "test5 passed ... " << boolalpha << Solution::test5() << endl;
		cout << "test6 passed ... " << boolalpha << Solution::test6() << endl;
		cout << "test7 passed ... " << boolalpha << Solution::test7() << endl;
		cout << "test8 passed ... " << boolalpha << Solution::test8() << endl;
		cout << "test9 passed ... " << boolalpha << Solution::test9() << endl;
		cout << "test10 passed ... " << boolalpha << Solution::test10() << endl;
		cout << "test11 passed ... " << boolalpha << Solution::test11() << endl;
		cout << "test12 passed ... " << boolalpha << Solution::test12() << endl;
		return true;
	}
	static bool test4(){
		std::string s = "-3.a52";
		bool groundTruth = false;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test5(){
		std::string s = " 99e2.5 ";
		bool groundTruth = false;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test6(){
		std::string s = "1";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test7(){
		std::string s = "-+3";
		bool groundTruth = false;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test8(){
		std::string s = "2e10";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test9(){
		std::string s = "0.786e23";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test10(){
		std::string s = "e1";
		bool groundTruth = false;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test11(){
		std::string s = "0000.1001";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test12(){
		std::string s = ".";
		bool groundTruth = false;
		return Solution().isNumber(s) == groundTruth;
	}
	static bool test13(){
		std::string s = "3.";
		bool groundTruth = true;
		return Solution().isNumber(s) == groundTruth;
	}
};