//  main.cpp
//  Grab-Task1
//
//  Created by Kshitij Banerjee on 21/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


#include <algorithm>
using namespace std;


long till(long a) {
    long out[] = {a,1,a+1,0};
    return out[a%4];
}

int solution(int M, int N){
    if( M == 0){
        M ++;
    }
    return (int)till(N) ^ till(M-1);
}

int linearXor(int M, int N ){
    int output = M;
    for( int i = M+1; i <= N; i ++)
        output = output ^ i;
    
    return output;
}

int main(int argc, const char * argv[]) {
    
    for( int i = 0; i < 100000; i ++)
        for( int j = 0; j <=i ; j++){
            if( solution(j,i) != linearXor(j,i) ){
                cout << "j "  << j << "i " << i << endl;
                cout << solution(j,i) << endl;
                cout << linearXor(j, i) << endl;
                return 0;
            }
        }
    return 0;
}
