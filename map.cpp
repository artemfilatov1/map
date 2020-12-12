#include <stdio.h>
#include <iostream>

template<typename Key, typename Value>
struct Data{
    Key k;
    Value v;
};

template<typename Key, typename Value>
struct Node{
    Data<Key, Value> data;
    Node *par;
    Node *left, *right;
    
    Value operator =(Value v){
        data.v = v;
    }
    
    Node(Data<Key, Value> value) : par(0), left(0), right(0), data(value) {}
};

template<typename Key, typename Value>
class Map{
    Node<Key, Value> *top;

    void show(Node<Key, Value> *top);
public:
    
    void add(const Data<Key, Value> data);
    bool find(const Key &key);
    Value* get(const Key &data);
    void show();
    void clear();
    
    Map() : top(0) {}
    
    Value& operator [](Key key);
};

template<typename Key, typename Value>
void Map<Key, Value>::add(const Data<Key, Value> data){
    if(!top) {
        top = new Node<Key, Value>(data);
        return;
    }
    Node<Key, Value> *p = top;
    while(p)
        if(data.k < p->data.k)
            if(!(p->left)) {
                p->left = new Node<Key, Value>(data);
                p->left->par = p;
                return;
            }
            else p = p->left;
        else if(data.k > p->data.k)
            if(!(p->right)) {
                p->right = new Node<Key, Value>(data);
                p->right->par = p;
                return;
            }
            else p = p->right;
        else if(p->data.k == data.k)
            return;
}

template<typename Key, typename Value>
bool Map<Key, Value>::find(const Key &data){
    Node<Key, Value> *p = top;
        while(p)
            if(data < p->data.k)
                p = p -> left;
            else if(data > p->data.k)
                p = p->right;
            else if(p->data.k == data)
                return true;
    return false;
}

template<typename Key, typename Value>
Value* Map<Key, Value>::get(const Key &data){
    Node<Key, Value> *p = top;
        while(p)
            if(data < p->data.k)
                p = p -> left;
            else if(data > p->data.k)
                p = p->right;
            else if(p->data.k == data)
                return &p->data.v;
    return 0;
}

template<typename Key, typename Value>
void Map<Key, Value>::show(){
    show(top);
}
 
template<typename Key, typename Value>
void Map<Key, Value>::show(Node<Key, Value> *top) {
    if(!top) return;
    show(top->left);
    std::cout << top->data.k << "-" << top->data.v << " ";
    show(top->right);
}

template<typename Key, typename Value>
Value& Map<Key, Value>::operator [](Key key){
    if (!find(key)){
        Data<Key, Value>* d = new Data<Key, Value>;
        d->k = key;
        add(*d);
    }
    return *get(key);
}
