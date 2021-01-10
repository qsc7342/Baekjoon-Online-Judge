#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

vector<ll>tree;
vector<ll>arr;

int N, M;

// ll init(int node, int start, int end) {
//   if(start == end) return tree[node] = arr[start];

//   int mid = (start + end) / 2;
//   return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
// }

ll getsum(int node, int left, int right, int start, int end) {
  int mid = (start + end) / 2; // left, right 찾으려는 위치
  // start, end 현재 탐색 위치
  if(left > end || right < start) return 0;
  if(left <= start && end <= right) return tree[node];
  else return getsum(node * 2, left, right, start, mid) + getsum(node * 2 + 1, left, right, mid + 1, end);
}

void update(int node, int start, int end, int idx, ll diff) {
  if(!(start <= idx && idx <= end)) return;
  tree[node] += diff;
  if(start == end) {
    arr[idx] = tree[node];
    return;
  }
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, diff);
  update(node * 2 + 1, mid + 1, end, idx, diff);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  tree.resize(N * 4);

  for(int i = 0 ; i < N ; i++) {
    arr.pb(0);
  }

  for(int i = 0 ; i < M ; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if(a == 1) {
      update(1, 0, N - 1, b - 1, c);
    }
    else if(a == 2) {
      cout << getsum(1, b - 1, c - 1, 0, N - 1) << endl;
    }
  }

}
