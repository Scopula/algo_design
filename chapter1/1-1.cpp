#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<int, int> table;

/*
Helper-function that recursively finds
the cycle length starting at num.
Uses memoization by storing each intermediate
result to table.
*/
int solve(int num) {
    if (table.find(num) == table.end()) {
        int new_val;
        if (num % 2 == 1) {
            new_val = 3*num + 1;
        } else {
            new_val = num / 2;
        }
        table[num] = 1 + solve(new_val);
    } 
    return table[num];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    table[1] = 1;
    int i, j, mn, mx, res, max_res;
    
    while (cin >> i >> j) {
        max_res = 0;
        
        // Dealing with the case where i > j
        mn = min(i, j);
        mx = max(i, j);

        // Iterate from mn to mx and calculate the cycle length
        // for each, then update max_res
        for (int num=mn; num <= mx; num++) {
            res = solve(num);
            max_res = max(max_res, res);
        }
        cout << i << " " << j << " " << max_res << endl;
    }

    return 0;
}