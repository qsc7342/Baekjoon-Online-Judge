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

int N, M;
vector<int>pos;
int ans = 0;

bool idxchk2(int i) {
  if(i >= pos.size() || i < 0) return true;
  else return false;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int bring = 0;
  int zeropos;
  cin >> N >> M;

  rep(i, N) {
    int num;
    cin >> num;
    pos.pb(num);
  }
  pos.pb(0);
  sort(all(pos));

  rep(i, N) {
    if(pos[i] == 0) {
      zeropos = i;
    }
  }
  if(abs(pos[0]) > abs(pos[pos.size() - 1])) {
    ans += abs(pos[0]);

    for(int i = M ; i < zeropos && pos[i] < 0 ; i += M) {
      if(idxchk2(i)) cont;
      ans += abs(pos[i] *  2);
    }
    for(int i = pos.size() - 1 ; i >= zeropos && pos[i] > 0 ; i -= M) {
      if(idxchk2(i)) cont;
      ans += abs(pos[i] * 2);
    }
  }

  else {
    ans += abs(pos[pos.size() - 1]);

    for(int i = 0 ; i < zeropos && pos[i] < 0 ; i += M) {
      if(idxchk2(i)) cont;
      ans += abs(pos[i] *  2);
    }
    for(int i = pos.size() - M - 1 ; i >= zeropos && pos[i] > 0 ; i -= M) {
      if(idxchk2(i)) cont;
      ans += abs(pos[i] * 2);
    }
  }
  cout << ans<< endl;
}
