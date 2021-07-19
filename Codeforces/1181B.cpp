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
#define pb push_back
using namespace std;
string num;
vector <string> v; 
int n;
bool cmp(string a, string b){
    return a.size() == b.size() ? a < b : a.size() < b.size();
}
void solve(int cut) {
    if (cut < 0 || cut+1 >= n) return;
    string ans, s1, s2;
    s1 = num.substr(0, cut+1); 
    s2 = num.substr(cut+1, n-cut);
    if (s2.size() >1 && s2[0] == '0') return; 
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int l1 = 0, l2 = 0, carry = 0;
    while(l1 < s1.size() || l2 < s2.size()) {
        carry += l1<s1.size() ? s1[l1++]-'0' : 0;
        carry += l2<s2.size() ? s2[l2++]-'0' : 0;
        ans += carry%10+'0';
        carry /= 10;
    }
    if (carry) ans += carry+'0';
    reverse(ans.begin(),ans.end());
    v.push_back(ans); 
}
int main() {
    cin >> n >> num;
    int l = n/2, r = n/2;
    while(num[l]=='0') --l;
    while(r < n && num[r] == '0') ++r;
    solve(l); solve(l-1);
    solve(r-1); solve(r);
    sort(v.begin() , v.end(), cmp);
    cout << v[0] << endl;
    return 0;
}