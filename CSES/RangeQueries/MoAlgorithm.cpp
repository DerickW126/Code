#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <vector<vector<int> > > v;
vector <int> ans;
vector <int> cnt;
vector <int> a;
int ccnt;
void f(int n){
    vector <int> na = a;
    sort(na.begin(), na.end());
    for(int i = 0;i < n;i++){
        a[i] = lower_bound(na.begin(), na.end(), a[i]) - na.begin();
    }
}
bool cmp(vector <int> &c, vector <int> &d){
    return c[1] < d[1];
}
void add(int x){
    cnt[x]++;
    if(cnt[x] == 1) ccnt++;
}
void del(int x){
    cnt[x]--;
    if(cnt[x] == 0) ccnt--;
}
void solve(int gi, int n){
    sort(v[gi].begin(), v[gi].end(), cmp);
    ccnt = 0;
    cnt = vector <int> (n,0);
    int L = 0, R = 0;
    for(int i = 0;i < v[gi].size();i++){
        int l = v[gi][i][0], r = v[gi][i][1], idx = v[gi][i][2];
        while(R <= r){
            add(a[R++]);
        }
        while(L < l){
            del(a[L++]);
        }
        while(l < L){
            add(a[--L]);
        }
        ans[idx] = ccnt;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    ans.resize(q);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    f(n);
    int k = sqrt(n);
    v.resize(n/k+1);
    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        v[a/k].push_back({a,b,i});
    }
    for(int i = 0;i < v.size();i++){
        solve(i,n);
    }
    for(int i = 0;i < q;i++){
        cout << ans[i] << '\n';
    }
}