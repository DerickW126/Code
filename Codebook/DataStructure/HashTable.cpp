#include <iostraem>
struct Node{
    int val;
    Node* nxt;
    Node(int x){
        val = x;
        nxt = nullptr;
    }
};

Node* A[10];
int myF(int x) {
    return x % 10; //hash value
}
void myInsert(int x){
    int y = myF(x);
    Node* o = new Node(x);
    o->nxt = A[y];
    A[y] = o;
}
int myCount(int x){
    int y = myF(x);
    int cnt = 0;
    Node* cur = A[y];
    while(cur != 0){
        if(cur->val == x)
            cnt++;
        cur = cur->next;
    }
    return cnt;
}
int main(){
    
}