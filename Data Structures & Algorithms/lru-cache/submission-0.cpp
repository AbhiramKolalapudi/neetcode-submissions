
class LRUCache {
private:
    struct Node
    {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node (int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    };

    Node* left;
    Node* right;
    int cap;
    unordered_map<int, Node*> cache;
    

    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) 
    {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:

    LRUCache(int capacity) 
    {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) 
    {
        if (cache.contains(key))
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.contains(key))
        {
            remove(cache[key]);
        }
        Node* newnode = new Node(key,value);
        cache[key] = newnode;
        insert(newnode);
        if (cache.size() > cap) 
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
