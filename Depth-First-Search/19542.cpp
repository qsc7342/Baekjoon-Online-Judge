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

int N, M;

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   cin >> N >> M;

   int arr[N + 1] = {};
   for(int i = 1 ; i <= N ; i++) {
    arr[i] = i;
   }
   while(M--) {
    int a, b;
    cin >> a >> b;
    swap(arr[a], arr[b]);
   }
   for(int i = 1 ; i <= N ; i++) {
    cout << arr[i] << ' ';
   }
   cout << endl;
   return 0;
}