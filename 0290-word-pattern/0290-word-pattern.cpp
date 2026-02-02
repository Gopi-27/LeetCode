class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>A;
        stringstream ss(s);
        string str;
        while(ss >> str){
            A.push_back(str);
        }
        int n = A.size();
        int m = pattern.size();
        if(n != m)return false;
        unordered_map<char,string>cmpp;
        unordered_set<string>st;
        for(int i = 0; i < n; i++){
            int ch = pattern[i];

            if(cmpp.count(ch)){
                if(cmpp[ch] == A[i])continue;
                else return false;
            }else{
                if(find(st.begin(),st.end(),A[i]) != st.end())return false;
                st.insert(A[i]);
                cmpp[ch] = A[i];
            }
        }
        return true;

    }
};