vector<int> prime;
vector<int> kill;
void sieve(int n){
    prime.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            kill.push_back(i);
            prime[i] = i;
        }
        for(int j : kill){
            if((ll)i * j > n || j > prime[i]) break;
            prime[i * j] = j;
        }
    }
}
