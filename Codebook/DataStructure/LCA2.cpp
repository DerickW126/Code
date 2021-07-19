#include <iostream>
#include <vector>
using namespace std;
struct Seg{
    pair<int,int> mn;
    Seg *lc, *rc;
    Seg(){
        mn = {INT_MAX,-1};
        lc = nullptr, rc = nullptr;
    }
};

vector <vector<int> > G;
vector <pair<int,int> > vec;
int pos[1000005];
Seg* root;

void pull(Seg* root){
    root->mn = min(root->lc->mn, root->rc->mn);
}

Seg* build(int L, int R){
    Seg *node = new Seg();
    if(L == R){
        node->mn = vec[L];
        return node;
    } else {
        int M = (L+R)>>1;
        node->lc = build(L, M);
        node->rc = build(M+1, R);
        pull(node);
        return node;
    }
}
pair<int,int> query(Seg* node, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return {INT_MAX, -1};
    if(ql <= L && qr >= R) return node->mn;
    int M = (L+R)>>1;
    return min(query(node->lc, L, M, ql, qr),query(node->rc, M+1, R, ql, qr));
}

int dep[1000005];
void dfs(int u){   
    for(int v : G[u]){
        if(dep[v] == -1){
            pos[v] = vec.size();
            dep[v] = dep[u]+1;
            vec.push_back({dep[v], v});
            dfs(v);
            pos[u] = vec.size();
            vec.push_back({dep[u], u});
        }
    }
}
int LCA(int a, int b){
    if(pos[a] > pos[b]) swap(a,b);
    cout << a << ' ' << b << ' ' << pos[a] << ' ' << pos[b] << '\n';
    pair <int,int> p = query(root, 0, vec.size()-1, pos[a], pos[b]);
    cout << p.first << ' ' << p.second << '\n';
    return p.second;
}
int main(){
    int n, q;
    cin >> n >> q;
    G.resize(n);
    for(int i = 0;i < n-1;i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0;i < n;i++){
        dep[i] = -1;
    }
    dep[0] = 0;
    pos[0] = 0;
    dfs(0);
    for(int i = 0;i < 2*n-2;i++){
        cout << pos[vec[i].second] << ' ' << vec[i].first << ' ' << vec[i].second << '\n';
    }
    root = build(0, 2*n-2);
    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << LCA(a,b)+1 << '\n';
    }
}