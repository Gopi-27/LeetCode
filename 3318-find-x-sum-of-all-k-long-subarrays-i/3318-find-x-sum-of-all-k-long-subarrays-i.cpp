bool comp(pair<int,int>& a, pair<int,int>& b){
        if(a.second > b.second)return true;
        else if(a.second == b.second)return (a.first > b.first)? true: false;
        return false;
}
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n = nums.size();
        map<int,int>mpp;
        for(int i = 0; i < k; i++)mpp[nums[i]]++;
        vector<pair<int,int>>temp;
        for(auto b : mpp)temp.push_back({b.first,b.second});
        sort(temp.begin(),temp.end(),comp);
        long long xsum = 0;
        int i = 0;
        while(i < x && i < temp.size()){
            xsum += (temp[i].first * temp[i].second);
            i++;
        }
        ans.push_back(xsum);
        for(int j = k; j < n; j++){
            mpp[nums[j - k]]--;
            if(mpp[nums[j - k]] == 0)mpp.erase(nums[j - k]);
            mpp[nums[j]]++;
            temp.clear();
            for(auto b : mpp)temp.push_back({b.first,b.second});
            sort(temp.begin(),temp.end(),comp);
            xsum = 0;
            i = 0;
            while(i < x && i < temp.size()){
                xsum += (temp[i].first * temp[i].second);
                i++;
            }
            ans.push_back(xsum);
        }
        return ans;

    }
};