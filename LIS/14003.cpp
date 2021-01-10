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
const int INF = 100000009;

int adj[1000001];
int arr[1000001];
pii ans[1000001];
deque<int>dq;

int N;
int cnt = 1;
int idx = 0;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    rep(i, N) {
      cin >> arr[i];
    }

    adj[0] = arr[0];
    ans[0] = {0, arr[0]};

    for(int i = 0 ; i < N ; i++) {
      if(adj[idx] < arr[i]) {
        idx++;
        adj[idx] = arr[i];
        ans[i] = mp(idx, arr[i]);
        cnt++;
      }

      else {
        int idx2 = lower_bound(adj, adj + idx, arr[i]) - adj;
        adj[idx2] = arr[i];
        ans[i] = mp(idx2, arr[i]);
      }
    }
    cout << cnt << endl;

    for(int i = N - 1 ; i >= 0 ; i--) {
      if(ans[i].first == cnt - 1) {
        dq.push_back(ans[i].second);
        cnt--;
      }
    }
    while(!dq.empty()) {
      cout << dq.back() << ' ';
      dq.pop_back();
    }
    cout << endl;
}