#include <iostream>
using namespace std;
const int MAXN = 200005;
struct Node{
    int val, tag;
    Node *l, *r;
    Node(){
        val = 0, tag = 0;
        l = nullptr, r = nullptr;
    }
/*  void pull(){
        val = l->val + r->val;
    } */
};
int v[MAXN], n;
void pull(Node* root){
    root->val = root->l->val + root->r->val;
}
Node* build(int L, int R){
    Node *root = new Node();
    if(L == R){
        root->val = v[L];
        return root;
    } else {
        int M = (L+R)>>1;
        root->l = build(L, M);
        root->r = build(M+1, R);
        pull(node);
        return node;
    }
}
void push(Node* root, int L, int R){
    if(!node->tag) return;
    if(L != R){
        int M = (L+R)>>1;
        root->l->tag += root->tag;
        root->r->tag += root->tag;
        root->l->val += root->tag * (M-L+1); // change value based on size
        root->r->val += root->tag * (R-M); // change value based on size
        root -> tag = 0;
    }
}
void update1(Node* root, int L, int R, int i, int d){ // 單點修改 (root, current L, current R, query index, value)
    if(L == R && L == i){
        root->val += d;
        return;
    }
    int M = (L+R)>>1;
    if(i <= M) update1(root->l, L, M, i, d);
    else update1(root->r, M+1, R, i, d);
    pull(root);
    return;
}
void update2(Node *root, int L, int R, int ql, int qr, int d){ // 區間修改 (root, current L, current R, querty L, querty R, value) 
    if(ql > R || qr < L) return; //finish
    if(ql <= L && qr >= R){ //current compeletely in querty 
        root->tag += d;
        root->val += d*(R-L+1);
        return;
    }
    push(root, L, R);
    int M = (L+R)>>1;
    update2(root->l, L, M, ql, qr, d);
    update2(root->r, M+1, R, ql, qr, d);
    pull(root);
    return;
}
int query(Node* root, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return 0;
    if(ql <= L && qr >= R) return root->val;
    push(root, L, R);
    int M = (L+R)>>1;
    return query(root->l, L, M, ql, qr) + query(root->r, M+1, R, ql, qr);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    Node *root = build(0, n-1);
}
