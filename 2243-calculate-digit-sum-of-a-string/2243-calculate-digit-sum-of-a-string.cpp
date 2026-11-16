class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string grps = "";
            int sum = 0;
            int cnt = 0;
            for(char& ch : s){
                sum += ch - '0';
                cnt++;
                if(cnt == k){
                    grps += to_string(sum);
                    cnt = 0;
                    sum = 0;
                }
            }
            if(cnt)grps += to_string(sum);
            s = grps;
        }
        return s;
    }
};