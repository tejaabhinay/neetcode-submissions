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
/*So the idea is to create a seperate graph entirely not just copying the integer value inside it and attaching it to another graph. So we can follow bfs or dfs for this question.
Approach:-
We need a map. Why do we need a map?(To check whether you have cloned the node or not). Now inside bfs we first make the copy of the node and place it inside the graph for the particular actual node and push it into queue. Now normal bfs procedure we take the first node and check for its neighbors if not inside the map then create a node and push it inside map and queue, now if its present then attach it directly to the neighbors vector.*/
class Solution {
public:
    Node* bfs(Node* node,unordered_map<Node*,Node*>& mpp){
        Node* copy=new Node(node->val);
        mpp[node]=copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            for(int i=0;i<temp->neighbors.size();i++){
                if(mpp.find(temp->neighbors[i])==mpp.end()){
                    Node* c=new Node(temp->neighbors[i]->val);
                    mpp[temp->neighbors[i]]=c;
                    q.push(temp->neighbors[i]);
                }
                mpp[temp]->neighbors.push_back(mpp[temp->neighbors[i]]);
                
            }
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
        return nullptr;
        unordered_map<Node*,Node*> mpp;
        return bfs(node,mpp);
    }
};
