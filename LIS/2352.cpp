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
const int INF = 1000000001;

vector<int>adj;
vector<int>arr;

int N, cnt = 0;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    adj.pb(-INF);

    cin >> N;
    rep(i, N) {
      int num;
      cin >> num;
      arr.pb(num);
    }

    for(int i = 0 ; i < arr.size() ; i++) {
      if(arr[i] > adj.back()) {
        adj.pb(arr[i]);
        cnt++;
      }
      else {
        auto pos = lower_bound(adj.begin(), adj.end(), arr[i]);
        *pos = arr[i];
      }
    }
    cout << cnt << endl;
}