class Solution {
public:
    long long Dp[17][10][3][17][2][2];
    long long rec(int idx,int prev,int dir,int cnt,bool flag,bool sflag,vector<int>& Dig){
        if(idx >= Dig.size())return cnt;
        if(Dp[idx][prev][dir][cnt][flag][sflag] != -1)return Dp[idx][prev][dir][cnt][flag][sflag];
        long long ans = 0;
        if(flag){// use 0 -> 9
            if(!sflag){
                ans += rec(idx + 1,0,0,cnt,flag,sflag,Dig);
                for(int i = 1; i <= 9; i++)ans += rec(idx + 1,i,0,cnt,flag,1,Dig);
            }else{
                for(int i = 0; i <= 9; i++){
                    int cur_dir = (prev < i) ? 1 : (prev > i) ? 2 : 0;
                    ans += rec(idx + 1,i,cur_dir,cnt + ((dir + cur_dir) == 3),flag,sflag,Dig);
                }
            }
        }else{// 0 -> Dig[idx]
            if(!sflag){
                ans += rec(idx + 1,0,0,cnt,0 < Dig[idx],sflag,Dig);
                for(int i = 1; i <= Dig[idx]; i++)ans += rec(idx + 1,i,0,cnt,i < Dig[idx],1,Dig);
            }else{
                for(int i = 0; i <= Dig[idx]; i++){
                    int cur_dir = (prev < i) ? 1 : (prev > i) ? 2 : 0;
                    ans += rec(idx + 1,i,cur_dir,cnt + ((dir + cur_dir) == 3),i < Dig[idx],sflag,Dig);
                }
            }
        }

        return Dp[idx][prev][dir][cnt][flag][sflag] = ans;
        // NO sflag -> 0    => Not started
        // NO sflag -> 1-9  => ready to start(NO compute)

        // sflag Present -> 0-9 => still present(compute)
    }
    long long totalWaviness(long long num1, long long num2) {
        num1--;
        vector<int>Dig1,Dig2;
        while(num1 > 0){
            Dig1.push_back(num1 % 10);
            num1 /= 10;
        }
        reverse(Dig1.begin(),Dig1.end());
        while(num2 > 0){
            Dig2.push_back(num2 % 10);
            num2 /= 10;
        }
        reverse(Dig2.begin(),Dig2.end());
        memset(Dp,-1,sizeof(Dp));
        long long big = rec(0,0,0,0,0,0,Dig2);
        memset(Dp,-1,sizeof(Dp));
        long long small = rec(0,0,0,0,0,0,Dig1);
        return big - small;
    }
};