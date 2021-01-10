#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int N, M, L;
vector<int>pos;
vector<int>dist;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> L;
  pos.pb(0);
  pos.pb(L);
  rep(i, N) {
    int num;
    cin >> num;
    pos.pb(num);
  }
  sort(all(pos));

  for(int i = 1 ; i <= pos.size() - 1 ; i++) {
    dist.pb(pos[i] - pos[i - 1] - 1);
  }

  int lo = 1;
  int hi = L - 1;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    int cur = 0;
    for(int i = 0 ; i < dist.size() ; i++) {
      cur += dist[i] / mid;
    }
    if(cur > M) {
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }
  cout << lo << endl;
  return 0;
}