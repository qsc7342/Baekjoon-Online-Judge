#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
vector< vector<int> > tree(501);
bool visit[501] = {};
int node_cnt = 0;

int isTree(int i) {
  node_cnt = 1;
  visit[i] = true;
  queue<int> q;
  int cnt = 0;
  q.push(i);

  while(!q.empty()) {
    int cur_node = q.front();
    q.pop();

    for(int i = 0 ; i < tree[cur_node].size() ; i++) {
      cnt++;
      int nxt_node = tree[cur_node][i];

      if(!visit[nxt_node]) {
        q.push(nxt_node);
        node_cnt++;
        visit[nxt_node] = true;
      }
    }
  }
  return cnt;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int tc = 1;
  while(1) {
    int N, M;
    cin >> N >> M;
    if(N == 0 && M == 0) return 0;

    int tree_cnt = 0;
    node_cnt = 0;
    memset(visit, false, sizeof(visit));
    tree = vector< vector<int> >(501);

    for(int i = 0 ; i < M ; i++) {
      int a, b;
      cin >> a >> b;
      tree[a].pb(b);
      tree[b].pb(a);
    }

    for(int i = 1 ; i <= N ; i++) {
      int cur_cnt = INF;
      if(!visit[i]) {
        cur_cnt = isTree(i);
      }

      if(cur_cnt != INF && (cur_cnt / 2) == node_cnt - 1) {
        tree_cnt++;
      }
    }

    if(tree_cnt > 1)
      cout << "Case " << tc++ << ": " << "A forest of " << tree_cnt << " trees." << endl;
    else if(tree_cnt == 1) {
      cout << "Case " << tc++ << ": " << "There is one tree." << endl; 
    }
    else {
      cout << "Case " << tc++ << ": " << "No trees." << endl; 
    }
  }
}
