class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ecnt = 0;
        int ocnt = 0;
        int eocnt = 0;
        bool eoflag = 0;
        int oecnt = 0;
        bool oeflag = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                ecnt++;
                if(!oeflag){
                    oecnt++;
                    oeflag = 1;
                }
                if(!eoflag){
                    eocnt++;
                    eoflag = 1;
                }

            }else{
                ocnt++;
                if(oeflag){
                    oecnt++;
                    oeflag = 0;
                }
                if(eoflag){
                    eocnt++;
                    eoflag = 0;
                }
            }
        }
        return(max(max(ecnt,ocnt),max(eocnt,oecnt)));
    }
};