class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        map<int,int>mpp;
        for(int i = 1; i <= dist + 1 && i < n; i++){
            mpp[nums[i]]++;
        }
        int req = k - 1;

        int maxi = 0;
        int freq = 0;
        long long val = 0;

        for(auto b : mpp){
            if(req == 0)break;

            if(b.second <= req){
                val += b.second * b.first;
                req -= b.second;
                freq = b.second;
                maxi = b.first;
            }else{
                val += req * b.first;
                freq = req;
                maxi = b.first;
                break;
            }
           
        }
        ans = min(ans,val);
        cout << ans << " " << maxi <<endl;
        for(int i = dist + 2; i < n; i++){
            mpp[nums[i]]++;
            int r = i - dist - 1;

            if(nums[i] < maxi){
                val += nums[i];
            }else if(nums[i] > maxi){
                if(mpp[maxi] == freq){
                    auto it = mpp.find(maxi);
                    it++;
                    val += (*it).first;
                    maxi = (*it).first;
                    freq = 1;
                }else{
                    val += maxi;
                    freq++;
                }
            }else{// equal
                val += nums[i];
                freq++;
            }


            if(nums[r] < maxi){
                val -= nums[r];
                mpp[nums[r]]--;
                if(mpp[nums[r]] == 0)mpp.erase(nums[r]);
            }else if(nums[r] > maxi){
                mpp[nums[r]]--;
                if(mpp[nums[r]] == 0)mpp.erase(nums[r]);

                if(freq > 1){
                    val -= maxi;
                    freq--;
                }else{
                    val -= maxi;
                    auto it = mpp.find(maxi);
                    it--;
                    maxi = (*it).first;
                    freq = (*it).second;
                }
            }else{ //equal
                if(freq == 1){
                    val -= maxi;
                    auto it = mpp.find(maxi);
                    it--;
                    maxi = (*it).first;
                    freq = (*it).second;
                }else{
                    val -= maxi;
                    freq--;
                }

                mpp[nums[r]]--;
                if(mpp[nums[r]] == 0)mpp.erase(nums[r]);
            }

            ans = min(ans,val);
            cout << ans << " " << maxi <<endl;
        }
        return ans + nums[0];
    }
};

// [26,11,39,31,24,40,44,11,10,20,47,50,12,39,21,13,36,9,12,42,6,27,15,2,49,46,20,3,8,16,3,28,29,32,39,48,1,36,2,1,19,37,12,41,30,7,24,11,18,2]