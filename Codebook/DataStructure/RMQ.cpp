#include <iostream>
#include <climits>
using namespace std;
const int MAXN = 500000;
struct Node{
    int mx, tag;
    Node *l, *r;
    Node(){
        mx = INT_MIN, tag = 0;
        l = nullptr, r = nullptr;
    }
};
int v[MAXN], n;
void pull(Node* root){
    root->mx = max(root->l->mx,root->r->mx);
}
Node* build(int L, int R){
    Node *root = new Node();
    if(L == R){
        root->mx = v[L];
        return root;
    } else {
        int M = (L+R)>>1;
        root->l = build(L, M);
        root->r = build(M+1, R);
        pull(root);
        return root;
    }
}
void update1(Node* root, int L, int R, int i, int d){ // 單點修改 (root, current L, current R, query index, value)
    if(L == R && L == i){
        root->mx += d;
        return;
    }
    int M = (L+R)>>1;
    if(i <= M) update1(root->l, L, M, i, d);
    else update1(root->r, M+1, R, i, d);
    pull(root);
    return;
}
int query(Node* root, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return 0;
    if(ql <= L && qr >= R) return root->mx;
    int M = (L+R)>>1;
    return max(query(root->l, L, M, ql, qr),query(root->r, M+1, R, ql, qr));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    Node *root = build(0, n-1);
    int q;
    cin >> q;
    for(int i = 0;i < q;i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l > r) swap(l, r);
        cout << query(root, 0, n-1, l, r) << '\n';
    }
}
