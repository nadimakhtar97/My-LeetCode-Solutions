class DLL{
    public:
    int data;
    DLL *next,*prev;
    DLL(int data){
        this->data = data;
        next = prev = nullptr;
    }
};


class MyLinkedList {
public:
    
    DLL *head,*tail;
    
    MyLinkedList() {
        head = new DLL(-1);
        tail = new DLL(-2);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        DLL* node = head->next;
        for(int i=0;i<index;i++){
            node = node->next;
            if(node == tail or node == nullptr){
                return -1;
            }
        }
        
        if(node == tail)
            return -1;
        
        return node->data;
        
    }
    
    void addAtHead(int val) {
        
        DLL *node = new DLL(val);
        node->next = head->next;
        node->prev = head;
        node->next->prev = node->prev->next = node;
        
    }
    
    void addAtTail(int val) {
        DLL *node = new DLL(val);
        node->next = tail;
        node->prev = tail->prev;
        node->next->prev = node->prev->next = node;
        // print();
        
    }
    
    void addAtIndex(int index, int val) {
        DLL* node = head;
        for(int i=0;i<index;i++){
            node = node->next;
            if(node == tail or node == nullptr){
                return;
            }
        }
        DLL* newNode = new DLL(val);
        newNode->next = node->next;
        newNode->prev = node;
        newNode->next->prev = newNode->prev->next = newNode;
        
    }
    
    void deleteAtIndex(int index) {
        DLL* node = head->next;
        for(int i=0;i<index;i++){
            node = node->next;
            if(node == nullptr or node == tail){
                return;
            }
        }
        
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */