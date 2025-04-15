int distMoney(int money, int children) {
    if(money < children)return - 1;
    int cnt = 0; 
    money -= children;
    int quo = money / 7;
    int rem = money % 7;
    if(quo > children)return children - 1;
    if(quo == children){
        if(rem == 0)return children;
        return children - 1;
    }
    if(quo == children - 1 && rem == 3)return quo - 1;
    return quo;
    
        
    
}