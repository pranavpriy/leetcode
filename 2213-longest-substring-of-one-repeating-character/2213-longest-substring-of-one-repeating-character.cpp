class Solution {
private:
    struct Node {
        int max_len;
        int pre_len;
        int suf_len;
        int size;
        char pre_char;
        char suf_char;
    };
    
    vector<Node> tree;
    string s;

    // Helper function to combine two child nodes into a parent node
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        
        // 1. Calculate Prefix
        res.pre_char = left.pre_char;
        res.pre_len = left.pre_len;
        // If the entire left side is one repeating character that matches the right's prefix
        if (left.pre_len == left.size && left.pre_char == right.pre_char) {
            res.pre_len += right.pre_len;
        }
        
        // 2. Calculate Suffix
        res.suf_char = right.suf_char;
        res.suf_len = right.suf_len;
        // If the entire right side is one repeating character that matches the left's suffix
        if (right.suf_len == right.size && right.suf_char == left.suf_char) {
            res.suf_len += left.suf_len;
        }
        
        // 3. Calculate Maximum Length in this segment
        res.max_len = max(left.max_len, right.max_len);
        
        // If the left suffix and right prefix match, they form a continuous block across the middle
        if (left.suf_char == right.pre_char) {
            res.max_len = max(res.max_len, left.suf_len + right.pre_len);
        }
        
        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        // Reached the leaf node representing the exact index
        if (start == end) {
            tree[node] = {1, 1, 1, 1, c, c};
            s[start] = c;
            return;
        }
        
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        
        // Recompute the parent based on updated children
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.length();
        tree.resize(4 * n + 1);
        
        // Build the initial segment tree
        build(1, 0, n - 1);

        int k = queryCharacters.length();
        vector<int> ans(k);
        
        // Process each query
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len; // The root node always holds the max_len for the whole string
        }
        
        return ans;
    }
};