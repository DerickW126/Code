ll mypow(ll a, ll n, ll m){
    ll ans = 1;
    while(n){
        if(n & 1) ans = ans * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ans;
}