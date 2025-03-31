class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        int rows = ( s[4] - s[1] ) + 1;
        int cols = (s[3] - s[0]) + 1;
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < rows; j++){
                string temp = "";
                char val1 = s[0] + i;
                char val2 = s[1] + j;
                temp = temp + val1 + val2;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};