#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;   // 수열의 길이
   int arr[n];   // 수열
   vector<int> lis;   // 가장 긴 증가하는 부분 수열

   cin >> n;
   
   for(int i = 0; i < n; i++) {
      cin >> arr[i];
   }

   lis.push_back(-1);
   for(int i = 0 ; i < n; i++) {
      if(lis.back() < arr[i]) {
         lis.push_back(arr[i]);
      } 
      else {
         auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
         *it = arr[i];
      }
   }

   cout << lis.size() - 1;

   return 0;
}