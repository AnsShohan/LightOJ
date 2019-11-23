#include <bits/stdc++.h>

using namespace std;

int dp[210][110], N, A[210][110];

/*
going on the way, which gives the most amount of banana.

*/


int solve(int i, int j)
{
    if(i == 2*N) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int res = A[i][j];
    if(i<N){
        return dp[i][j] = res + max(solve(i+1, j), solve(i+1, j+1));
    }
    else {
        int res1=0, res2=0;
        int LIdx = 2*N-i-1;
        if(j==0)
        {
            res1 = solve(i+1, j);
        }
        else if(j==LIdx)
        {
            res1 = solve(i+1, j-1);
        }
        else
        {
            res1 = solve(i+1, j);
            res2 = solve(i+1, j-1);
        }
        return dp[i][j] = res + max(res1, res2);
    }
}

int main()
{
    int Test;
    cin>>Test;
    for(int cs=1; cs<=Test; cs++)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &N);
        for(int i=1; i<=2*N-1; i++)
        {
            if(i<=N)
            {
                for(int j=0; j<i; j++) scanf("%d", &A[i][j]);
            }
            else
            {
                for(int j=0; j<(2*N-i); j++) scanf("%d", &A[i][j]);
            }
        }
        printf("Case %d: %d\n", cs, solve(1, 0));

    }
    return 0;
}
