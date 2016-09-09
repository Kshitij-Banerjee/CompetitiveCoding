//
//  main.cpp
//  MinAbsSum
//
//  Created by Kshitij Banerjee on 21/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int solution( vector<int>&A, int end) {
    int a = abs(A[end]);
    
    int pos = (pos[A][end-1] - a);
    int neg = (neg[A][end-1] + a);
    
    
}

int solution(vector<int> &A) {
    
    return solution( A, A.size()-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
