#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
vector<char>route2;
vector<char>route;

int R, C;
int arr[1010][1010] = {};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> R >> C;
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
        for(int j = 1 ; j < R ; j++) {
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
            min_val = arr[i][j];
          }
        }
      }
    }
    int x1 = 1;
    int y1 = 1;
    int y2 = R;
    int x2 = C;
    while(y2 - y1 > 1) {
      if((no_y - 1) / 2 > (y1 - 1) / 2) {
 //       cout << "1" << endl;
        for(int i = 1 ; i < C ; i++) {
          route.pb('R');
        }
        route.pb('D');
        for(int i = 1 ; i < C ; i++) {
          route.pb('L');
        }
        route.pb('D');
        y1 += 2;
      }

      if((no_y - 1) / 2 < (y2 - 1) / 2) {
//        cout << "2" << endl;
        for(int i = 1 ; i < C ; i++) {
          route2.pb('R');
        }
        route2.pb('D');
        for(int i = 1 ; i < C ; i++) {
          route2.pb('L');
        }
        route2.pb('D');
        y2 -= 2;
      }
    }

    while(x2 - x1 > 1) {
      if((x1 - 1) / 2 < (no_x - 1) / 2) {
//        cout << x1 << ' ' << no_x << endl;
 //       cout << "3" << endl;
        route.pb('D');
        route.pb('R');
        route.pb('U');
        route.pb('R');
        x1 += 2;
      } 

      if((x2 - 1) / 2 > (no_x - 1) / 2) {
//        cout << "4" << endl;
        route2.pb('D');
        route2.pb('R');
        route2.pb('U');
        route2.pb('R');
        x2 -= 2;
      }
    }
//    cout << no_y << ' ' << y1 << endl;
    if(no_x == x1) {
//      cout << "5" << endl;
      route.pb('R');
      route.pb('D');
    }

    else {
 //     cout << "6" << endl;
      route.pb('D');
      route.pb('R');
    }
  }

  for(int i = 0 ; i < route.size() ; i++) {
   cout << route[i];
  }
 // cout << "----------" << endl;
  if(route2.size() > 0) {
    for(int i = route2.size() - 1 ; i >= 0 ; i--) {
      cout << route2[i];
    }
  }
  cout << endl;
  return 0;
}
