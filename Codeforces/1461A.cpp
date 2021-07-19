#include <iostream>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    cout << 'a';
    for(int i = 1;i < n;i++){
        if(i%3 == 1) cout << 'b';
        else if(i%3 == 2) cout << 'c';
        else cout << 'a';
    }
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}