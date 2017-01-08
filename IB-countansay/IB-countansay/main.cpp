//
//  main.cpp
//  IB-countansay
//
//  Created by Kshitij Banerjee on 28/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string start = "1";
    while( A-- > 1 ){
        string next = "";
        int i = 0;
        int j = 0;
        while( j < start.length() ){
            while( j < start.length() && start[j] == start[i] ){
                j++;
            }
            next.append(to_string(j-i));
            next.push_back(start[j-1]);
            i = j;
        }
        start = next;
    }
    
    return start;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << countAndSay(2);
    return 0;
}
