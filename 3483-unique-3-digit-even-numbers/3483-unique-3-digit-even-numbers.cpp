class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
            if(!digits[i])continue;
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                for(int k = 0; k < n; k++){
                    if(i == k || j == k || digits[k] % 2)continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(!st.count(num))st.insert(num);
                }
            }
        }
        return st.size();
    }
};