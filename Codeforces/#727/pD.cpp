#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <set>
#include <climits>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pair<int,int> > v;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    int l = 0, r = n-1;
    int ans = 0, cnt = 0;
    while(l < r){
        int smallcap = v[l].second;
        int smallneed = v[l].first;
        int bigcap = v[r].second;
        int bigneed = v[r].first;
        if(bigneed <= cnt){
            cnt += bigneed;
            ans += bigneed;
            r--;
        }
        if(bigcap <= smallneed){
            cnt += bigcap;
            ans += bigcap*2;
            r--;
        } else {
            ans += (bigcap-smallneed)*2;
            cnt += bigcap-smallneed;
            v[r].second -= smallneed;
            bigcap -= smallneed; 
        }
        if(cnt >= smallneed){
            ans += smallcap;
            l++;
        }
    }
    cout << ans << '\n';
}