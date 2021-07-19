#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#define ll long long
using namespace std;
int pa[100005], pb[100005], pc[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector <ll> cnt[26];
    for(int j = 0;j < 26;j++){
        cnt[j].resize(n);
        cnt[j][0] = (s[0]-'a' == j);
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < 26;j++){
            cnt[j][i] = cnt[j][i-1] + (s[i]-'a' == j);
        }
    }
    for(int i = 0;i < q;i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        ll ans = 0;
        if(l > 0){
            for(int j = 0;j < 26;j++){
                ans += (cnt[j][r]-cnt[j][l-1])*(j+1);
            }
        } else {
            for(int j = 0;j < 26;j++){
                ans += (cnt[j][r])*(j+1);
            }
        }
        cout << ans << '\n';
    }
}