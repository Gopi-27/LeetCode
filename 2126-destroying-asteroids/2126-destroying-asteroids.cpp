class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        for(int i = 0; i < n; i++){
            if(mass < asteroids[i])return 0;
            mass = min(100001,mass + asteroids[i]);
        }
        return 1;
    }
};