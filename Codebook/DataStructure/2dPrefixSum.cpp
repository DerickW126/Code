#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <set>
#include <cmath>
#define ll long long
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;
int sum(int x1, int y1, int x2, int y2, int G[101][101]){
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    x1--, y1--;
    return G[x2][y2] + G[x1][y1] - G[x1][y2] - G[x2][y1];
}
void solve(){
    int n, q, c;
    cin >> n >> q >> c;
    int G[101][101] = {}, C[101][101] = {};
    for(int i = 0;i < n;i++){
        int x, y, s;
        cin >> x >> y >> s;
        G[x][y] = s;
        C[x][y]++;
    }
    for(int i = 1;i <= 100;i++){
        for(int j = 1;j <= 100;j++){
            G[i][j] += G[i-1][j] + G[i][j-1] - G[i-1][j-1];
            C[i][j] += C[i-1][j] + C[i][j-1] - C[i-1][j-1];
        }
    }
    for(int k = 0;k < q;k++){
        int t, x1, x2, y1, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int cnt = sum(x1,y1,x2,y2,C);
        int tot = sum(x1,y1,x2,y2,G);
        cout << (t%(c+1))*cnt+tot << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}