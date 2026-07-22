class Solution {
public:
    void QueryReverse(int l,int r,string& s){
        while(l < r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    void Trim(string& s){
        int n = s.size();
        int i = 0;
        int j = 0;
        while(i < n){
            while(i < n && s[i] == ' ')i++;
            while(i < n && s[i] != ' ')s[j++] = s[i++];
            if(i < n)s[j++] = s[i++];
        }
        while(j < n)s[j++] = ' ';
        while(s.back() == ' ')s.pop_back();
    }
    string reverseWords(string s) {
        Trim(s);
        // cout << s;
        int n = s.size();
        QueryReverse(0, n - 1, s);
        int l = 0;
        int r = 0;
        while(r < n){
            while(r < n && s[r] != ' ')r++;
            QueryReverse(l,r - 1,s);
            r++;
            l = r;
        }
        return s;
    }
};

// eht yks si eulb => blue is sky the
// the sky is blue
// eulb si yks eht
// blue is sky the