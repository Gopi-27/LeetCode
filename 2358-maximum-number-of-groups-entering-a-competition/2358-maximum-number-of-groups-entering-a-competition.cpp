class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int grps = sqrt(n + n);
        // cout << grps;
        if(grps * (grps + 1) <= n + n)return grps;
        return grps - 1;
    }
};