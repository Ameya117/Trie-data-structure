/*
complete string - if every prefix of this stirng is also present in this array
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putChar(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }


    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->putChar(word[i], new Node());

            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word){
        Node *node = root;
        for (int i=0;i<word.length();i++){
            if (node->containsKey(word[i])){

                node = node->get(word[i]);
                if(!node->isEnd())  return false;
            }
            return false;
        }

        return true;
    }
};

// complete string fuction
string completeString(int n, vector<string> &arr){
    Trie trie;
    for(auto &word:arr){
        trie.insert(word);
    }

    string res="";

    for(auto &word: arr){
        if (trie.checkIfPrefixExists(word)){
            if (word.size() > res.size()){
                res = word;
            }
            else if(word.length() == res.length() && word<res){
                res = word;
            }
        }
    }
    if (res=="") return "None";
    return res;
}