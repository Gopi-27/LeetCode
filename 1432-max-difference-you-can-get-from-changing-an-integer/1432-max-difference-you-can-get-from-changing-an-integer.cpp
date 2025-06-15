class Solution {
public:
    int maxDiff(int num) {
        vector<int>Dig;
        while(num > 0){
            Dig.push_back(num % 10);
            num /= 10;
        }
        int n = Dig.size();

        long long max = 0;
        bool max_exchanger_found = false;
        int max_exchanger;
        
        int min_exchanger = Dig[n - 1];
        int min = 0;
        bool min_exchanger_found = false;
        int flag = 1;

        if(Dig[n - 1] == 1){
            flag = 0;
        }


        for(int i = n - 1; i >= 0; i--){
            if(max_exchanger_found){
                if(max_exchanger == Dig[i]){
                    max = (max * 10) + 9;
                }else{
                    max = (max * 10) + Dig[i];
                }
            }else if(Dig[i] != 9){
                max_exchanger_found = true;
                max_exchanger = Dig[i];
                max = (max * 10) + 9;
            }else{
                max = (max * 10) + 9;
            }

            
            if(flag){
                if(Dig[i] == min_exchanger){
                    min = (min * 10) + 1;
                }else{
                    min = (min * 10) + Dig[i];
                }

            }else{
                if(min_exchanger_found){
                    if(Dig[i] == min_exchanger){
                        min = (min * 10) + 0;
                    }else{
                        min = (min * 10) + Dig[i];
                    }
                }else if(Dig[i] != 1 && Dig[i] != 0){
                    min_exchanger_found = true;
                    min_exchanger = Dig[i];
                    min = (min * 10) + 0;
                }else{
                    min = (min * 10) + Dig[i];
                }

            }
            



        }
        cout << max << " " << min;
        return max - min;

        
    }
};