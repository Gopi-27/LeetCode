class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int>Match(n);
        for(vector<int>& p : pairs){
            Match[p[0]] = p[1];
            Match[p[1]] = p[0];
        }
        int unhappy = 0;
        for(int i = 0; i < n; i++){
            vector<int>& mylst = preferences[i];
            int j = 0;
            bool flag = 0;
            while(!flag && mylst[j] != Match[i]){
                int frnd = mylst[j];
                vector<int>& flst = preferences[frnd];
                int k = 0;
                while(flst[k] != Match[frnd]){
                    if(flst[k] == i){
                        flag = 1;
                        break;
                    }
                    
                    k++;
                }
                // cout << j << " -> ";
                j++;
            }
            if(flag)unhappy++;
        }
        return unhappy;
    }
};