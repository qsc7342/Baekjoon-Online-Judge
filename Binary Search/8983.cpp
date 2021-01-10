#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1587654321;

int M, N, L;
vector<int>pos;
vector<pii>animal;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> M >> N >> L;
    int cnt = 0;

    rep(i, M) {
      int num;
      cin >> num;
      pos.pb(num);
    }

    sort(pos.begin(), pos.end());

    rep(i, N) {
      int a, b;
      cin >> a >> b;
      animal.pb(mp(a,b));
    }

    for(int i = 0 ; i < N ; i++) {
      int left = -L + animal[i].second + animal[i].first;
      int right = L + animal[i].first - animal[i].second;
      if(lower_bound(pos.begin(), pos.end(), left) == pos.end()) {
        continue;
      }
      else {
        int idx = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
        if(pos[idx] > right)
          continue;
        else cnt++;
      } 
    }
    cout << cnt << endl;
    return 0;
}