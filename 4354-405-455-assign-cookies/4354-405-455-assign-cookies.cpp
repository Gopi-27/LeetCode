class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0;
        int i = 0;
        int cnt = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
                j++;
                cnt++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};