#include <bits/stdc++.h>
const int kN = 200100;
using namespace std;

int n, a[kN], k[kN], f[kN];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], f[i] = -1;
    for (int i = 1; i <= n; ++i)
        cin >> k[i];

    int R = 1;
    f[1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == -1)
            break;
        for (int j = max(R + 1, i - a[i] + 1); j <= min(n, i - a[i] + k[i - a[i]]); ++j) {
            f[j] = f[i] + 1;
            R = j;
        }
    }

    cout << f[n] << "\n";
    system("pause");
    return 0;
}