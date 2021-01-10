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
ll sum = 0;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;

  cin >> T;
  for(int i = 0 ; i < T ; i++) {
    ll num;
    cin >> num;
    priority_queue<ll, vector<ll>, greater<ll> >pq;
    sum = 0;
    for(int j = 0 ; j < num ; j++) {
      int a;
      cin >> a;
      pq.push(a);
    }

    while(pq.size() >= 2) {
      ll tmp1 = pq.top();
      pq.pop();
      ll tmp2 = pq.top();
      pq.pop();
      pq.push(tmp1 + tmp2);
      sum += (tmp1 + tmp2);
    }
    cout << sum << endl;
  }
} 