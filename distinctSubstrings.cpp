/*
    number of distincy subtrings for a given string using Trie
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};


int distinctSubstrings(string word){
    int res=0;
    int n=word.length();

    Node *root = new Node();
    for(int i=0;i<n;i++){
        Node *node = root;
        for (int j=0;j<n;j++){
            if (!node->containsKey(word[i])){
                node->put(word[i],new Node());
                res+=1;
            }
            node = node->get(word[i]);
        }
    }

    return res+1;
}