


typedef struct {
    int n;
    char** str;
    int* frr;
} OrderedStream;


OrderedStream* orderedStreamCreate(int n) {
    OrderedStream* obj = (OrderedStream *)malloc(sizeof(OrderedStream));
    obj->str = (char**)calloc(n , sizeof(char*));
    for(int i = 0; i < n; i++){
        obj->str[i] = (char*)calloc(6, sizeof(char));
    }
    obj->frr = (int*)calloc(n , sizeof(int));
    obj->n = n;
    return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* retSize) {
    strcpy(obj->str[idKey - 1], value);
    obj->frr[idKey - 1] = 1;
    int cnt = 0;
    int idx = 0;
    while( idx < obj->n && (obj->frr[idx]) != 0 ){
        if(obj->frr[idx] == 1)cnt++;
        idx++;
    }
    *retSize = cnt;
    char** Ans = (char**)calloc(cnt ,sizeof(char*));
    for(int i = 0; i < cnt; i++){
        Ans[i] = (char*)calloc(6 , sizeof(char));
    }
    int ansidx = 0;
    for(int i = 0; i < idx; i++){
        if(obj->frr[i] == 1){
           strcpy(Ans[ansidx],obj->str[i]);
           ansidx++;
           obj->frr[i] = -1;
        }
    }
    return Ans;
}

void orderedStreamFree(OrderedStream* obj) {
    free(obj);
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
 
 * orderedStreamFree(obj);
*/