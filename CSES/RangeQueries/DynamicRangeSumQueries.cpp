#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    long long val;
    Node *l, *r;
};
vector <int> v;
void pull(Node* root){
    root->val = root->l->val + root->r->val;
}
Node* build(int l, int r){
    Node* root = new Node();
    if(l == r){
        root->val = v[l];
        return root;
    }
    int m = (l+r)/2;
    root->l = build(l, m);
    root->r = build(m+1, r);
    pull(root);
    return root;
}
void modify(Node* root, int l, int r, int i, int d){
    if(i > r || i < l) return;
    if(l == r && r == i){
        root->val = d;
        return;
    }
    int m = (l+r)/2;
    modify(root->l, l, m, i, d);
    modify(root->r, m+1, r, i, d);
    pull(root);
    return;
}
long long query(Node* root, int l, int r, int ql, int qr){
    if(ql > r || qr < l) return 0;
    if(l >= ql && r <= qr) return root->val;
    int m = (l+r)/2;
    return query(root->l, l, m, ql, qr) + query(root->r, m+1, r, ql, qr);
}
int main(){
    int n, q;
    cin >> n >> q;
    v.resize(n+1);
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    Node* root = build(1, n);
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) modify(root, 1, n, a, b);
        else cout << query(root, 1, n, a, b) << '\n';
    }
}