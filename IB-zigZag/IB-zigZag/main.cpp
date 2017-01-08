//
//  main.cpp
//  IB-zigZag
//
//  Created by Kshitij Banerjee on 04/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>

using namespace std;
#include <stack>


vector<vector<int> > zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    stack<TreeNode*> left;
    stack<TreeNode*> right;
    
    vector<vector<int> > result;
    
    left.push(A);
    
    while( !left.empty() || !right.empty() ){
        vector<int> output;
        
        while( !left.empty() ){
            TreeNode* top = left.top();
            left.pop();
            output.push_back(top->val);
            
            if( top->left ) right.push(top->left);
            if( top->right )right.push(top->right);
        }
        result.push_back(output);
        
        output.clear();
        while( !right.empty() ){
            TreeNode* top = right.top();
            right.pop();
            
            output.push_back(top->val);
            if( top->right ) left.push(top->right);
            if( top->left ) left.push(top->right);
        }
        
        result.push_back(output);
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    
     zigzagLevelOrder(node);
    
    return 0;
}
