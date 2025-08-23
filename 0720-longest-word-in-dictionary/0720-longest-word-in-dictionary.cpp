class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string Ans = "";
        string prev = "";
        int n = words.size();
        int i = 0;
        while(i < n){

            if(prev.size() + 1 == words[i].size()){
                string temp = words[i];
                temp.pop_back();
                if(prev == temp){
                    if(Ans.size() < words[i].size()){
                        Ans = words[i];
                        cout << Ans << endl;
                    }
                    prev = words[i];                    
                }

            }else{
                if(words[i].size() == 1)prev = words[i];
                else if(prev.size() == words[i].size()){
                    prev.pop_back();
                    string temp = words[i];
                    temp.pop_back();
                    if(prev == temp){
                        prev = words[i];
                    }
                }else if(prev.size() > words[i].size()){
                    string temp = words[i];
                    prev.resize(words[i].size() - 1);
                    temp.pop_back();
                    if(prev == temp){
                        prev = words[i];
                    }
                }
            }
            
            i++; 
        }
        return Ans;
    }
};


// ["rac","rs","ra",,"r",,,"onpdu","rsf","rs",,"racy","onpd"]
// "o","on","ot","oti","otif"


