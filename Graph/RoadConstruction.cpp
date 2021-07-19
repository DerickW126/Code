#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
int mx;
int par[100005];
int sz[100005];
int find(int x){
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    cnt--;
	sz[x] += sz[y];
    mx = max(mx, sz[x]);
	par[y] = x;
}
int main(){
    int n, m;
    cin >> n >> m;
    cnt = n;
    mx = 1;
    for(int i = 1;i <= n;i++){
        par[i] = -1;
        sz[i] = 1;
    }
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        merge(a,b);
        cout << cnt << ' ' << mx << '\n';
    }
}