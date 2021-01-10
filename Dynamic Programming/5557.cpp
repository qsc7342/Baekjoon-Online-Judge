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

vector<int>arr;
int N;
ll dp[101][21] = {};

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    arr.pb(num);
  }
  dp[0][arr[0]] = 1;
  for(int i = 1 ; i < N - 1 ; i++) {
    for(int j = 0 ; j <= 20 ; j++) {
      if(j + arr[i] <= 20)
        dp[i][j + arr[i]] +=  dp[i - 1][j];
      if(j - arr[i] >= 0)
        dp[i][j - arr[i]] +=  dp[i - 1][j];
    }
  }

  // for(int i = 1 ; i < N - 1 ; i++) {
  //   for(int j = 0 ; j <= 20 ; j++) {
  //     printf("dp[%d][%d] = %lld\n",i, j, dp[i][j]);
  //   }
  // }
  

  cout << dp[N - 2][arr[N - 1]] << endl;
}