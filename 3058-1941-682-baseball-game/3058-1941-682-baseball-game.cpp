class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;
        vector<int>arr(n);
        int top = -1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(operations[i][0] == '+'){
                top++;
                arr[top] = arr[top - 1] + arr[top - 2];
                sum += arr[top];
            }else if(operations[i][0] == 'D' ){
                top++;
                arr[top] =  2 * arr[top - 1];
                sum += arr[top];
            }else if(operations[i][0] == 'C'){
                sum -= arr[top];
                top--;
            }else{
                top++;
                arr[top] = stoi(operations[i]);
                sum += arr[top];
            }
        }
        return sum;
    }
};