class Solution {
public:
    const bool eq(const char a, const char b) const {
        return (a == b || b == '?');
    }
    bool isMatch(string s, string p) {
        int idx_s=0, idx_p=0;
        int len_s = s.size();
        int len_p = p.size();
        bool has_star = false;
        int star_s, star_p;
        while (idx_s < len_s) {
            if (idx_p < len_p && eq(s[idx_s], p[idx_p])){
                idx_s ++;
                idx_p ++;
            } else if (idx_p < len_p && p[idx_p] == '*') {
                while (idx_p < len_p && p[idx_p] == '*') { idx_p ++; }
                if (idx_p == len_p) { return true; }
                has_star = true;
                star_s = idx_s;
                star_p = idx_p;
            } else if (has_star){
                star_s ++;
                idx_p = star_p;
                idx_s = star_s;
            } else {
                return false;
            }
        }
        while (idx_p < len_p && p[idx_p] == '*') { idx_p ++; }
        return (idx_p == len_p && idx_s == len_s);
    }
};