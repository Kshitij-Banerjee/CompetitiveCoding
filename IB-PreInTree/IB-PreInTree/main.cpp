//
//  main.cpp
//  IB-PreInTree
//
//  Created by Kshitij Banerjee on 24/10/16.
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




TreeNode* build(vector<int> &preorder, int start, int end,  vector<int> &inorder, int i, int j) {
    if( start > end ) return NULL;
    if( i > j ) return NULL;
    
    
    TreeNode* root = new TreeNode( preorder[start] );
    vector<int>::iterator it = find(inorder.begin()+i, inorder.begin()+j+1, preorder[start]);
    int idx = it - inorder.begin();
    int llength = idx - i;
    int rlength = end - idx;
    
    root->left = build( preorder, start+1, start + llength, inorder, i, idx-1 );
    root->right = build( preorder, start + llength + 1, end, inorder, idx+1, j );
    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int pre[] = { 1, 2, 3, 4, 5 };
    int in[] = { 3, 2, 4, 1, 5 };
    
    vector<int> preorder(pre, pre + 5);
    vector<int> inorder(in, in + 5 );
    
    TreeNode* node = buildTree(preorder, inorder);
    
    return 0;
}
