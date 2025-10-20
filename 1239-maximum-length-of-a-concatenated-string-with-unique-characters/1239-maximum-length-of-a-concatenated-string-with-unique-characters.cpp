class Solution {
public:
    int GetCurMask(string& s){
        int cur_mask = 0;
        for(auto ch : s){
            int k = (ch - 'a');
            int mask = (1 << k);
            if((cur_mask & mask) == 0)cur_mask = (cur_mask | mask);
            else return -1;
        }
        return cur_mask;
    }
    int rec(int level,int prev_mask,vector<string>& arr){
        if(level < 0)return 0;
        int non_pick = rec(level - 1,prev_mask,arr);
        int pick = 0;
        int cur_mask = GetCurMask(arr[level]);
        if(cur_mask != -1 && (prev_mask & cur_mask) == 0){
            pick = arr[level].size() + rec(level - 1,(prev_mask | cur_mask),arr);
        }
        return max(non_pick,pick);
    }
    int maxLength(vector<string>& arr) {
        return rec(arr.size() - 1,0,arr);
    }
};