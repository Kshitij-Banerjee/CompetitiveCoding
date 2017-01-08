//
//  main.cpp
//  SPOJ-DivisorSUm
//
//  Created by Kshitij Banerjee on 07/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <tgmath.h>
#include <algorithm>

using namespace std;

int solve( long num ) {
    int result = 0;
    
    // find all divisors which divides 'num'
    for (int i=2; i<=sqrt(num); i++)
    {
        // if 'i' is divisor of 'num'
        if (num%i==0)
        {
            // if both divisors are same then add
            // it only once else add both
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
    
    // Add 1 to the result as 1 is also a divisor
    return (result + 1);
}




int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin >> T;
    while( T-- ) {
        int s;
        cin >> s;
        cout << solve(s);
    }
    return 0;
}
