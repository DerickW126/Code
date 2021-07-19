#include <iostream>
#include <vector>
using namespace std;
int par[100001];
int weight[100001];
int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    weight[y] += weight[x];
    par[x] = y;
    //return weight[y];
}
int size(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return weight[x];
    else return weight[x]+weight[y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
/* 
4
5
l 1 2
l 3 4
q 1 4
l 2 3
q 1 4 
*/