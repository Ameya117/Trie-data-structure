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
}

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // inserting word
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->putChar(word[i], new Node());
            }

            // moves to the reference trie
            node = node->get(words[i]);
        }

        // end of the word
        node->setEnd();
    }


    // searching for a word
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i])){
                return false;
            }
            node = node->get(words[i]);
        }
        return node->isEnd();
    }

    // checking for a prefix
    bool startsWith(string prefix){
        Node *node = root;
        for (int i=0;i<prefix.size()){
            if (!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
}