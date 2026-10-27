class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>Ans;
        string s = "";
        for(int i = 0; i < n; i++)s += '.';
        Ans.push_back(s);
        for(int j = 0; j < m - 1; j++){
            s = "";
            for(int i = 0; i < n - 1; i++)s += '#';
            s += '.';
            Ans.push_back(s);
        }
        return Ans;
    }
};