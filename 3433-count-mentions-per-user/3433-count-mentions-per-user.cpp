bool comp(vector<string>& a,vector<string>& b){
    int t1 = stoi(a[1]);
    int t2 = stoi(b[1]);
    if(t1 < t2)return 1;
    if(t1 > t2)return 0;
    if(a[0][0] == 'O')return 1;
    return 0;
}
class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>ans(n);
        vector<int>start(n);
        sort(events.begin(),events.end(),comp);
        for(auto e : events){
            if(e[0][0] == 'O'){
                int t = stoi(e[1]);
                start[stoi(e[2])] = t + 60;
            }else{
                if(e[2][0] == 'A')for(int i = 0; i < n; i++)ans[i]++;
                else if(e[2][0] == 'H'){
                    int t = stoi(e[1]);
                    for(int i = 0; i < n; i++){
                        if(start[i] <= t)ans[i]++;
                    }
                }else{
                    stringstream ss(e[2]);
                    string str;
                    while(ss >> str){
                        int id = stoi(&str[2]);
                        ans[id]++;
                    }
                }
            }
        }
        return ans;
    }
};