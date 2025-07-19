class Solution {
public:
    bool Signal(string folder,unordered_map<string,bool> & mpp){
        int i = folder.size() - 1;
        while(i >= 0){
            while(folder[i] != '/'){
                folder.pop_back();
                i--;
            }
            folder.pop_back();
            i--;
            if(mpp[folder])return false;
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,bool>mpp;
        vector<string>Ans;
        sort(folder.begin(),folder.end());
        int n = folder.size();
        for(int i = 0; i < n; i++){
            bool flag = Signal(folder[i],mpp);
            if(flag){
                mpp[folder[i]] = true;
                Ans.push_back(folder[i]);
            }
        }
        return Ans;
    }
};