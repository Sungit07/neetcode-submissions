struct Node {
    Node* children[26];
    bool isEnd;

    Node() {
        isEnd = false;

        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<vector<char>> grid;

    int n, m;

    Node* root;

    void insert(string s) {

        Node* curr = root;

        for(char c : s) {

            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    void dfs(int i, int j, string& s, Node* curr) {

        if(i < 0 || i >= n || j < 0 || j >= m)
            return;

        if(grid[i][j] == '#')
            return;

        int index = grid[i][j] - 'a';

        if(curr->children[index] == nullptr)
            return;

        Node* next = curr->children[index];

        s += grid[i][j];

        if(next->isEnd) {
            ans.push_back(s);

            next->isEnd = false;
        }

        char temp = grid[i][j];
        grid[i][j] = '#';

        dfs(i + 1, j, s, next);
        dfs(i - 1, j, s, next);
        dfs(i, j + 1, s, next);
        dfs(i, j - 1, s, next);

        grid[i][j] = temp;

        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        grid = board;

        n = grid.size();
        m = grid[0].size();

        root = new Node();

        for(string& word : words) {
            insert(word);
        }

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                string s = "";

                dfs(i, j, s, root);
            }
        }

        return ans;
    }
};