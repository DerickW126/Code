#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n), pre(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    pre[0] = a[0];
    for(int i = 1;i < n;i++){
        pre[i] = a[i]^pre[i-1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l == 0) cout << pre[r] << '\n';
        else cout << (pre[r]^pre[l-1]) << '\n';
    }
}