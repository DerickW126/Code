#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    long long val;
    Node *l, *r;
};
vector <int> v;
Node* build(int l, int r){
    Node* root = new Node();
    if(l == r){
        root->val = v[l];
        return root;
    }
    root->val = 0;
    int m = (l+r)/2;
    root->l = build(l, m);
    root->r = build(m+1,r);
    return root;
}
void push(Node* root, int l, int r){
    if(root->val == 0) return;
    if(l != r){
        root->l->val += root->val;
        root->r->val += root->val;
        root->val = 0;
    }
}
void modify(Node* root, int l, int r, int ql, int qr, int u){
    if(ql > r || qr < l) return;
    if(ql <= l && qr >= r){
        root->val += u;
        return;
    }
    push(root, l, r);
    int m = (l+r)/2;
    modify(root->l, l, m, ql, qr, u);
    modify(root->r, m+1, r, ql, qr, u);
    return;
}
long long query(Node* root, int l, int r, int i){
    if(i < l || i > r) return 0;
    if(l == r && r == i){
        return root->val;
    }
    push(root, l, r);
    int m = (l+r)/2;
    return query(root->l, l, m, i) + query(root->r, m+1, r, i);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    v.resize(n+1);
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    Node* root = build(1, n);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int a, b, u;
            cin >> a >> b >> u;
            modify(root, 1, n, a, b, u);
        } else{
            int k;
            cin >> k;
            cout << query(root, 1, n, k) << '\n';
        }
    }
}
