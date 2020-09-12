#include<bits/stdc++.h>
using namespace std;
int t, n, x, y;

int main() {
    freopen("../sample.in", "r", stdin);
    freopen("../sample.out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> x >> y;
        int det = y - x, p;
        for(int j = det; j >= 1; j--)
            if (det % j == 0 && det / j < n) p = j;
        //cout << p << endl;
        int ret = y - p * (n - 1);
        if (ret <= 0) ret = x % p != 0 ? x % p : p;
        for(int j = 0; j < n; j++) cout << ret + j * p << " ";
        cout << endl;
    }
}