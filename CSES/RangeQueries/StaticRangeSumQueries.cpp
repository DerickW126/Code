#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector <long long> a(n+1), pre(n+1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i-1]+a[i];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        cout << pre[b]-pre[a-1] << '\n';
    }
}