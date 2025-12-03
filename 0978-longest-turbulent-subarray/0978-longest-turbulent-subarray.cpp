class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ccnt = 1;
        int ans = 1;
        int n = arr.size();
        bool flag = true;
        int i = 1;
        while(i < n && arr[i] == arr[i - 1])i++;
        if(i < n){
            if(arr[i - 1] > arr[i])flag = true;
            else flag = false;
            ccnt++;
            ans = 2;
        }
        i++;
        while(i < n){
            // up
            if(flag){
                // down
                if(arr[i - 1] > arr[i]){
                    ccnt = 2;
                    i++;
                }else if(arr[i - 1] < arr[i]){// up
                    ccnt++;
                    ans = max(ans,ccnt);
                    flag = !flag;
                    i++;
                }else{// equal
                    while(i < n && arr[i - 1] == arr[i])i++;
                    ccnt = 1;
                    if(i < n){
                        if(arr[i - 1] > arr[i])flag = true;
                        else flag = false;
                        ccnt++;
                    }
                    i++;
                }
            }else{ // down
                if(arr[i - 1] > arr[i]){// down
                    ccnt++;
                    ans = max(ans,ccnt);
                    flag = !flag;
                    i++;
                }else if(arr[i - 1] < arr[i]){// up
                    ccnt = 2;
                    i++;
                }else{// equal
                    while(i < n && arr[i - 1] == arr[i])i++;
                    ccnt = 1;
                    if(i < n){
                        if(arr[i - 1] > arr[i])flag = true;
                        else flag = false;
                        ccnt++;
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};