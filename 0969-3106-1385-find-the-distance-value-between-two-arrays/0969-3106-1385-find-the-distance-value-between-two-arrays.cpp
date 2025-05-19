class Solution {
public:
    int Getidx(vector<int>& arr,int n,int key){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(arr[mid] <= key)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int n1 = arr1.size();
        int n2 = arr2.size();
        int cnt = 0;
        for(int i = 0; i < n1; i++){
            int idx = Getidx(arr2,n2,arr1[i]); 
            // if idx == 0 check only right limit
            // if idx >= n2  check only left limit;
            // else check  both limits 
            if(idx == 0 && arr2[idx] > arr1[i] + d)cnt++;
            else if(idx == n2 && arr2[idx - 1] < arr1[i] - d)cnt++;
            else if(idx > 0 && idx < n2 && arr2[idx - 1] < arr1[i] - d && arr2[idx] > arr1[i] + d)cnt++; 
        }
        return cnt;
    }
};