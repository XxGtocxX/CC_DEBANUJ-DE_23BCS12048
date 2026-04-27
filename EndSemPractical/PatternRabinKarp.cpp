#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(string pat, string txt, int q) {
    int m = pat.length();
    int n = txt.length();
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string txt = "ABCCDDAEFG";
    string pat = "CDD";
    int q = 101;

    search(pat, txt, q);
    return 0;
}