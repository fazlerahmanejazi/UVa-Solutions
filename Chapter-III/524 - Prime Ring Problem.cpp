#include <cstdio>
using namespace std;

bool p[42]={0} ;
int N, Case = 0, ans[20] = {1};

void backtracking(int L, bool taken[])
{
    if (L == N) {
        if (!p[ans[N-1] + 1])
            return;
        printf("1");
        for (int i = 1; i < N; ++i)
            printf(" %d", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 2; i <= N; ++i) {
        if (taken[i]) continue;
        if (p[i + ans[L - 1]]) {
            taken[i] = 1;
            ans[L] = i;

            backtracking(L + 1, taken);

            taken[i] = 0;
        }
    }
}
int main()
{

  p[2]=1 ; p[3]=1 ; p[5]=1 ; p[7]=1 ; p[11]=1 ; p[13]=1 ;
  p[17]=1 ; p[19]=1 ; p[23]=1 ; p[29]=1 ; p[31]=1 ; p[37]=1 ; p[41]=1 ;

    while (scanf("%d", &N) != EOF) {
        if (Case++) putchar('\n');
        printf("Case %d:\n", Case);
        bool taken[17] = {0};
        backtracking(1, taken);
    }
}
