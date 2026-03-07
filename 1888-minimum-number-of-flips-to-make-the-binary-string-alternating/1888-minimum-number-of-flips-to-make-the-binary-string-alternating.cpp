class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string str_01 = "",str_10 = "";
        int cnt_01 = 0;
        int cnt_10 = 0;
        for(int i = 0; i < n; i++){
            //01 series
            if(i % 2 == 0 && s[i] == '1')cnt_01++;
            else if(i % 2 == 1 && s[i] == '0')cnt_01++;
            if(i % 2 == 0)str_01 += '0';
            else str_01 += '1';
            //10 series
            if(i % 2 == 0 && s[i] == '0')cnt_10++;
            else if(i % 2 == 1 && s[i] == '1')cnt_10++;
            if(i % 2 == 0)str_10 += '1';
            else str_10 += '0';   
        }
        int ans = min(cnt_10,cnt_01);
        for(int i = 0; i < n - 1; i++){
            //01 series
            if(s[i] == str_01[i]){
                if(s[i] != str_01[n + i - 1])str_01 += s[i];
                else{
                    str_01 += (s[i] == '0') ? '1' : '0';
                    cnt_01++;
                }
            }else{
                cnt_01--;
                if(s[i] != str_01[n + i - 1])str_01 += s[i];
                else{
                    str_01 += (s[i] == '0') ? '1' : '0';
                    cnt_01++;
                }
            }
            // cout << endl << s << endl;
            // cout << str_01 << endl;
            //10 series
            if(s[i] == str_10[i]){
                if(s[i] != str_10[n + i - 1])str_10 += s[i];
                else{
                    cnt_10++;
                    str_10 += (s[i] == '0') ? '1' : '0';
                }
            }else{
                cnt_10--;
                if(s[i] != str_10[n + i - 1])str_10 += s[i];
                else{
                    cnt_10++;
                    str_10 += (s[i] == '0') ? '1' : '0';
                }
            }
            ans = min({ans,cnt_01,cnt_10});
        }
        return ans;
    }
};