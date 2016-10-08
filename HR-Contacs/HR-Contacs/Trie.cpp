//
//  Trie.cpp
//  HR-Contacs
//
//  Created by Kshitij Banerjee on 08/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include "Trie.hpp"
#include <iostream>
#include <queue>


void Trie::add(string s){
    
    add(_root, s+"$");
    //print();
}

bool Trie::add(TrieNode* node, string s){
    if( s.length() == 0 ) return false;
    char c = s[0];
    unordered_map<char, TrieNode*>::iterator next = node->_children.find(c);
    if(  next != node->_children.end() ){
        if(s.length() != 1 && add( next->second, s.substr(1, s.length()-1) )){
            node->_count++;
            return true;
        }
        return false;
    }
    else{
        TrieNode* newNode = new TrieNode( c, 0 );
        node->_children[c] = newNode;
        add( newNode, s.substr(1, s.length() -1));
        node->_count++;
        return true;
    }
}

void Trie::print()  {
    
    queue<TrieNode*> Q;
    Q.push(_root);
    while( !Q.empty() ){
        TrieNode* node = Q.front();
        node->print();
        for( auto i : node->_children){
            Q.push(i.second);
        }
        Q.pop();
        
    }
}

int Trie::find(string partial){
    if( partial.empty() ) return 0;
    
    string::iterator c = partial.begin();
    TrieNode* next = _root;
    TrieNode* prev = _root;
    
    while( next->_children.find(*c) != next->_children.end() ){
        prev = next;
        next = next->_children.find(*c)->second;
        c++;
    }
    
    if( c == partial.end() )
        return next->_count;
    else
        return 0;
}

void Trie::TrieNode::print(){
    std::cout << "Val " << _val << " | Count : " << _count << " | Children: [" ;
    for( auto i : _children ){
        cout << i.first << " " ;
    }
    
    cout << "]" << endl;
}

Trie::~Trie(void) {
    delete _root;
}

Trie::TrieNode::~TrieNode() {
    for( auto i : _children )
        delete i.second;
}