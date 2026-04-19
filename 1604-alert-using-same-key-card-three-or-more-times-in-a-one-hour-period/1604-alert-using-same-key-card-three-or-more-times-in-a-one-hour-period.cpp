class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,vector<int>>mpp;
        int n = keyName.size();
        for(int i = 0; i < n; i++){
            int hrs = (keyTime[i][0] - '0') * 10 + (keyTime[i][1] - '0');
            int mins = (keyTime[i][3] - '0') * 10 + (keyTime[i][4] - '0');
            // cout << hrs << " " << mins << "\n";
            mpp[keyName[i]].push_back(hrs * 60 + mins);
        }
        vector<string>ans;
        for(auto& b : mpp){
            sort(b.second.begin(),b.second.end());
            int m = b.second.size();
            // cout << m << " ";
            for(int i = 0; i < m - 2; i++){
                if(b.second[i + 2] - b.second[i] <= 60)ans.push_back(b.first);
            }
        }
        return ans;
    }
};