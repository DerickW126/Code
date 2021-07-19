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
using namespace std;
const int mxn = 2e5;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> v(n);
    for(int &x : v) cin >> x;
    for (int i=0;i<n;i++){
            if (v[i] >= 0) v[i] = -v[i]-1;
    }
    if (n&1){
        int mx = -1, ind = -1;
        for (int i=0;i < n; i++){
            if (abs(v[i]) > mx){
                mx = abs(v[i]);
                ind = i;
            }
        }
        v[ind] = -v[ind]-1;
    }
    for(int x : v) cout << x << ' ';
    cout << '\n';   
}