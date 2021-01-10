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

int N;

int main() {
 cin.tie(NULL);
 ios_base::sync_with_stdio(false);

 cin >> N;

 vector<int> arr;
 for(int i = 1 ; i <= N ; i++) {
 	int x;
 	cin >> x;
 	arr.pb(x);
 }

 stack<int> s;

 ll ans = 0;
 for(int i = 0 ; i < N ; i++) {
 	while(!s.empty() && s.top() <= arr[i]) {
 		s.pop();
 	}
 	ans += s.size();
 	s.push(arr[i]);
 }
 cout << ans << endl;
} 
