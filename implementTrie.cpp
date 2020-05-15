class Trie {
public:
    /** Initialize your data structure here. */
        /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */
    
    struct node {
        struct node *child[26];
        bool isEnd;
    };
    
    struct node *root;
    
    struct node *getNode(){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    for(int i=0;i<26;i++){
        
        temp->child[i]=NULL;
    }
    temp->isEnd=false;
    return temp;
}
    
    Trie() {
        root=getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct node *temp=root;
        for(int i=0;i<word.size();i++){
           if(temp->child[word[i]-'a']==NULL){
               temp->child[word[i]-'a']=getNode();
               temp=temp->child[word[i]-'a'];
           }
            else
                temp=temp->child[word[i]-'a'];
        }
        temp->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child[word[i]-'a']==NULL) return false;
            else temp=temp->child[word[i]-'a'];
        }
        if(temp!=NULL && temp->isEnd==true) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
         struct node *temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child[word[i]-'a']==NULL) return false;
            else temp=temp->child[word[i]-'a'];
        }
        if(temp!=NULL) return true;
        return false;
    }
};

