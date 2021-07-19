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
    vector <int> a(n), b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    vector <int> ft, sc;
    for(int i = 0;i < n;i++){
        if(a[i] < b[i]) {
            for(int j = 0;j < (b[i]-a[i]);j++){
                sc.pb(i);
            }
        } else if(a[i] > b[i]) {
            for(int j = 0;j < (a[i]-b[i]);j++){
                ft.pb(i);
            }
        }
    }
    //e() << '\n';
    if(ft.size() == sc.size()){
        cout << ft.size() << '\n';
        for(int i = 0;i < ft.size();i++){
            cout << ft[i]+1 << ' ' << sc[i]+1 << '\n';
        }
    } else {
        cout << "-1\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}