#pragma once

template <typename T>
class AVL_Tree_Node {
 private:
  T node_value_;
  AVL_Tree_Node<T>* parent_;
  AVL_Tree_Node<T>* left_child_;
  AVL_Tree_Node<T>* right_child_;
 public:
  
};

template <typename T>
class AVL_Tree {
 private:
  AVL_Tree_Node<T>* node_;
  AVL_Tree_Node<T>* root_;
 public:
  //bool contains(AVL_Tree_Node<T>* node, T searched_node_value) {};

   AVL_Tree_Node<T>* search(AVL_Tree_Node<T>* node, T searched_node_value) {};

   AVL_Tree_Node<T>* iterative_search(AVL_Tree_Node<T>* node, T searched_node_value) {};

   AVL_Tree_Node<T>* findMin(AVL_Tree_Node<T>* node) {};

   AVL_Tree_Node<T>* findMax(AVL_Tree_Node<T>* node) {};

   AVL_Tree_Node<T>* findPredecessor(AVL_Tree_Node<T>* node) {};

   AVL_Tree_Node<T>* findSuccessor(AVL_Tree_Node<T>* node) {};

   void insertNode(AVL_Tree<T>& tree, AVL_Tree_Node<T>* node) {};

   void deleteNode(AVL_Tree<T>& tree, T node_value) {};
};

//AVL_Tree<T> Obama();
