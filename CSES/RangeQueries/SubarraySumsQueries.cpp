#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <set>
#define int long long
#define ll long long
using namespace std;
const int MAXN = 200005;
struct Seg{
    int ans, mpre, msuf, sum;
    Seg *lc, *rc;
    Seg(){
        lc = nullptr, rc = nullptr;
    }
/*  void pull(){
        val = lc->val + rc->val;
    } */
};
int v[MAXN], n;
void pull(Seg* root){
    root->ans = max({root->lc->ans, root->rc->ans, root->lc->msuf+root->rc->mpre});
    root->mpre = max(root->lc->mpre, root->lc->sum+root->rc->mpre);
    root->msuf = max(root->rc->msuf, root->rc->sum+root->lc->msuf);
    root->sum = root->lc->sum + root->rc->sum;
}
Seg* build(int L, int R){
    Seg *node = new Seg();
    if(L == R){
        node->ans = max(0LL,v[L]);
        node->mpre = max(0LL,v[L]);
        node->msuf = max(0LL,v[L]);
        node->sum = v[L];
        return node;
    } else {
        int M = (L+R)>>1;
        node->lc = build(L, M);
        node->rc = build(M+1, R);
        pull(node);
        return node;
    }
}
int query(Seg* node, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return 0LL;
    if(ql <= L && qr >= R) return node->ans;
    int M = (L+R)>>1;
    return max(query(node->lc, L, M, ql, qr),query(node->rc, M+1, R, ql, qr));
}
void modify1(Seg* node, int L, int R, int i, int d){ // 單點修改 (root, current L, current R, query index, value)
    if(L == R && L == i){
        node->ans = max(d,0LL);
        node->mpre = max(d,0LL);
        node->msuf = max(d,0LL);
        node->sum = d;
        return;
    }
    int M = (L+R)>>1;
    if(i <= M) modify1(node->lc, L, M, i, d);
    else modify1(node->rc, M+1, R, i, d);
    pull(node);
    return;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> v[i];
    Seg* root = build(0, n-1);
    for(int i = 0;i < m;i++){
        int k, x;
        cin >> k >> x;
        modify1(root, 0, n-1, k-1, x);
        cout << query(root, 0, n-1, 0, n-1) << '\n';
    }
}