#include "BST.h"

template<typename key_type, typename value_type>
BST<key_type,value_type>::Node::Node(const pair<key_type,value_type> &p): data{p}, left{nullptr}, right{nullptr} {};

template<typename key_type, typename value_type>
BST<key_type,value_type>::BST(const pair<key_type,value_type> &p): head{new Node{p}} {};

template<typename key_type, typename value_type>
BST<key_type,value_type>::BST(BST &b){
  copy(b.head);
};

template<typename key_type, typename value_type>
BST<key_type,value_type>& BST<key_type,value_type>::operator=(const BST &b){
  clearTree(head);
  copy(b.head);
  return *this;
};

template<typename key_type, typename value_type>
BST<key_type,value_type>::BST(BST &&b) noexcept: head {move(b.head)}{cout<<"Move constructor"<<endl;};

template<typename key_type, typename value_type>
BST<key_type,value_type>& BST<key_type,value_type>::operator=(BST &&b) noexcept{
  head = move(b.head);
  return *this;
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::copy(const unique_ptr<Node> &root){
  if(root){
    insertNode(root->data);
    copy(root->left);
    copy(root->right);
  }
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::insertNode(const pair<key_type,value_type> &p) {
      buildTree(p,head);
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::buildTree(const pair<key_type,value_type> &p, unique_ptr<Node> &root){
  if(root == nullptr)
    root.reset(new Node{p});
  if(p.first < root->data.first)
    buildTree(p,root->left);
  if(p.first > root->data.first)
    buildTree(p,root->right);
  if(p.first == root->data.first)
    root->data.second = p.second; 
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::clearTree(unique_ptr<Node> &root) {
  if(root == nullptr)
    return;
  clearTree(root->left);
  clearTree(root->right);
  root.reset();
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::printTree() {
  if(head) {
    Iterator i(head.get());
    while(!i.isEnd()) {
      cout<<i.top()->data.first<<":"<<i.top()->data.second<<endl;
      i++;
    }
  }
  else
    cout<<"The tree is empty"<<endl;
};

template<typename key_type, typename value_type>
value_type& BST<key_type,value_type>::operator[](const key_type &key){

    Iterator i{findNode(key)};
    if(i != end()) {
      return i.value()->data.second;
    }
    else {
      cout<<"Element newly added"<<endl;
      insertNode(pair<key_type,value_type>{key,{}});
      return Iterator{findNode(key)}.value()->data.second;
    }

};

template<typename key_type, typename value_type>
const value_type& BST<key_type,value_type>::operator[](const key_type &key) const{
    ConstIterator i{findNode(key).top()};
    if(i != end()) {
      return i.value()->data.second;
    }
    else {
      throw "Cannot deference/add an element that is not present in the const tree";
    }

};

template<typename key_type, typename value_type>
typename BST<key_type,value_type>::Node* BST<key_type,value_type>::search(const key_type &key,const unique_ptr<Node> &root) const{
    if(root == nullptr || root->data.first == key)
      return root.get();
    if(key < root->data.first)
      return search(key,root->left);
    if(key> root->data.first)
      return search(key,root->right);
    return (root.get());
};

template<typename key_type, typename value_type>
typename BST<key_type,value_type>::Iterator BST<key_type,value_type>::findNode(const key_type &key) const{

      Node *reference = search(key,head);
      if(!reference)
         return end();
      else
        return Iterator{reference};
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::buildBalancedTree(vector<pair<key_type,value_type>> nodes, int start, int end){
   int mid = (start+end)/2;
   if(start > end)
     return ;
   insertNode(nodes[mid]);
   buildBalancedTree(nodes, start, mid-1);
   buildBalancedTree(nodes, mid+1, end);
};

template<typename key_type, typename value_type>
void BST<key_type,value_type>::balanceTree(){
  vector<pair<key_type,value_type>> nodes;
  Iterator i(head.get());
  while(!i.isEnd()) {
    nodes.push_back(i.top()->data);
    i++;
  }
  clearTree(head);
  buildBalancedTree(nodes, 0, nodes.size()-1);
};

template<typename key_type, typename value_type>
int BST<key_type,value_type>::height(const unique_ptr<BST<key_type,value_type>::Node> &root){
  if(root == nullptr)
    return 0;
  else {
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if(lHeight > rHeight)
      return lHeight+1;
    else
      return rHeight+1;
  }
};

template<typename key_type, typename value_type>
typename BST<key_type,value_type>::Iterator BST<key_type,value_type>::begin() { return Iterator{head.get()};};

template<typename key_type, typename value_type>
typename BST<key_type,value_type>::Iterator BST<key_type,value_type>::end() { return Iterator{nullptr}; };

template<typename key_type, typename value_type>
typename BST<key_type,value_type>::ConstIterator BST<key_type,value_type>::begin() const { return ConstIterator{head.get()};};

template<typename key_type, typename value_type>
typename BST<key_type,value_type>::ConstIterator BST<key_type,value_type>::end() const { return ConstIterator{nullptr};};
