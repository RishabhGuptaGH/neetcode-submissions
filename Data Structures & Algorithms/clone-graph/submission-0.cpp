/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

void dfs(Node* n1, Node* n2, map<int,Node*>& visited){
    if(visited.find(n1->val) != visited.end()){
        return;
    }
    visited[n1->val] = n2;

    for(auto i: n1->neighbors){
        Node* t = nullptr;
        if(visited.find(i->val) == visited.end())t = new Node(i->val);
        else t = visited[i->val];
        n2->neighbors.push_back(t);
        dfs(i, t, visited);
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node)return nullptr;

        map<int, Node*> visited;
        Node* t = new Node(node->val);
        dfs(node, t, visited);

        return t;
    }
};
