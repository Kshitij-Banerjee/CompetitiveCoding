//
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



static vector<int> memo(32, 0);

int solution(vector<int>& days, int end){
    
    if( end <= 0 ) return 0;
    
    if( memo[end] != 0 ) return memo[end];
    
    if( days[end] == 0 )
        return solution(days, end-1);
    if( end == 1) return 2;
    
    int cost = min( (2 + solution(days, end -1)),  (7 + solution(days, end -7)));
    memo[end] = cost;
    return cost;
}


int solution(vector<int> &A) {
    
    vector<int> days(32, 0);
    for( auto i : A){
        days[i] = 1;
    }
    
    return min( 25, solution(days, 30) );
}

int main(int argc, const char * argv[]) {
    
    int arr[] = { 1, 2, 4, 5, 7, 29, 30 };
    vector<int> inp(arr, arr + 7);
    cout << solution(inp) << endl;
    return 0;
}
