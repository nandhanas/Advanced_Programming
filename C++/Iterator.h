#include "BST.h"

/**
 *  Templated Iterator class to iterate through the given BST
 *  @param key_type template for a key of the BST node
 *  @param value_type template for a value of the BST node
 */

template<typename key_type, typename value_type>
class BST<key_type,value_type>::Iterator {
  using Node = BST<key_type,value_type>::Node;
  /**
   *  Node pointer to the current and temperory node
   */
  Node *current, *temp;
  /**
   *  Stack of nodes of a given BST tree
   */
  stack<Node*> q;

 public:
   /**
    *  Constructor of the Iterator
    *  @param n the node to be iterated
    */
  Iterator(Node *n): current{n}, temp{n} {
    while(temp != nullptr) {
      q.push(temp);
      temp = temp->left.get();
    }
    if(!q.empty())
      temp = q.top();
  };
  /**
   *  a function to find the top of the stack
   */
  Node*  top() {
    return temp;
  };
  /**
   *  a function to find the node that is currently being iterated
   */
  Node*  value() {
    return current;
  };
  /**
   *  an overload function for the operator ++ ie post increment
   *  @param int type to do post increment
   */
  Iterator& operator++(int) {
    temp = temp->right.get();
    if(!q.empty())
      q.pop();
    while(temp != nullptr) {
      q.push(temp);
      temp = temp->left.get();
    }
    if(!q.empty())
      temp = q.top();
    return *this;
  };
  /**
   *  an overload function for the operator == to compare iterators
   *  @param n interator ie to be compared
   */
  bool operator==(const Iterator &n) {return current == n.current;};
  /**
   *  an overload function for the operator != to compare iterators
   *  @param n interator ie to be compared
   */
  bool operator!=(const Iterator &n) {return current != n.current;};
  /**
   *  a function to check if the stack is empty
   */
  bool isEnd() {return q.empty();}
  ~Iterator() = default;
};

/**
 *  Templated ConstIterator class to iterate through the given const BST
 *  @param key_type template for a key of the BST node
 *  @param value_type template for a value of the BST node
 */

template<typename key_type, typename value_type>
class BST<key_type,value_type>::ConstIterator:public BST<key_type,value_type>::Iterator {
public:
  using Iterator = BST<key_type,value_type>::Iterator;
  /**
   *  For inheriting the Iterator's Constructor
   */
  using Iterator::Iterator; 
};
