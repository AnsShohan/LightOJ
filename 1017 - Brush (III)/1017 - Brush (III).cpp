#include <bits/stdc++.h>


using namespace std;

struct node {
    int x, y;
    node(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

bool cmp(node a, node b)
{
    return a.y<b.y;
}

vector<node>Points;

int dp[110][110], N, k, w;

int solve(int idx, int x)
{
    if(!x || idx>=N) return 0;
    if(dp[idx][x] != -1) return dp[idx][x];

    int res1 = solve(idx+1, x);
    int res2 = 0, i=-1, cnt = 0, L = Points[idx].y + w;
    for(i=idx; i<N; i++)
    {
        if(Points[i].y <= L) cnt++;
        else
        {
            break;
        }
    }
    res2 = cnt + solve(i, x-1);
    return dp[idx][x] = max(res1, res2);
}

void Init()
{
    Points.clear();
    memset(dp, -1, sizeof(dp));
    return;
}

int main()
{
    int T, tx, ty;
    cin>>T;
    for(int cs=1; cs<=T; cs++)
    {
        Init();
        scanf("%d %d %d", &N, &w, &k);
        for(int i=0; i<N; i++)
        {
            scanf("%d %d" ,&tx, &ty);
            Points.push_back(node(tx, ty));
        }
        sort(Points.begin(), Points.end(), cmp);
        printf("Case %d: %d\n", cs, solve(0, k));
    }
    return 0;
}
