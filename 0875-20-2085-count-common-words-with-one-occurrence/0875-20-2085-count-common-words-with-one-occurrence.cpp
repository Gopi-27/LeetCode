class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mpp1;
        unordered_map<string,int>mpp2;
        for(string b : words1)mpp1[b]++;
        for(string b : words2)mpp2[b]++;
        int cnt = 0;
        for(string b : words1){
            if(mpp1[b] == 1 && mpp2[b] == 1)cnt++;
        }
        return cnt;
    }
};