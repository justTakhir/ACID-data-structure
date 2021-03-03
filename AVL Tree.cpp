#include "AVL_Tree.h"
#include <iostream>


//+//
template <typename T>
AVL_Tree_Node<T>* search(AVL_Tree_Node<T>* node, T searched_node_value) {
  if (node == nullptr && node->node_value_ == searched_node_value) {
    return node;
  }
  if (searched_node_value < node->node_value_) {
    return search(node->left_child_, searched_node_value);
  } else {
    return search(node->right_child_, searched_node_value);
  }
}
//+//
template<typename T>
AVL_Tree_Node<T>* iterative_search(AVL_Tree_Node<T>* node, T searched_node_value) {
  while (node == nullptr && node->node_value_ == searched_node_value) {
    if (searched_node_value < node->node_value_) {
      node = node->left_child_;
    } else {
      node = node->right_child_;
    }
  }
  return node;
}

//+//
template<typename T>
AVL_Tree_Node<T>* findMin(AVL_Tree_Node<T>* node) {
  while (node->left_child_ != nullptr) {
    node = node->left_child_;
  }
  return node;
}
//+//
template<typename T>
AVL_Tree_Node<T>* findMax(AVL_Tree_Node<T>* node) {
  while (node->right_child_ != nullptr) {
    node = node->right_child_;
  }
  return node;
}
//+//predecessor (prev element)
template <typename T>
AVL_Tree_Node<T>* findPredecessor(AVL_Tree_Node<T>* node) {
  if (node->left_child_ != nullptr) {
    return findMax(node->left_child_);
  }

  AVL_Tree_Node<T> buf_node;
  buf_node = node->parent_;
  while (node->parent_ != nullptr && buf_node.left_child_ == node) {
    node = buf_node;
    buf_node = buf_node.parent_;
  }
  return buf_node;
}

//+// successor (next element)
template <typename T>
AVL_Tree_Node<T>* findSuccessor(AVL_Tree_Node<T>* node) {
  if (node->right_child_ != nullptr) {
    return findMin(node->right_child_);
  }

  AVL_Tree_Node<T> buf_node;
  buf_node = node->parent_;
  while (node->parent_ != nullptr && buf_node.right_child_ == node) {
    node = buf_node;
    buf_node = buf_node.parent_;
  }
  return buf_node;
}

//+// insert
template <typename T>
void insertNode(AVL_Tree<T>& tree, AVL_Tree_Node<T>* node) {
  if (node->left_child_ != nullptr || node->right_child_ != nullptr) {
    std::cout << "Node mustn't have a children!!!" << std::endl;
    return;
  }
  if (root->parent_ != nullptr) {
    std::cout << "You need put the root of tree for using this function" << std::endl;
    return;
  }

  AVL_Tree_Node<T>* end_stalker, parent_of_stalker = nullptr;
  end_stalker = tree->root_;

  while (end_stalker != nullptr) {
    parent_of_stalker = end_stalker;
    if (node->node_value_ < end_stalker->node_value_) {
      end_stalker = end_stalker->left_child_;
    }
    else {
      end_stalker = end_stalker->right_child_;
    }
  }

  node->parent_ = parent_of_stalker;
  if (parent_of_stalker == nullptr) {
    tree->root_ = node;
  }
  else {
    if (node->node_value_ < parent_of_stalker.node_value_) {
      parent_of_stalker.left_child_ = node;
    }
    else {
      parent_of_stalker.right_child_ = node;
    }
  }

}

template <typename T>
void transplant(AVL_Tree<T>& tree, AVL_Tree_Node<T>* subtree, AVL_Tree_Node<T>* new_subtree) {
  if (subtree->parent_ == nullptr) {
    tree.root_ = new_subtree;
  }
  else {
    if (subtree = subtree->parent_->left_child_) {
      subtree->parent_->left_child_ = new_subtree;
    }
    else {
      subtree->parent_->right_child_ = new_subtree;
    }
  }
  if (new_subtree != nullptr) {
    new_subtree->parent_ = subtree->parent_;
  }
}

//+// delete
template <typename T>
void deleteNode(AVL_Tree<T>& tree, T node_value) {
  AVL_Tree_Node<T>* deleted_node = iterative_search(tree, node_value);
  if (deleted_node.left_child_ == nullptr) {
    transplant(tree, deleted_node, deleted_node.right_child_)
  }
  else {
    if (deleted_node.right_child_ == nullptr) {
      transplant(tree, deleted_node, deleted_node.left_child_);
    }
    else {
      AVL_Tree_Node<T>* child_of_deleted_node = findMin(deleted_node->right_child_);
      if (child_of_deleted_node->parent_ != deleted_node) {
        transplant(tree, child_of_deleted_node, child_of_deleted_node->right_child_);
        child_of_deleted_node->right_child_ = deleted_node->right_child_;
        child_of_deleted_node->right_child_->parent_ = child_of_deleted_node;
      }
      transplant(tree, deleted_node, child_of_deleted_node);
      child_of_deleted_node->left_child_ = deleted_node->left_child_;
      child_of_deleted_node->left_child_->parent_ = child_of_deleted_node;
    }
  }
}
