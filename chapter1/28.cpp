#include <bits/stdc++.h>
#include <assert.h>
typedef long long ll;
using namespace std;

/*
Explaining my algorithm is best done with an example.
Suppose we want to divide 14 by 2. The algorithm:
- Subtracts 2 from 14, so our current value is 12.
- Subtracts 4 from 12, so our current value is 8.
- Subtracts 6 from 8, so our current value is 2.
- Because 8 > 2, recursively repeats the proccess.
*/

int int_div(int val, int div) {
    // Deal with negative val and div values.
    if (val < 0) { val *= -1;}
    if (div < 0) { div *= -1;}
    
    // Base case.
    if (div > val || val == 0) { return 0; }
    
    int count = 0; 
    int cur_div_count = 1;
    int cur_div = div;

    while (val >= cur_div) {
        // Do the subtraction, update count
        val -= cur_div;
        count += cur_div_count;
        
        // Update
        cur_div += div;
        cur_div_count += 1;
    }
    
    // Recursive step.
    return count + int_div(val, div);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    assert(int_div(8,2) == 4);
    assert(int_div(4, 5) == 0);
    assert(int_div(4, 1) == 4 / 1);
    assert(int_div(12313, 13) == 12313 / 13);
    assert(int_div(1231323, 4) == 1231323 / 4);
    
    cout << "All tests passed.";
    return 0;

}
