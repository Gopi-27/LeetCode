typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int cap;
}Queue;

Queue* Create_A_Queue(int Capacity){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->data = (int*)malloc(Capacity * sizeof(int));
    Q->front = - 1;
    Q->rear = - 1;
    Q->size = 0;
    Q->cap = Capacity;
    return Q;
}
void Enque(Queue* Q,int val){
    Q->rear = (Q->rear + 1) % (Q->cap);
    Q->data[Q->rear] = val;
    Q->size++;
    return ;
}
int Deque(Queue* Q){
    int val = Q->data[(Q->front + 1) % (Q->cap)];
    Q->front = (Q->front + 1) % (Q->cap);
    Q->size--;
    return val;
}

typedef struct {
    Queue* Q1;
    Queue* Q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* S1 = (MyStack*)malloc(sizeof(MyStack));
    S1->Q1 = Create_A_Queue(200);
    S1->Q2 = Create_A_Queue(200);
    return S1;
}

void myStackPush(MyStack* obj, int x) {
    while(obj->Q1->front != obj->Q1->rear)Enque(obj->Q2,Deque(obj->Q1));

    Enque(obj->Q1,x);

    while(obj->Q2->front != obj->Q2->rear)Enque(obj->Q1,Deque(obj->Q2));
    return ;
}

int myStackPop(MyStack* obj) {
    int val = obj->Q1->data[(obj->Q1->front + 1) % (obj->Q1->cap)];
    obj->Q1->front = (obj->Q1->front + 1) % (obj->Q1->cap);
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->Q1->data[(obj->Q1->front + 1) % (obj->Q1->cap)];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->Q1->front == obj->Q1->rear)return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->Q1);
    free(obj->Q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/