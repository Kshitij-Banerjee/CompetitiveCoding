//
//  main.cpp
//  IB-kthBST
//
//  Created by Kshitij Banerjee on 18/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <numeric>

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
typedef pair<int, int> pii;
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



void node_traverse(TreeNode* root, int& count, int& kval, int& k){
    
    int left = 0;
    if( root->left == NULL ) {
        left = 0;
    }
    else
        node_traverse(root->left, left, kval, k);
    
    if(kval != -1 ) return;
    
    if( left == (k-1) ){
        // this is the node
        kval = root->val;
        count = left + 1;
        return;
    }
    else if( left < k ) {
        int right = 0;
        int K = k - left - 1;
        node_traverse(root->right, right, kval, K );
        count = left + right + 1;
        return;
    }
    else if( left > k ) {
        return;
    }
    
}
int sol(TreeNode* root, int k) {
    
    int count = 0;
    int kval = -1;
    node_traverse(root, count, kval, k);
    
    return kval;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root = new TreeNode(2);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(3);
    root -> left = left;
    root -> right = right;
    
    std::cout << sol(root, 2);
    return 0;
}
