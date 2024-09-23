class Solution {
public:
    // here we have declared structure of TRIE
    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    // to get new node in trie
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        newNode->word="";
        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    // insert a word in trie;
    void insert(trieNode* root, string & word){
        trieNode* crawler = root;
        // check for each charcter of word
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch-'a'];
        }
        crawler->endOfWord = true;
        crawler->word = word;
    }
    vector<string > ans;
    
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void find(vector<vector<char>>& board,trieNode* root,int i, int j){
        if(i>=board.size()|| i<0 || j<0 || j>=board[0].size()) return ;

        if(board[i][j]=='$' || root->children[board[i][j]-'a']==NULL) return ;

        root=root->children[board[i][j]-'a'];
        if(root->endOfWord == true){
            ans.push_back(root->word);
            root->endOfWord=false;
        }

        char temp=board[i][j];
        board[i][j] = '$';

        // Now we will go in all direction to get the character of the words
        for(vector<int>& dir:directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            find(board,root,new_i,new_j);

        }
        board[i][j] = temp;

    }


    
    vector<string> findWords(vector<vector<char>>& boards, vector<string>& words) {
        
        // traverse in the grid just once and find all the words.
        int row = boards.size();
        int col = boards[0].size();

        // create root
        trieNode* root = getNode();

        // insert words in tire
        for(int i=0;i<words.size();i++){
            insert(root,words[i]);
        }

        // traverse grid only once

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(root->children[boards[i][j]-'a']!=NULL){
                        find(boards,root,i,j);
                }
            }
        }
        return ans;
    }
};