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

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int arr[5][5] = {};

  for(int i = 0 ; i < 5 ; i++) {
    for(int j = 0 ; j < 5 ; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i = 0 ; i < 5 ; i++) {
    for(int j = 0 ; j < 5 ; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}