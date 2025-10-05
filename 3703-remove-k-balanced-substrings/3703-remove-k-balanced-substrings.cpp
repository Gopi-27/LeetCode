class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<vector<int>>st;
        // 0 open , 1 close
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(st.empty()){
                    st.push({0,1,0});
                }else{
                    vector<int>top = st.top();
                    if(top[0] == 0){
                        st.push({0,top[1] + 1,0});
                    }else{
                        st.push({0,1,0});
                    }
                }
                
            }else{

                if(st.empty()){
                    st.push({1,0,1});
                }else{
                    vector<int>top = st.top();

                    if(top[0] == 0){
                        st.push({1,top[1],1});
                    }else{
                        st.push({1,top[1],top[2] + 1});
                    }
                }

                vector<int>top = st.top();

                if(top[1] >= k && top[2] == k){
                    for(int j = 0; j < k + k; j++)st.pop();                    
                }
                
            }
           
            
            
        }
        
        string ans = "";
        while(!st.empty()){
            vector<int>top = st.top();
            if(top[0] == 0)ans += '(';
            else ans += ')';
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};