int findPeakElement(int* nums, int numsSize) {
    int l=0;
    int h=numsSize-1;
    int ans=0;
    while(l<=h){
        int mid=(l+h)/2;
       long long int val=nums[mid];
        long long int val1,val2;
        if((mid-1)<0){
            val1=val-1;
        }else{
             val1=nums[mid-1];
        }
        
        if((mid+1)>=numsSize){
            val2=val-1;
        }else{
            val2=nums[mid+1];
        }
        
        if(val>val1 && val>val2){         
            ans=mid;
            break;
        }else if(val<val1 && val<val2){
            l=mid+1;
        }else if(val>val1 && val<val2){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}