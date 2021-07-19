#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <set>
#define ll long long
using namespace std;
int calc(string s, char c){
    if(s.size() == 1){
        return (s[0] == c ? 0 : 1);
    }
    int m = s.size()/2;
    int cntl = calc(string(s.begin(), s.begin()+m), c+1);
    cntl += s.size()/2 - count(s.begin()+m, s.end(), c);
    int cntr = calc(string(s.begin()+m, s.end()), c+1);
    cntr += s.size()/2 - count(s.begin(), s.begin()+m, c);
    return min(cntl, cntr);
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << calc(s,'a') << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}