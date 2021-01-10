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
const ll INF = 987654321;

int T;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;

  int star = 2 * N - 1;
  int blank = 0;

  while(star >= 1) {
    for(int i = 0 ; i < blank ; i++) {
      cout << ' ';
    }
    for(int i = 0 ; i < star ; i++) {
      cout << '*';
    }
    cout << endl;
    star -=2;
    blank++;
  }
  star = 3;
  blank--;
  while(star <= 2 * N - 1 ) {
    for(int i = 0 ; i < blank ; i++) {
      cout << ' ';
    }
    for(int i = 0 ; i < star ; i++) {
      cout << '*';
    }
    cout << endl;
    star += 2;
    blank--; 
  }
} 
