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
int N;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    arr.pb(num);
  }

  adj.pb(-INF);

  for(int i = 0 ; i < N ; i++) {
    if(adj.back() < arr[i]) {
      adj.pb(arr[i]);
    }
    else {
      auto it = lower_bound(adj.begin(), adj.end(), arr[i]);
      *it = arr[i];
    }
  }
  cout << N - (adj.size() - 1) << endl;
}