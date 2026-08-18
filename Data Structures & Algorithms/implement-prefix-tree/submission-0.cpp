struct Node{
    Node* children[26];
    bool isEnd;
    Node(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class PrefixTree {
public:
    Node *root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Node *curr = root;
        for(char c:word){
            if(curr->children[c-'a'] == nullptr) return false;
            curr=curr->children[c-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for(char c : prefix) {
            if(curr->children[c-'a'] == nullptr)
                return false;

            curr = curr->children[c-'a'];
        }

        return true;
    }
};
