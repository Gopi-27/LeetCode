class Solution {
public:
    string getSmallestString(int n, int k) {
        // 73
        //   47 + 1(26)
        //   21 + 2(26)
        //   a + a + (19) + (26) + (26);
        int quo = k / 26;
        int rem = k % 26;
        string ans = "";
        while(ans.size() + (bool)(rem) + quo < n){
            if(!rem){
                rem = 26;
                quo--;
            }
            ans += 'a';
            rem--;
        }
        if(rem)ans += (char)('a' + rem - 1);
        for(int i = 0; i < quo; i++)ans += 'z';
        return ans;
    }
};





