#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <cstdio>
 
using namespace std;
 
vector<int> adj[100000];
int deg[100000];
 
int main()
{
  int n; scanf("%d", &n);
  for(int i = 0; i + 1 < n; i++) {
    int a, b; scanf("%d%d", &a, &b); a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  
  queue<int> q;
  for(int i = 0; i < n; i++)
    if(deg[i] == 1)
      q.push(i);
 
  int result = 0;
  while(!q.empty()) {
    int v = q.front(); q.pop();
    if(deg[v] != 1) continue;
    result++;
 
    int u = -1;
    for(int i = 0; i < adj[v].size(); i++)
      if(deg[adj[v][i]] > 0)
        u = adj[v][i];
    assert(u != -1);
 
    deg[u] = 0;
    for(int i = 0; i < adj[u].size(); i++)
      if(--deg[adj[u][i]])
        q.push(adj[u][i]);
  }
 
  cout << result << endl;
}