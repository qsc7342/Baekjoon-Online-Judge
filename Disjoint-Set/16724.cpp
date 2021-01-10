#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int N, M;
char arr[1001][1001] = {};
int parent[1000001] = {};
bool visit[1001][1001] = {};
int chk[1000001] = {};

int find(int n) {
  if(parent[n] < 0) return n;

  else {
    return parent[n] = find(parent[n]);
  }
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);

  if(a == b) return false;
  else {
    parent[find(a)] = b;
    return true;
  }
}


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  memset(parent, -1, sizeof(parent));


  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = 0;
  for(int i = 1 ; i <= N ; i++) {
    for(int j = 1 ; j <= M ; j++) {
      if(arr[i][j] == 'N' && i - 1 > 0) {
        int a = M *(i - 1) + j;
        int b = (M * (i - 2)) + j;
        if(a > b) swap(a, b);
        merge(a, b);
 //       cout << "merge : " << a << ' ' << b << endl;
      }

      else if(arr[i][j] == 'S' && i + 1 <= N) {
        int a = M *(i - 1) + j;
        int b = (M * (i)) + j;
        if(a > b) swap(a, b);
        merge(a, b);
 //       cout << "merge : " << a << ' ' << b << endl;
      }

      else if(arr[i][j] == 'W' && j - 1 > 0) {
        int a = M *(i - 1) + j;
        int b = (M * (i - 1)) + j - 1;
        if(a > b) swap(a, b);
        merge(a, b);
 //       cout << "merge : " << a << ' ' << b << endl;
      }

      else if(arr[i][j] ==  'E' && j + 1 <= M) {
        int a = M *(i - 1) + j;
        int b = (M * (i - 1)) + j + 1;
        if(a > b) swap(a, b);
        merge(a, b);
 //       cout << "merge : " << a << ' ' << b << endl;
      }
    }
  }

  for(int i = 1 ; i <= N * M ; i++) {
    if(chk[find(i)] == 0) {
 //     cout << "i : " << i << ' ' << "parent : " << find(i) << endl; 
      chk[find(i)] = 1;
      cnt++;
    }
  } 
  cout << cnt << endl;
  return 0;
}
