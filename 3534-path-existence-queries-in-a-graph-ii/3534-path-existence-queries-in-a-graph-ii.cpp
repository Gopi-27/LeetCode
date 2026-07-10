class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>Nodes;
        for(int i = 0; i < n; i++)Nodes.push_back({nums[i],i});
        sort(Nodes.begin(),Nodes.end());
        vector<int>Par(n);
        for(int j = 0; j < n; j++)Par[Nodes[j].second] = j;

        vector<vector<int>>Dp(n,vector<int>(20));
        int ptr = 0;
        for(int i = 0; i < n; i++){
            while(ptr < n && Nodes[ptr].first - Nodes[i].first <= maxDiff)ptr++;
            if(i == ptr - 1)Dp[i][0] = -1;
            else Dp[i][0] = ptr - 1;
        }   

        for(int j = 1; j < 20; j++){
            for(int i = 0; i < n; i++){
                if(Dp[i][j - 1] == -1)Dp[i][j] = -1;
                else Dp[i][j] = Dp[Dp[i][j - 1]][j - 1];
            }
        } 

        vector<int>Ans;
        for(vector<int>& q : queries){
            int u = Par[q[0]];
            int v = Par[q[1]];
            if(u == v){
                Ans.push_back(0);
                continue;
            }
            if(u > v)swap(u,v);
            int stps = 0;
            int j = 0;
            while(1){
                while(Dp[u][j] < v){
                    if(Dp[u][j] == -1)break;
                    j++;
                }
                if(Dp[u][j] == -1){
                    if(j == 0){
                        Ans.push_back(-1);
                        break;
                    }else{
                        stps += 1 << (j - 1);
                        u = Dp[u][j - 1];
                        j = 0;
                    }
                }else if(Dp[u][j] == v){
                    stps += 1 << j;
                    Ans.push_back(stps);
                    break;
                }else if(Dp[u][j] > v){
                    if(j == 0){
                        stps++;
                        Ans.push_back(stps);
                        break;
                    }else{
                        stps += 1 << (j - 1);
                        u = Dp[u][j - 1];
                        j = 0;
                    }
                }else{
                    cout << "Something Wrong" << endl;
                    break;
                }
            }
        }  
        return Ans;  
    }
};