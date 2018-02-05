//
// Created by Ke Jin on 2/3/18.
//

#include "Trie.h"

bool TrieNode::find(string word) const{
    auto node = this;
    for(char ch : word){
        int k = ch - 'a';
        if(node->children[k] == nullptr){
            return false;
        }
        node = node->children[k];
    }
    return node->is_end;
}


bool Trie::insert(string word){
    TrieNode* node = root;
    vector<TrieNode*> path{root};
    for(char ch : word){
        int k = ch - 'a';
        if(node->children[k] == nullptr){
            node->children[k] = new TrieNode(node->prefix + ch);
        }
        node = node->children[k];
        path.push_back(node);
    }
    bool boo = node->is_end;
    if(!boo){
        node->is_end = true;
        for(auto p : path){
            ++p->size;
        }
    }
    return !boo;
}

const TrieNode* Trie::find_prefix(string word) const {
    const TrieNode* node = root;
    for(char ch : word){
        int k = ch - 'a';
        if(node->children[k] == nullptr){
            return nullptr;
        }
        node = node->children[k];
    }
    return node;
}


void words_gen(const TrieNode *node, vector<string> &res) {
    if(node == nullptr) return;
    if(node->is_end) res.push_back(node->prefix);
    for(auto p : node->children){
        if(p){
            words_gen(p, res);
        }
    }
}