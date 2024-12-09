///solution for the problem https://vjudge.net/problem/UVA-12965
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> prod, custom, comb;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p, c;
        cin >> p >> c;

        prod.resize(p);
        custom.resize(c);
        comb.clear();

        for (int i = 0; i < p; i++) {
            cin >> prod[i];
        }

        for (int i = 0; i < c; i++) {
            cin >> custom[i];
        }

        comb = prod;
        comb.insert(comb.end(), custom.begin(), custom.end());
        comb.emplace_back(0);
        sort(comb.begin(), comb.end());
        comb.erase(unique(comb.begin(), comb.end()), comb.end());

        sort(prod.begin(), prod.end());
        sort(custom.begin(), custom.end());

        int sol1 = -1;
        int sol2 = INT_MAX;

        for (int x : comb) {
            int ap = prod.end() - lower_bound(prod.begin(), prod.end(), x + 1);
            int ac = lower_bound(custom.begin(), custom.end(), x) - custom.begin();

            int total_angry = ap + ac;

            if (total_angry < sol2 || (total_angry == sol2 && x < sol1)) {
                sol2 = total_angry;
                sol1 = x;
            }
        }

        cout << sol1 << " " << sol2 << '\n';
    }

    return 0;
}
