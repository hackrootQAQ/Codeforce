#include<bits/stdc++.h>
using namespace std;
int t, a, b, x, y, n;

int main() {
    freopen("../sample.in", "r", stdin);
    freopen("../sample.out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> a >> b >> x >> y >> n;
        int pa1, pb1, pa2, pb2, left;
        {
            pa1 = max(a - n, x), left = n - (a - pa1);
            pb1 = max(b - left, y);
        }
        {
            pb2 = max(b - n, y), left = n - (b - pb2);
            pa2 = max(a - left, x);
        }
        cout << min((long long)pa1 * pb1, (long long)pa2 * pb2) << endl;
    }
}