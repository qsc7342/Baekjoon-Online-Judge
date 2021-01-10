#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646;


vector<pii>ans;

int getsize(ll a) {
  int cnt = 0;
  while(a > 0) {
    a /= 10;
    cnt++;
  }
  return cnt;
}

bool compare(pii a, pii b) {
  if(a.first == b.first) {
    return a.second < b.second;
  }
  else return a.first > b.first;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  int max_size = 0;

  vector<ll> arr;

  cin >> N;
  bool allzero = true;
  for(int i = 0 ; i < N ; i++) {
    ll num;
    cin >> num;
    if(num != 0) allzero = false;
    arr.pb(num);
    max_size = max(max_size, getsize(num));
  }
  for(int i = 0 ; i < arr.size() ; i++) {
    ll cur_num = arr[i];
    cur_num *= (ll)pow(10, max_size - getsize(cur_num));

    ans.pb(mp(cur_num, arr[i]));
  }

  sort(ans.begin(), ans.end(), compare);

  for(int i = 0 ; i < ans.size() ; i++) {
    cout << ans[i].second;
  }
  cout << endl;
} 

