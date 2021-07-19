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
using namespace std;
void solve(){
    int n;
    cin >> n;
    int y = 0;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        cout << ((y |= x) ^ x);
        cout << ' ';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}