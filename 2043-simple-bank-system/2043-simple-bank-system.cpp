class Bank {
private:
    vector<long long> locker;
    int n;
public:
    Bank(vector<long long>& balance){
        locker = balance;
        n = balance.size();
    }
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account1 < 1)return false;
        if(account2 > n || account2 < 1)return false;
        if(locker[account1 - 1] < money)return false;
        locker[account2 - 1] += money;
        locker[account1 - 1] -= money;
        return true;
    }
    bool deposit(int account, long long money) {
        if(account > n || account < 1)return false;
        locker[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || account < 1)return false;
        if(locker[account - 1] < money)return false;
        locker[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */