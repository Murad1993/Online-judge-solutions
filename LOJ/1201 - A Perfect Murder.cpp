#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
vector <vector <int> > g(mx);
int l[mx], r[mx];
bool visited[mx];
int color[mx];

bool dfs(int u){
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            visited[v] = true;
            if(l[v] == -1 or dfs(l[v])){
                l[v] = u;
                r[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm(int n){
    int total = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    for(int i = 1; i <= n; ++i){
        memset(visited, false, sizeof(visited));
        if(color[i] and dfs(i)) ++total;
    }
    return total;
}

void dfs(int u, bool clr){
    visited[u] = true;
    color[u] = clr;

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            dfs(v, clr ^ 1);
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < mx; ++i) g[i].clear();

        for(int i = 0; i < m; ++i){
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        memset(color, 0, sizeof(color));
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= n; ++i){
            if(!visited[i]) dfs(i, 0);
        }

        int ans = n - bpm(n);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
