struct Node{
    Node* children[26];
    bool isEnd;
    Node(){
        isEnd = false;
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a']=new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    
     bool dfs(Node* curr, string& word, int i) {

        if(i == word.size()) {
            return curr->isEnd;
        }

        char c = word[i];

        if(c != '.') {

            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                return false;
            }

            return dfs(curr->children[index], word, i + 1);
        }

        for(int j = 0; j < 26; j++) {

            if(curr->children[j] != nullptr) {

                if(dfs(curr->children[j], word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
