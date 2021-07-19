#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    priority_queue <int, vector <int>, greater <int> > pq;
    long long sum = 0;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
        if(sum < 0){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << (int)pq.size() << '\n';
}

