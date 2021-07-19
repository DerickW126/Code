#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int> > a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int,int> >());
    vector<int> idx(m*k);
    ll ans = 0;
    for(int i = 0; i < m*k; ++i) {
        ans += a[i].first;
        idx[i] = a[i].second;
    }

    sort(idx.begin(), idx.end());

    vector<int> division(k-1);
    for(int i = 0; i < k-1; ++i)
        division[i] = idx[(i+1)*m - 1];

    cout << ans << endl;
    for(int i = 0;i < division.size();i++){
        cout << division[i]+1 << " \n"[i == division.size()-1];
    }
}