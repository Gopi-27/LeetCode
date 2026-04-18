class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        double mini = 257;
        double maxi = 0;
        double mode = 0;
        double sum = 0;
        int cnt = 0;
        int mode_freq = 0;
        for(int i = 0; i < n; i++){
            if(count[i]){
                mini = min(mini,(double)i);
                maxi = max(maxi,(double)i);
                sum += 1ll * count[i] * i;
                cnt += count[i];
                mode_freq = max(mode_freq,count[i]);
                if(count[i] == mode_freq)mode = i;
            }
        }
        double mean = sum/cnt;
        double median = 0;
        int pref = 0;
        for(int i = 0; i < n; i++){
            pref += count[i];
            if(pref > cnt/2){
                median = i;
                break;
            }
        }
        if(cnt % 2 == 0){
            pref = 0;
            for(int i = 0; i < n; i++){
                pref += count[i];
                if(pref >= cnt/2){
                    median = (median + i)/2.0;
                    break;
                }
            }
        }
        return {mini,maxi,mean,median,mode};
    }
};