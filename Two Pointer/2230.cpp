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

const ll INF = 9876543212135;
ll N, M;
vector<ll>arr;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  arr.pb(INF);
  for(int i = 0 ; i < N ; i++) {
    ll num;
    cin >> num;
    arr.pb(num);
  }
  if(N == 1 || M == 0) {
    cout << "0" << endl;
    return 0;
  }
  sort(arr.begin(), arr.end());

  int left = 0;
  int right = 0;
  ll min_diff = INF;

  while(left < N - 1 || right < N - 1) {
    ll cur_diff = arr[right] - arr[left];
    if(cur_diff > min_diff) {
      left++;
    }
    else {
      if(cur_diff >= M) {
        min_diff = cur_diff;
        left++;
      }
      else right++;
    }
  }
  cout << min_diff << endl;
}
