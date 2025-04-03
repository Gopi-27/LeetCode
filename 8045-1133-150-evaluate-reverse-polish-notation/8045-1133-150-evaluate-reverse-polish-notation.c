struct Node{
    struct Node* prev;
    int val;
    struct Node* next;
};
struct Node* Top = NULL;
void Push(int num){
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->prev = NULL;
    nn->val = num;
    nn->next = NULL;
    if(Top == NULL){
        Top = nn;
        return ;
    }else{
        Top->next = nn;
        nn->prev = Top;
        Top = nn;
        return ;
    }
}
void Pop(){
    Top = Top->prev;
    return ;
}
int Number(char* str){
    int sign = 1;
    int idx = 0;
    if(str[idx] == '-' || str[idx] == '+'){
        if(str[idx] == '-'){
            sign = -1;
        }
        idx++;
    }
    
    int n = 0;
    while(str[idx] != '\0'){
        n = (n * 10) + (str[idx] - '0');
        idx++;
    }
    return sign * n;
}
int evalRPN(char** tokens, int tokensSize) {
    Top = NULL;
    int val1,val2;
    for(int i = 0; i < tokensSize; i++){
        if(strlen(tokens[i]) == 1 && (tokens[i][0] < '0' || tokens[i][0] > '9')){
            switch (tokens[i][0]){
                case '*' :
                    val2 = Top->val;
                    Pop();
                    val1 = Top->val;
                    Pop();
                    Push(val1 * val2 ); 
                break;
                case '/' :
                    val2 = Top->val;
                    Pop();
                    val1 = Top->val;
                    Pop();
                    Push(val1 / val2 ); 
                break;
                case '+' :
                    val2 = Top->val;
                    Pop();
                    val1 = Top->val;
                    Pop();
                    Push(val1 + val2 ); 
                break;
                default :
                    val2 = Top->val;
                    Pop();
                    val1 = Top->val;
                    Pop();
                    Push(val1 - val2 ); 
                break;
            }

        }
        else{
            Push(Number(tokens[i]));
        }
    }
    int ans = Top->val;
    Pop();
    return ans;
}