
// countxWordsEqualTo() | countWordsStartingWith()

struct Node{
    Node *links[26];
    int prefix=0,endswith=0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void putChar(char ch, Node *node){
        links[ch-'a'] = node;
    }
  
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    int getEndsWith(){
        return endswith;
    }

    int getPrefix(){
        return prefix;
    }

    void increasePrefix(){
        prefix++:
    }

    void reducePrefix(){
        prefix--;
    }

    void increaseEndsWith(){
        endswith++;
    }

    void reduceEndsWith(){
        endswith--;
    }
}

class Trie{
private:
    Node *root;
     
public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;
        for (int i=0;i<word.size();i++){
            if (!node->containsKey(words[i])){
                node->putChar(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndsWith();
    }

    int countWordsEqualTo(string word){
        Node *node = root;

        for(int i=0;i<word.size();i++){
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }

        return node->getEndsWith();
    } 
    
    int countWordsStartingWith(string prefix){
        Node *node = root;

        for(int i=0;i<word.size();i++){
            if (node->containsKey(prefix[i]))
                node = node->get(prefix[i]);
            else
                return 0;
        }

        return node->getPrefix();
    }

    // function to erase a word
    void erase(string word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if (node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix()
            }
        }

        node->reduceEndsWith();
    }

}