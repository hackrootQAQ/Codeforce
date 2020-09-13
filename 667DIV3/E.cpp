#include<bits/stdc++.h>
using namespace std;
#define N 300000
struct pt {
    int x, y;
} p[N];
int cx[N], ct[N], f[N][5], n, k, t;

bool cmp(pt x, pt y) {
    return x.x < y.x;
}

int main() {
    freopen("../sample.in", "r", stdin);
    freopen("../sample.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> p[i].x;
        for(int i = 1; i <= n; i++) cin >> p[i].y;
        sort(p + 1, p + 1 + n, cmp);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if (p[i].x == p[i - 1].x) ct[cnt]++;
            else ct[++cnt] = 1, cx[cnt] = p[i].x;
        int l = 1, sum = 0;
        for(int r = 1; r <= n; r++) {
            sum += ct[r];
            while(l < r && cx[r] - cx[l] > k) sum -= ct[l], l++;
            for(int j = 1; j <= 2; j++) {
                f[r][j] = max(f[l - 1][j - 1] + sum, f[r][j]);
                f[r][j] = max(f[r][j], f[r - 1][j]);
            }
        }
        cout << f[n][2] << endl;
        for(int i = 1; i <= n; i++) f[i][1] = f[i][2] = cx[i] = ct[i] = 0;
    }
}