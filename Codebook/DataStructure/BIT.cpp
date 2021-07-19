#include <iostream>
using namespace std;
int bit[105];
int n;
void modify(int pos, int x){
    for(int i = pos;i <= n;i += i&-i)
        bit[i] += x;
}
int query(int pos){
    int res = 0;
    for(int i = pos;i > 0;i -= i&-i){
        res += bit[i];
    }
    return res;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) modify(i,i);
    cout << query(5) << '\n';
    modify(3,3);
    cout << query(3) << '\n';
}