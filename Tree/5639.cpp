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

vector<int>preorder;

void postorder(int left, int right) {
	int cur = left;
	int line = left + 1;
	
	while(preorder[line++] < preorder[cur]); 
	if(left <= line - 1) postorder(left, line - 1);
	if(line <= right) postorder(line, right);
	cout << preorder[cur] << endl;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N;
  
  while(cin >> N) {
  	preorder.pb(N);
  }
  preorder.pb(INF);
  preorder.pb(INF);
  postorder(0, preorder.size() - 3);
  return 0;
}
