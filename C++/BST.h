#include <iostream>
#include <utility> // pair
#include <memory> // unique pointer
#include <vector>
#include <stack>
using namespace std;

#ifndef BST_H
#define BST_H

/**
 *  Templated class of a Binary Search tree
 *  @param key_type template for a key of the BST node
 *  @param value_type template for a value of the BST node
 */

template<typename key_type, typename value_type>
class BST {

  /**
   *  Structure of a Node
   */
  struct Node {
    /**
     *  Pair to store a node's key and value
     */
    pair<key_type,value_type> data;
    /**
     *  Left child of a node
     */
    unique_ptr<Node> left;
    /**
     *  Right child of a node
     */
    unique_ptr<Node> right;
    /**
     *  Constructor of a node
     */
    Node(const pair<key_type,value_type> &p);
    /**
     *  Destructor of a node
     */
    ~Node() = default;
  };
  /**
   *  a recursive function to copy a BST node
   *  @param root the node to be copied
   */
  void copy(const unique_ptr<Node> &root);
  /**
   *  a recursive function to build a balanced BST node
   *  @param nodes a vector of nodes of a BST
   *  @param start starting point of a divided vector
   *  @param end ending point of a divided vector
   */
  void buildBalancedTree(vector<pair<key_type,value_type>> nodes, int start, int end);
  /**
   *  a recursive function to insert/replace a node into the BST node
   *  @param p a data pair of a node in a BST
   *  @param root the node to be inserted/replaced
   */
  void buildTree(const pair<key_type,value_type> &p, unique_ptr<Node> &root);
  /**
   *  a recursive const function to search a node in the BST node
   *  @param key key of a node in a BST ie to be found
   *  @param root the node to be searched
   */
  Node* search(const key_type &key,const unique_ptr<Node> &root) const;

public:

  /**
   *  Head of a BST
   */
  unique_ptr<Node> head;
  /**
   *  Default constructor of the BST
   */
  BST() = default;
  /**
   *  Constructor to assign a head to a BST
   *  @param p a data pair of a node ie to be inserted in a BST as head
   */
  BST(const pair<key_type,value_type> &p);
  /**
   *  Copy constructor
   *  @param b an already existing BST to be assigned to a given tree
   */
  BST(BST &b);
  /**
   *  Move constructor
   *  @param b an already existing BST to be moved to a given tree
   */
  BST(BST &&b) noexcept;
  /**
   *  Copy assignment
   *  @param b an already existing BST to be assigned to a given tree
   */
  BST& operator=(const BST &b);
  /**
   *  Move assignment
   *  @param b an already existing BST to be moved to a given tree
   */
  BST& operator=(BST &&b) noexcept;
  /**
   *  Iterator class to iterate through a BST
   */
  class Iterator;
  /**
   *  ConstIterator class to iterate through a const BST
   */
  class ConstIterator;
  /**
   *  a function to find the begining ie head of a BST
   */
  Iterator begin();
  /**
   *  a function to find the end ie nullptr of a BST
   */
  Iterator end();
  /**
   *  a const function to find the begining ie head of a BST
   */
  ConstIterator begin() const;
  /**
   *  a const function to find the end ie nullptr of a BST
   */
  ConstIterator end() const;
  /**
   *  a function to insert/replace a node into the BST node
   *  @param p a data pair of a node in a BST
   */
  void insertNode(const pair<key_type,value_type> &p);
  /**
   *  a recursive function to delete a BST node
   *  @param root the head of a BST
   */
  void clearTree(unique_ptr<Node> &root);
  /**
   *  a function to build a balanced BST node
   */
  void balanceTree();
  /**
   *  a const function to search a node in the BST node
   *  @param key key of a node in a BST ie to be found
   */
  Iterator findNode(const key_type &key) const;
  /**
   *  a function to print a BST node
   */
  void printTree();
  /**
   *  a function to find the height of a BST node
   *  @param root the head of a BST
   */
  int height(const unique_ptr<Node> &root);
  /**
   *  an overload function to the operator [] to find the value of a given key in a BST
   *  @param key the key whose associated value to be found
   */
  value_type& operator[](const key_type &key);
  /**
   *  a const overload function to the operator [] to find the value of a given key in a BST
   *  @param key the key whose associated value to be found
   */
  const value_type& operator[](const key_type &key) const;
  /**
   *  an overload friend function to the operator << to print the given BST
   *  @param out a ostream variable
   *  @param b BST
   */
  friend ostream& operator<<(ostream &out, BST<key_type,value_type> &b){
    b.printTree();
    return out;
  };
  /**
   *  a function to find the perfomance of a BST by generating random nodes for the given tree
   *  @param values a vector of random value to be inserted into the BST
   */
  void performance_BST(vector<key_type> &values);
  /**
   *  a function to estimate the time taken to find a node of a BST
   *  @param values a vector of key random values that need to searched
   *  @param file an ofstream variable
   */
  void lookup_time_BST(vector<key_type> &values, ofstream &file);
  /**
   *  Default destructor of the BST
   */
  ~BST() noexcept = default;
};

#include "BST_functions.h"
#include "Iterator.h"

#endif
