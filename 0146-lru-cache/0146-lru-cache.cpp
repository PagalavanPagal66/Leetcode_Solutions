class LRUCache {
    class node{
        public:
        int val;
        int key;
        node *next;
        node *prev; 
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> m;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node *newNode){
        node *temp=head->next;
        newNode->next=temp;
        temp->prev=newNode;
        newNode->prev=head;
        head->next=newNode;
    }
    void deleteNode(node *delnode){
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *resNode=m[key];
            int res=resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *delNode=m[key];
            m.erase(key);
            deleteNode(delNode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */