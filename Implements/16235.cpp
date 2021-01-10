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
const int INF = 2147483646;
const double pi = 3.141592653589793;

int N, M, D;
int board[17][17] = {};
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < M ; j++) {
      cin >> board[i][j];
    }
  }
  cin >> N >> M >> D;
  int arch[M];
  arch[0] = 2;
  arch[1] = 2;
  arch[2] = 2;

  sort(arch.begin(), arch.end());

  do {

  }while{next_permutation(arch.begin(), arch.end())};
  
} 
