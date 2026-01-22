class Solution {
public:
    string makeGood(string s) {
        string st = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(st.size() == 0)st += s[i];
            else{
                if(s[i] >= 'a'){
                    int l = st.size() - 1;
                    if(st[l] >= 'a')st += s[i];
                    else {
                        if((s[i] - 'a') == (st[l] - 'A'))st.pop_back();
                        else st += s[i];
                    }
                }else {
                    int l = st.size() - 1;
                    if(st[l] >= 'a'){
                        if((s[i] - 'A') == (st[l] - 'a'))st.pop_back();
                        else st += s[i];
                    }else{
                        st += s[i];
                    }
                }
            }
        }
        return st;
    }
};