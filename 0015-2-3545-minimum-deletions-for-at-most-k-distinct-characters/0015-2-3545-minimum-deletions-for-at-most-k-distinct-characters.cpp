class Solution {
public:
    int minDeletion(string s, int k) {
       int frr[26] = {0};
        for(char it : s)frr[it - 'a']++;
        vector<int>gp;
        for(int i = 0; i < 26; i++)if(frr[i] > 0)gp.push_back(frr[i]);
        int cnt = gp.size();
        sort(gp.begin(),gp.end());
        int min = 0;
        int idx = 0;
        while(cnt > k){
            min += gp[idx++];
            cnt--;
        }
        return min;
    }
};