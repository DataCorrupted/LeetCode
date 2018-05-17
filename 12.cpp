class Solution {
public:
    string intToRoman(int num) {
        const char* tens = "XCM";
        const char* fives = "VLD";
        const char* ones = "IXCM";
        
        string ans = "";
        int scale = 0;
        while (num != 0){
            const int temp = num % 10;
            num = num / 10;
            const char ten = tens[scale];
            const char five = fives[scale];
            const char one = ones[scale];
            
            if (temp <= 3){
                for (int i =0; i<temp; i++){
                    ans = one + ans;
                }
            } else if (temp == 4) {
                ans = five + ans;
                ans = one + ans;
            } else if (temp >=5 && temp <= 8) {
                for (int i =0; i<temp-5; i++){
                    ans = one + ans;
                }                
                ans = five + ans;
            } else if (temp == 9) {
                ans = ten + ans;
                ans = one + ans;
            } 
            scale ++;
        }
        return ans;
    }
};