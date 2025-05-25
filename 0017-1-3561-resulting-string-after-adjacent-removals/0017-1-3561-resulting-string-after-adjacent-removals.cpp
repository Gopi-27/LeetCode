class Solution {
public:
    string resultingString(string s) {
        stack<char>mystack;
        for(int i = 0; s[i] != '\0'; i++){
            if(mystack.empty())mystack.push(s[i]);
            else if((mystack.top() - s[i]) == 1 || (mystack.top() - s[i]) == -1 || (mystack.top() - s[i] == 25) || (mystack.top() - s[i]) == -25){
                mystack.pop();
            }else{
                mystack.push(s[i]);
            }
        }
        string ans = "";
        while(!mystack.empty()){
            ans += mystack.top();
            mystack.pop();
        }
        int n = ans.size();
        for(int i = 0; i < n/2 ; i++){
            char temp = ans[i];
            ans[i] = ans[n - i - 1];
            ans[n - i - 1] = temp;
        }
        return ans;
        
    
    }
};