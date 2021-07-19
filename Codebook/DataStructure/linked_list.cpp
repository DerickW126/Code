#include <iostream>
using namespace std;
int nxt[105], pre[105];
int main(){
    int n, k;
    while(cin >> n >> k){
        for(int i = 1;i < n;i++)
            nxt[i] = i+1;
        nxt[n] = 1;
        for(int i = 2;i <= n;i++)
            pre[i] = i-1;
        pre[1] = n;
        int now = 1;
        int rest = n;
        while(rest > 1){
            int x = (k-1) % rest;
            for(int j = 0;j < x;j++)
                now = nxt[now]; 
            nxt[pre[now]] = nxt[now];
            pre[nxt[now]] = pre[now];
            rest--;

            int i = nxt[now];
            x = (k-1) % rest;
            for(int j = 0;j < x;j++)
                i = nxt[i];

            if(i != pre[now] && i != nxt[now]) {
                nxt[pre[i]] = nxt[i];
                pre[nxt[i]] = pre[i];

                nxt[pre[now]] = i;
                pre[nxt[now]] = i;
                pre[i] = pre[now];
                nxt[i] = nxt[now];
            }
            now = nxt[i];
        }
        cout << (1 - now + n) % n + 1 << '\n';
    }
}