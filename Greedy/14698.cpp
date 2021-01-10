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
const int INF = 987654321;

int K;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;

  cin >> T;

  for(int i = 0 ; i < T ; i++) {
    ll num;
    cin >> num;
    multiset<ll, less<ll> >arr;

    for(int j = 0 ; j < num ; j++) {
      ll a;
      cin >> a;
      arr.insert(a);
    }

    ll sum = 1;
    auto iter = arr.begin();
    auto iter2 = ++arr.begin();
    vector<ll>slime;
    while(arr.size() > 1) {
      ll tmp = (*iter) * (*iter2);
      slime.pb(tmp);
      arr.erase(iter);
      arr.erase(iter2);
      arr.insert(tmp);
      if(arr.size() > 1) {
        iter = arr.begin();
        iter2 = ++arr.begin();
      }
    }
    for(int j = 0 ; j < slime.size() ; j++) {
      sum *= slime[j] % MOD;
      sum %= MOD;
    }
    cout << sum % ((ll)1e9 + 7) << endl;
  }
} 