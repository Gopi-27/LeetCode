int GetAns(char*** items,int n,char* rule,int idx){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(rule,items[i][idx]) == 0)cnt++;
    }
    return cnt;
}

int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue) {
    if(strcmp(ruleKey , "type") == 0)return GetAns(items,itemsSize,ruleValue,0);
    if(strcmp(ruleKey,"color") == 0)return GetAns(items,itemsSize,ruleValue,1);
    return GetAns(items,itemsSize,ruleValue,2);
    
}