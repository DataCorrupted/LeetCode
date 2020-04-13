#define MATCH(str_a, str_b) \
int match = 0; \
for (size_t k = 0; k<6; k++) { \
    match += (str_a[k] == str_b[k])? 1: 0; \
}

#ifdef DEBUG
// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
private: 
    vector<string> wordlist;
    string secret;
    int num_guess;
public:
    Master(vector<string> wordlist, string secret): wordlist(wordlist), secret(secret), num_guess(0) {}
    int guess(string& word){
        this->num_guess ++;
        MATCH(secret, word);
        return match;
    }
    bool successful() {
        return this->num_guess <= 10;
    }
};
#endif

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        size_t len = wordlist.size();
        vector<vector<int>> matrix(len, vector<int>(len, 0));
        for (size_t i=0; i<len; i++){
            for (size_t j=0; j<len; j++){
                MATCH(wordlist[i], wordlist[j])
                matrix[i][j] = match;
            }
        }
        vector<size_t> possible;
        for (size_t i=0; i<len; i++) {
            possible.push_back(true);
        }

        for (int x = 0; x < 20; x++){
            vector<double> varlist;
            for (size_t i=0; i<len; i++){
                if (possible[i]){
                    double deg = 0;
                    double num = 0;
                    for (size_t j=0; j<len; j++){
                        if (i != j && possible[j]) {
                            deg += matrix[i][j];
                            num ++;
                        }
                    }
                    double avg = deg / num;
                    double var = 0;
                    for (size_t j=0; j<len; j++){
                        if (i != j && possible[j]) {
                            var += (matrix[i][j] - avg) * (matrix[i][j] - avg);
                        }
                    }
                    varlist.push_back(var);
                } else {
                    varlist.push_back(-1);
                }                
            }
            // Find the node to pick.
            double max = -1;
            size_t max_idx;
            for (size_t i=0; i<len; i++){
                if (varlist[i] > max) {
                    max = varlist[i];
                    max_idx = i;
                } 
            }

            // Now we pick it.
            int match = master.guess(wordlist[max_idx]);
            // We are done here.
            if (match == 6) { return; }
            for (size_t j=0; j<len; j++){
                // Since matrix[max_idx][max_idx] == 6, it will be labled as impossible too.
                if (matrix[max_idx][j] != match){
                    possible[j] = false;
                }
            }
        }
    }
};


#ifdef DEBUG
REGISTER_TEST(example0) {
  string secret = "eiowzz";
  vector<string> wordlist = {"acckzz","ccbazz","eiowzz","abcczz"};
  Master master(wordlist, secret);
  Solution().findSecretWord(wordlist, master);
  return master.successful();
}

REGISTER_TEST(example1) {
  string secret = "ccoyyo";
  vector<string> wordlist = {
    "wichbx","oahwep","tpulot","eqznzs","vvmplb","eywinm","dqefpt","kmjmxr","ihkovg","trbzyb","xqulhc","bcsbfw","rwzslk","abpjhw","mpubps","viyzbc","kodlta","ckfzjh","phuepp","rokoro","nxcwmo","awvqlr","uooeon","hhfuzz","sajxgr","oxgaix","fnugyu","lkxwru","mhtrvb","xxonmg","tqxlbr","euxtzg","tjwvad","uslult","rtjosi","hsygda","vyuica","mbnagm","uinqur","pikenp","szgupv","qpxmsw","vunxdn","jahhfn","kmbeok","biywow","yvgwho","hwzodo","loffxk","xavzqd","vwzpfe","uairjw","itufkt","kaklud","jjinfa","kqbttl","zocgux","ucwjig","meesxb","uysfyc","kdfvtw","vizxrv","rpbdjh","wynohw","lhqxvx","kaadty","dxxwut","vjtskm","yrdswc","byzjxm","jeomdc","saevda","himevi","ydltnu","wrrpoc","khuopg","ooxarg","vcvfry","thaawc","bssybb","ccoyyo","ajcwbj","arwfnl","nafmtm","xoaumd","vbejda","kaefne","swcrkh","reeyhj","vmcwaf","chxitv","qkwjna","vklpkp","xfnayl","ktgmfn","xrmzzm","fgtuki","zcffuv","srxuus","pydgmq"
  };
  Master master(wordlist, secret);
  Solution().findSecretWord(wordlist, master);
  return master.successful();
}
REGISTER_TEST(example2) {
  string secret = "vftnkr";
  vector<string> wordlist = {
    "mjpsce","giwiyk","slbnia","pullbr","ezvczd","dwkrmt","qgzebh","wvhhlm","kqbmny","zpvrkz","pdwxvy","gilywa","gmrrdc","vvqvla","rmjirt","qmvykq","mhbmuq","unplzn","qkcied","eignxg","fbfgng","xpizga","twubzr","nnfaxr","skknhe","twautl","nglrst","mibyks","qrbmpx","ukgjkq","mhxxfb","deggal","bwpvsp","uirtak","tqkzfk","hfzawa","jahjgn","mteyut","jzbqbv","ttddtf","auuwgn","untihn","gbhnog","zowaol","feitjl","omtiur","kwdsgx","tggcqq","qachdn","dixtat","hcsvbw","chduyy","gpdtft","bjxzky","uvvvko","jzcpiv","gtyjau","unsmok","vfcmhc","hvxnut","orlwku","ejllrv","jbrskt","xnxxdi","rfreiv","njbvwj","pkydxy","jksiwj","iaembk","pyqdip","exkykx","uxgecc","khzqgy","dehkbu","ahplng","jomiik","nmcsfe","bclcbp","xfiefi","soiwde","tcjkjp","wervlz","dcthgv","hwwghe","hdlkll","dpzoxb","mpiviy","cprcwo","molttv","dwjtdp","qiilsr","dbnaxs","dbozaw","webcyp","vftnkr","iurlzf","giqcfc","pcghoi","zupyzn","xckegy"
  };
  Master master(wordlist, secret);
  Solution().findSecretWord(wordlist, master);
  return master.successful();
}
#endif