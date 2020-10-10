#include <bits/stdc++.h>
#include <assert.h>
typedef long long ll;
using namespace std;

/*
NEW solution, slightly changed from old one.
Runs in O(logn).

Explaining my algorithm is best done with an example.
Suppose we want to divide 38 by 2. The algorithm:
- Subtracts 2 from 38, so our current value is 36.
- Subtracts 4 from 36, so our current value is 32.
- Subtracts 8 from 32, so our current value is 24.
- Subtracts 16 from 24, so our current values is 8.
- Because 32 > 8, recursively repeats the above proccess.
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
        cur_div = cur_div + cur_div;
        cur_div_count = cur_div_count + cur_div_count;
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
    assert(int_div(51212213, 27) == 51212213 / 27);
    assert(int_div(51212213, 23) == 51212213 / 23);
    assert(int_div(55773, 3) == 55773 / 3);
    assert(int_div(55773, 4) == 55773 / 4);
    assert(int_div(55773, 5) == 55773 / 5);
    assert(int_div(55773, 6) == 55773 / 6);
    assert(int_div(55773, 7) == 55773 / 7);
    assert(int_div(55773, 8) == 55773 / 8);
    assert(int_div(55773, 9) == 55773 / 9);
    assert(int_div(55773, 10) == 55773 / 10);
    assert(int_div(55773, 11) == 55773 / 11);
    assert(int_div(55773, 12) == 55773 / 12);
    assert(int_div(55773, 13) == 55773 / 13);
    assert(int_div(55773, 14) == 55773 / 14);
    assert(int_div(55773, 15) == 55773 / 15);
    assert(int_div(55773, 16) == 55773 / 16);

    cout << "All tests passed.";
    return 0;

}
