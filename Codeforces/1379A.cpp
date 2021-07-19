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
#define mxn 2e5
#define mod 1e9+7
#define inf 1e9
using namespace std;
void print(vector <int> a){
    for(int i : a) cout << i << ' ';
    cout << '\n';
}
const string T = "abacaba";
int count(string s){
    int cnt = 0;
    for(int i = 0;i < s.size();i++){
        if(s.substr(i,7) == T){
            ++cnt;
        }
    }
    return cnt;
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i+7 <= n;i++){
        string tmp = s;
        bool ok = true;
        for(int j = 0;j < 7;j++){
            if(tmp[i+j] != '?' && tmp[i+j] != T[j]){
                ok = false;
                break;
            }
            tmp[i+j] = T[j];
        }
        if(ok && count(tmp) == 1){
            for(int j = 0;j < n;j++){
                if(tmp[j] == '?'){
                    tmp[j] = 'd';
                }
            }
            cout << "Yes\n";
            cout << tmp << '\n';
            return;
        }
    }
    cout << "No\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}