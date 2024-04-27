/*
Problem: 
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Link: https://leetcode.com/problems/clone-graph/
*/

Node* cloneGraph(Node* node) {
        map<Node*, bool> visited;
        map<Node*, Node*> clone;
        queue<Node*> q;
        if(node == NULL)
            return NULL;
        visited[node] = true; 
        q.push(node);
        clone[node] = new Node(node->val); 
        while(!q.empty()) {
            Node* x = q.front();
            q.pop();
            Node* cnode = clone[x];
            for(vector<Node*>::iterator it = x->neighbors.begin(); it != x->neighbors.end(); it++) {
                if(visited.find(*it) == visited.end()) { // if not visited 
                    visited[*it] = true;
                    q.push(*it);
                    clone[*it] = new Node((*it)->val);
                }
                cnode->neighbors.push_back(clone[*it]);
            }
        }
        return clone[node];
    }