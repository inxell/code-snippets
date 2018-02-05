//
// Created by Ke Jin on 2/3/18.
//
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>

#ifndef PLAYGROUND_TRIE_H
#define PLAYGROUND_TRIE_H

using namespace std;


struct TrieNode{
    TrieNode() = default;
    TrieNode(string s):prefix(s){};
    unsigned size = 0;
    bool is_end = false;
    string prefix;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    ~TrieNode(){
        for(TrieNode* p : children){
            delete p;
        }
    }

    bool find(string word) const;
};

void words_gen(const TrieNode* node, vector<string>& res);

class Trie{
public:
    ~Trie(){
        delete root;
    }

    bool insert(string word);

    const TrieNode* find_prefix(string word) const;


private:
    TrieNode* root = new TrieNode();
};






#endif //PLAYGROUND_TRIE_H
