#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

int T;
int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visit[1001][1001] = {};

bool isRange(int y, int x) {
  if(y <= 0 || y > n || x <= 0 || x > m) return false;
  else return true;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  bool odd = false;
  bool even = false;
  vector<int> arr;
  for(int i = 0 ; i < n ; i++) {
    int x;
    cin >> x;
    if(x % 2 == 0) even = true;
    else odd = true;
  }
  if(even & odd) {
    sort(arr.begin(), arr.end());
    for(auto x : arr) {
      cout << x << ' ';
    }
    cout << endl;
  }
  else {
    for(auto x : arr) {
      cout << x << ' ';
    }
    cout << endl;
  }
}