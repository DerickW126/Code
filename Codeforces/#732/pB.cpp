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
    int n, m;
    cin >> n >> m;
    vector <string> a(n);    
    int cnt[26] = {};
    for(int i = 0;i < n;i++){
        cin >> a[i];
        cnt[(a[i][0]-'a')]++;
    }
    for(int i = 0;i < (n-1);i++){
        string b;
        cin >> b;
        cnt[(b[0]-'a')]--;
    }
    for(int i = 0;i < 26;i++){
        if(cnt[i] == 1){
            for(int j = 0;j < n;j++){
                if((a[j][0]-'a') == i){
                    cout << a[j] << '\n';
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;
    while(t--) solve();
}