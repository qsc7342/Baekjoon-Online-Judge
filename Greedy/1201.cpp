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


int R, C;
int arr[1010][1010] = {};
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> R >> C;
  vector<char>route;
  for(int i = 1 ; i <= R ; i++) {
    for(int j = 1 ; j <= C ; j++) {
      cin >> arr[i][j];
    }
  }
  if(R % 2 == 1) {
    for(int i = 1 ; i < R ; i++) {
      for(int j = 1 ; j < C ; j++) {
        if(i % 2 == 1) {
          route.pb('R');
        }
        else {
          route.pb('L');
        }
      }
      route.pb('D');
      if(i == R - 1) {
        for(int j = 1 ; j < C ; j++) {
          if(i % 2 == 0) {
            route.pb('R');
          }
          else {
            route.pb('L');
          }
        }  
      }
    }
  }
  else if(R % 2 == 0 && C % 2 == 1) {
    for(int i = 1 ; i < C ; i++) {
      for(int j = 1 ; j < R ; j++) {
        if(i % 2 == 1) {
          route.pb('D');
        }
        else {
          route.pb('U');
        }
      }
      route.pb('R');
      if(i == C - 1) {
        for(int j = 1 ; j < C ; j++) {
          if(i % 2 == 0) {
            route.pb('D');
          }
          else {
            route.pb('U');
          }
        }  
      }
    }
  }

  else {
    int min_val = INF;
    int no_y, no_x;
    for(int i = 1 ; i <= R ; i++) {
      for(int j = 1 ; j <= C ; j++) {
        if((i + j) % 2 == 1) {
          if(min_val > arr[i][j]) {
            no_y = i;
            no_x = j;
          }
        }
      }
    }

    int x1 = 0;
    int y1 = 0;
    int y2 = R;
    int x2 = C;




  }

  for(int i = 0 ; i < route.size() ; i++) {
   cout << route[i];
  }
  cout << endl;
  return 0;
}
