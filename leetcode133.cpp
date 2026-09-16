class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        if(node == NULL)
            return NULL;

        if(mp.find(node) != mp.end())
            return mp[node];

        Node* copy = new Node(node->val);

        mp[node] = copy;

        for(Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};