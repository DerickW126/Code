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
int G[15][101][101];
void solve(){
    int n, q, c;
    cin >> n >> q >> c;
    for(int i = 0;i < n;i++){
        int x, y, s;
        cin >> x >> y >> s;
        G[s][x][y]++;
    }
    for(int k = 0;k <= c;k++){
        for(int i = 1;i <= 100;i++){
            for(int j = 1;j <= 100;j++){
                G[k][i][j] += G[k][i-1][j] + G[k][i][j-1] - G[k][i-1][j-1];
            }
        }
    }
    for(int k = 0;k < q;k++){
        int t, x1, x2, y1, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for(int i = 0;i <= c;i++){
            int val = (i+t) % (c+1);
            int tmp = G[i][x2][y2] + G[i][x1-1][y1-1] - G[i][x1-1][y2] - G[i][x2][y1-1];
            ans += tmp*val;
        }
        cout << ans << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}