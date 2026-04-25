class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>ans;
        int n = words.size();
        for(int i = 0; i < n; i++){
            char si = words[i][0];
            char ei = words[i][3];
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                char sj = words[j][0];
                char ej = words[j][3];
                if(si == sj){
                    for(int k = 0; k < n; k++){
                        if(i == k || j == k)continue;
                        char sk = words[k][0];
                        char ek = words[k][3];
                        if(ei == sk){
                            for(int l = 0; l < n; l++){
                                if(i == l || j == l || k == l)continue;
                                char sl = words[l][0];
                                char el = words[l][3];
                                if(ej == sl && ek == el){
                                    ans.push_back({words[i],words[j],words[k],words[l]});
                                }
                            }
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};