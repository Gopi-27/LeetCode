class FenWickTree{
    vector<int>Bit;
    int n;
public :
        FenWickTree(int n){
            Bit.resize(n);
            this->n = n - 1;
        }
        void Update(int idx,int val){
            while(idx <= n){
                Bit[idx] = max(Bit[idx],val);
                idx += idx & (-idx);
            }
        }
        int Query(int idx){
            int ans = 0;
            while(idx > 0){
                ans = max(ans,Bit[idx]);
                idx -= idx & (-idx);
            }
            return ans;
        }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        map<int,int>mpp;
        for(int& obs : obstacles)mpp[obs]++;
        int idx = 1;
        for(auto& p : mpp)p.second = idx++;
        for(int& obs : obstacles)obs = mpp[obs];
        FenWickTree Fen(idx);
        vector<int>Ans;
        for(int& obs : obstacles){
            Ans.push_back(Fen.Query(obs) + 1);
            Fen.Update(obs,Ans.back());
        }
        return Ans;
    }
};