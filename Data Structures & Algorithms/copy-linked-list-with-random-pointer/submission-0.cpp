/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> oldcopy;
        oldcopy[NULL]= NULL;

        Node* cur= head;

        while(cur != NULL){
            Node* copy = new Node(cur-> val);
            oldcopy[cur]=copy;
            cur=cur->next;
        }

        cur =head;
        while(cur!= NULL){
            Node* cp= oldcopy[cur];
            cp->next=oldcopy[cur->next];
            cp->random=oldcopy[cur->random];
            cur=cur->next;
        }

        return oldcopy[head];
        
    }
};
