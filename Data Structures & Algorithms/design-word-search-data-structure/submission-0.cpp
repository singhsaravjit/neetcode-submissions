class Trienode
{
    public:
       vector<Trienode*> children;
       bool word;

       Trienode() : children(26,NULL), word(false){}
};

class WordDictionary {
public:
  Trienode* root;


   
    WordDictionary() {
        root= new Trienode();
        
    }
    
    void addWord(string word) {


        Trienode* cur=root;
        for( char c : word){
            if(cur->children[c-'a']==NULL)
            cur->children[c-'a']= new Trienode();

            cur=cur->children[c-'a'];
        }
        cur->word=true;
        
    }
    
    bool search(string word) {

        return dfs(word,0,root);
        
    }



    private:

    bool dfs(string word, int j, Trienode* root){

        Trienode* cur=root;


        for(int i=j;i<word.size();i++){

            char c=word[i];

            if(c=='.'){
                for(Trienode* child: cur->children){
                    if(child!=NULL && dfs(word,i+1,child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(cur->children[c-'a']==NULL)
                {
                    return false;
                }
                cur=cur->children[c-'a'];
            }
        }
        return cur->word;
    }
};
