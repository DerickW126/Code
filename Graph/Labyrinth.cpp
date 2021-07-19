#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1005;
char G[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int prex[MAXN][MAXN];
int prey[MAXN][MAXN];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int main(){
    int n, m;
    cin >> n >> m;
    int s1, s2, f1, f2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> G[i][j];
            if(G[i][j] == 'A'){
                s1 = i;
                s2 = j;
            }
            if(G[i][j] == 'B'){
                f1 = i;
                f2 = j;
            }
        }
    }
    queue <pair<int,int> > q;
    q.push({s1,s2});
    vis[s1][s2] = true;
    dis[s1][s2] = 0;
    prex[s1][s2] = -1;
    prey[s1][s2] = -1;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int x = 0;x < 4;x++){
            int u = i+dx[x];
            int v = j+dy[x];
            if(u >= 0 && u < n && v >= 0 && v < m && G[i][j] != '#' && !vis[u][v]){
                q.push({u,v});
                vis[u][v] = true;
                dis[u][v] = dis[i][j]+1;
                prex[u][v] = i;
                prey[u][v] = j;
            }
        }
    }
    int i = f1, j = f2;
    if(vis[i][j] == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << dis[i][j] << "\n";
    vector <char> v;
    while(prex[i][j] != -1 && prey[i][j] != -1){
        if(prex[i][j] == i-1){
            v.push_back('D');
        } else if(prex[i][j] == i+1){
            v.push_back('U');
        } else if(prey[i][j] == j+1){
            v.push_back('L');
        } else {
            v.push_back('R');
        }
        int tmp = i;
        i = prex[tmp][j];
        j = prey[tmp][j];
    }
    for(int i = v.size()-1;i >= 0;i--){
        cout << v[i];
    } 
    cout << '\n';
}