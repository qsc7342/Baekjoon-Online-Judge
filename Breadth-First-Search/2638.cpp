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

int N, K;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  int f; 
  int s;
  if(N % 2 == 0) {
    f = N / 2;
    s = N / 2;
  }
  else {
    f = N / 2;
    s = N / 2 + 1;
  }

  if(f * s < K) {
    cout << "-1" << endl;
    return 0;
  }
  else {
    int a = 0;
    int b = 0;
    for(int i = 1 ; i <= sqrt(K) ; i++) {
      if(K % i == 0) {
        if(i + (K / i) <= N) {
          a = i;
          b = K / i;
        }
      }
      if(a + b != 0) break;
    }
    int s = n - (a + b);
    for(int i = 0 ; i < a ; i++) {
      cout << 'A';
    }
    for(int i = 0 ; i < b ; i++) {
      cout << 'B';
    }
    for(int i = 0 ; i < s ; i++) {
      cout << 'A';
    }
  }
} 
