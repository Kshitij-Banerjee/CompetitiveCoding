// //  Trie.hpp
//  HR-Contacs
//
//  Created by Kshitij Banerjee on 08/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>

#include <unordered_map>
#include <string>
using namespace std;

class Trie {
    
    class TrieNode{
    public:
        char _val;
        int _count;
        unordered_map<char, TrieNode*> _children;
        TrieNode() : _val('$'), _count(0) {}
        TrieNode(char c, int count) : _val(c), _count(count) {}
        void print();
        ~TrieNode();
    };
    
    bool add( TrieNode*, string);
    TrieNode* _root;
public:
    void add( string s);
    int find( string partial);
    void print();
    
    Trie( ): _root( new TrieNode() ){}
    ~Trie();
};

#endif /* Trie_hpp */
