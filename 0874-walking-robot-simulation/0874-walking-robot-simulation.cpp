class Solution {
public:
    char ChangeDir(char dir,int val){
        if(val == -1){
            switch(dir){
                case 'N':
                    return 'E';
                case 'E':
                    return 'S';
                case 'S':
                    return 'W';
                default :
                    return 'N';
            }  
        }
        switch(dir){
             case 'N':
                return 'W';
            case 'E':
                return 'N';
            case 'S':
                return 'E';
            default :
                return 'S';
        }
            
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int,int>>st;
        for(auto b : obstacles)st.insert({b[0],b[1]});
        int ans = 0, x = 0, y = 0;
        char dir = 'N';
        for(int i = 0; i < n; i++){
            int k = commands[i];
            if(k < 0)dir = ChangeDir(dir,k);
            else if(dir == 'N')while(k-- && st.find({x,y + 1}) == st.end())y++;   
            else if(dir == 'S')while(k-- && st.find({x,y - 1}) == st.end())y--;
            else if(dir == 'W')while(k-- && st.find({x - 1, y}) == st.end())x--;
            else while(k-- && st.find({x + 1,y}) == st.end())x++;
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};