class ATM {
public:
    vector<int>bank;
    ATM() {
        bank.resize(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int>cash(5);
        vector<int>denom = {20,50,100,200,500};
        for(int i = 4; i >= 0; i--){
            int upto = min(bank[i],amount/denom[i]);
            cash[i] = upto;
            amount -= upto * denom[i];            
        }
        if(amount > 0)return {-1};
        for(int i = 0; i < 5; i++)bank[i] -= cash[i];
        return cash;

    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */