class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int limit = skill[0] + skill[n - 1];
        long long ans = 0;
        for(int i = 0; i < n/2; i++){
            if(limit != skill[i] + skill[n - i - 1])return -1;
            ans += skill[i] * skill[n - i - 1];
        }
        return ans;
    }
};

// 1 2 3 3 4 5