class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int n = s.size();
        string ans = "";
        bool flag = 0;
        int first = 2 * (numRows - 1); // represented by 0
        int second = 0; // represented by 1
        // first row
        for(int i = 0; i < n; i += first)ans += s[i];
        first -= 2;
        second += 2;

        // middle rows        
        for(int i = 1; i < numRows - 1; i++){
            flag = 0;
            int j = i;
            while(j < n){
                ans += s[j];
                if(flag)j += second;
                else j += first;
                flag = !flag;
            }
            first -= 2;
            second += 2;
        }

        // last row 
        for(int i = numRows - 1; i < n; i += second)ans += s[i];
        return ans;
    }
};