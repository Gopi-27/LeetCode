class Solution {
public:
    int rec(int level,bool flag,vector<int>Dig,int val,vector<vector<vector<int>>>& Dp){

        if(level >= Dig.size()){
            return val;
        }

        if(Dp[level][val][flag] != -1)return Dp[level][val][flag];
        int ans = 0;
        if(flag){
            for(int i = 0; i < Dig[level]; i++){
                if(i == 1)ans += rec(level + 1,0,Dig,val + 1,Dp);
                else ans += rec(level + 1,0,Dig,val,Dp);
            }
            if(Dig[level] == 1)ans += rec(level + 1,1,Dig,val + 1,Dp);
            else ans += rec(level + 1,1,Dig,val,Dp);
        }else{
            for(int i = 0; i < 10; i++){
                if(i == 1)ans += rec(level + 1,0,Dig,val + 1,Dp);
                else ans += rec(level + 1,0,Dig,val,Dp);
            }
        } 
        return Dp[level][val][flag] = ans;
    }
    int countDigitOne(int n) {
        vector<int>Dig;
        while(n > 0){
            Dig.push_back(n % 10);
            n /= 10;
        }
        reverse(Dig.begin(),Dig.end());
        vector<vector<vector<int>>>Dp(Dig.size(),vector<vector<int>>(Dig.size(),vector<int>(2,-1)));
        return rec(0,1,Dig,0,Dp);
    }
};