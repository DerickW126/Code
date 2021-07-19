#include <iostream>
using namespace std;
int bit[200005], a[200005];
int n;
void modify(int pos, int x){
    for(int i = pos;i <= n;i += i&-i)
        bit[i] += x;
}
int query(int x){
    int ret = 0;
    for(int i = 17;i >= 0;i--){
        if(ret+(1<<i) <= n && bit[ret+(1<<i)] < x){
            ret += (1<<i);
            x -= bit[ret];
        }
    }
    return ret+1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        modify(i,1);
    }
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        int id = query(p);
        cout << a[id] << ' ';
        modify(id,-1);
    }
    cout << '\n';
}