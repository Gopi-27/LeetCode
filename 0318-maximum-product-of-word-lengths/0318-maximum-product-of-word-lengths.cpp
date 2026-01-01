class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>Mask(n);
        for(int i = 0; i < n; i++){
            int mask = 0;
            for(char& ch : words[i])mask |= (1 << (ch - 'a'));
            Mask[i] = mask;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int l = words[i].size();
            for(int j = i + 1; j < n; j++){
                if((Mask[i] & Mask[j]) == 0)ans = max(ans,(int)words[j].size() * l);
            }
        }
        return ans;
    }
};