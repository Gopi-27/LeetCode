class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        bool flag = 1;
        while(flag){
            flag = 0;
            string prevLeft = "",left = "";
            int i = 0;
            while(s[i] == '1')prevLeft += s[i++];
            string temp = "";
            while(i < n && s[i] == '0')temp += s[i++];
            for(int j = 0; j < temp.size(); j++){
                left += '1';
                prevLeft.pop_back();
            }
            left += temp;
            while(i < n){
                int cnt = 0;
                string p = "";
                while(i < n && s[i] == '0'){
                    p += '0';
                    cnt--;
                    i++;
                }
                string dummy = "";
                int idx = prevLeft.size() - 1;
                while(cnt != 0){
                    if(prevLeft[idx] == '1')cnt++;
                    else cnt--;
                    dummy += prevLeft[idx];

                    idx--;
                    prevLeft.pop_back();                
                }
                reverse(dummy.begin(),dummy.end());
                left = dummy + left + p;
                
                string right = "";
                int mask = 0;
                while(i < n){
                    if(s[i] == '1')mask++;
                    else mask--;
                    right += s[i++];
                    if(mask == 0)break;
                }
                right = makeLargestSpecial(right);
                if(left < right){
                    flag = 1;
                    swap(left,right);
                }
                prevLeft += left;
                left = right;
            }
            s = prevLeft + left;
        } 
        return s;
    }
};