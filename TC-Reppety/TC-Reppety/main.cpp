//
//  main.cpp
//  TC-Reppety
//
//  Created by Kshitij Banerjee on 19/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Reppity{
public:
    int longestRep(string input){
        int maxl = 0;
        for(int size =1; size <= input.length()/2; size++){
            for(int i =0; i < input.length() - size; i++){
                string a(input, i, size);
                string b(input, i+size, input.length() - size -i );
                if( b.find(a) != string::npos){
                    maxl = max(size, (int)a.size());
                }
            }
        }
        
        return maxl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Reppity r;
    cout << r.longestRep("abcdxxxxabcd");
    return 0;
}
