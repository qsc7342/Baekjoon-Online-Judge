#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int move[1000000 + 1] = {};
   // 초기화
   string n; cin >> n;
   int m; cin >> m;
   bool canUse[10];
   memset(canUse, true, sizeof(canUse));
   for(int i = 0; i < m; i++) {
      int btn; cin >> btn;
      canUse[btn] = false;
   }
   
   // // 완전탐색
   for(int i = 0; i < 1000000 + 1; i++) {
      string channel_s = to_string(i);
      bool directMove = true;
      for(int j = 0; j < channel_s.size(); j++) {
         directMove = directMove && canUse[channel_s[j] - '0'];
      }
      if(directMove) {
         move[i] = min((int)(channel_s.size()), abs(100 - i));
      } else {
         move[i] = abs(100 - i);
      }
   }

    int minmove = 1000000 + 1;

   // 최소 버튼 클릭횟수 계산
   for(int i = 0; i < 1000000 + 1; i++) {
      int curmove = min(move[i] + abs(i - stoi(n)), move[stoi(n)]);
      if(curmove < minmove) {
         minmove = curmove;
      }
   }

   cout << minmove << endl;

   return 0;
}