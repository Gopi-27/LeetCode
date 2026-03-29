class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string es1 = "",os1 = "",es2 = "",os2 = "";
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                es1 += s1[i];
                es2 += s2[i];
            }
            else{
                os1 += s1[i];
                os2 += s2[i];
            } 
        }
        sort(es1.begin(),es1.end());
        sort(os1.begin(),os1.end());
        sort(es2.begin(),es2.end());
        sort(os2.begin(),os2.end());
        return es1 == es2 && os1 == os2;

    }
};