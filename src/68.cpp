class Solution {
private:
	unsigned m_maxWidth;
	unsigned m_idx = 0;
	std::vector<string> m_line;
	std::vector<string> m_words;
	unsigned m_CharCnt;

	void greedyPickWords(){
		m_line.clear();
		m_CharCnt = 0;
		// The first word don't need a space. 
		int charCnt = -1;
		do {
			m_line.push_back(m_words[m_idx]);
			// At least one space is required
			charCnt += m_words[m_idx].size() + 1;
			m_CharCnt += m_words[m_idx].size();
			m_idx ++;
		} while (m_idx != m_words.size() && charCnt + m_words[m_idx].size() + 1 <= m_maxWidth);
	}

	string justifyLine(bool isLastLine){
		// First word can be added safely.
		string result(m_line[0]);
		// No Words in the middle
		if (m_line.size() == 1) {
			result += string(m_maxWidth - m_CharCnt, ' ');
			return result;
		}

		int spaceBetweenWords;
		int switchPoint = -1;
		int wordCnt = m_line.size();
		int spaceCnt = m_maxWidth - m_CharCnt;
		if (isLastLine) {
			spaceBetweenWords = 1;
		} else {
			// If can't divid equal, first #swichPoint spaces have to have one more.
			switchPoint = spaceCnt % (wordCnt - 1);
			spaceBetweenWords = spaceCnt / (wordCnt -1) + (switchPoint != 0);
		}
		// Words in the middle
		for (int i=1; i<wordCnt; i++){
			result += string(spaceBetweenWords, ' ') + m_line[i];
			// Passed switch point.
			if (i == switchPoint && !isLastLine) { spaceBetweenWords --; }
		}
		if (isLastLine){
			result += string(m_maxWidth - m_CharCnt - (wordCnt -1), ' ');
		} 
		return result;
	}

public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		m_maxWidth = maxWidth;
		m_words = words;

		std::vector<string> text;
		while (m_idx != words.size()){
			greedyPickWords();
			text.push_back(justifyLine(m_idx==words.size()));
		}
		return text;
	}

	static bool test0(){
		std::vector<string> v = {"This", "is", "an", "example", "of", "text", "justification."};
		std::vector<string> groundTruth = {
				"This    is    an",
				"example  of text",
				"justification.  "
		};
		int maxWidth = 16;
		auto result = Solution().fullJustify(v, maxWidth);
		return result == groundTruth;
	}
	static bool test1(){
		std::vector<string> v = {"What","must","be","acknowledgment","shall","be"};
		std::vector<string> groundTruth = {
				"What   must   be",
				"acknowledgment  ",
				"shall be        "
		};
		int maxWidth = 16;
		auto result = Solution().fullJustify(v, maxWidth);
		return result == groundTruth;
	}
	static bool test2(){
		std::vector<string> v = {
				"Science","is","what","we","understand","well","enough","to","explain",
				"to","a","computer.","Art","is","everything","else","we","do"
		};
		std::vector<string> groundTruth = {
				"Science  is  what we",
				"understand      well",
				"enough to explain to",
				"a  computer.  Art is",
				"everything  else  we",
				"do                  "
		};
		int maxWidth = 20;
		auto result = Solution().fullJustify(v, maxWidth);
		return result == groundTruth;
	}
	static bool test3(){
		std::vector<string> v = {
				"Don't","go","around","saying","the","world","owes","you","a","living;",
				"the","world","owes","you","nothing;","it","was","here","first."
		};
		std::vector<string> groundTruth = {
				"Don't  go  around  saying  the",
				"world  owes  you a living; the",
				"world owes you nothing; it was",
				"here first.                   ",
		};
		int maxWidth = 30;
		auto result = Solution().fullJustify(v, maxWidth);
		return result == groundTruth;
	}
};