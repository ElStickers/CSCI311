#include <algorithm>
#include <iostream>
using namespace std;

#include "bst.h"

Tnode *BST::insert(Tnode *cur, string akey, string aval) {
  int bf;
  // inserts new node to empty tree
  if (cur == NULL) {
    cur = new Tnode(akey, aval);
    updateHeight(cur);
    return cur;
  }
  // if akey < key it will go down the left size of the tree
  if (akey < cur->key) {
    // if left child is NULL it will create a new node
    if (cur->left == NULL) {
      cur->left = new Tnode(akey, aval);
      updateHeight(cur);
      return cur;
    }  // if
    //if node already exists it will call insert at cur->left
    else {
      cur->left = insert(cur->left, akey, aval);
      bf = findBalanceFactor(cur);
      if (bf < -1 || bf > 1) {
        cur = restoreBalance(cur);
      }
      updateHeight(cur);
      updateSize(cur);
      return cur;
    }  // else
  }    // if
  //if akey > key it will go down right side of tree
  else if (akey > cur->key) {
    //if right child is null it will create a new node
    if (cur->right == NULL) {
      cur->right = new Tnode(akey, aval);
      updateHeight(cur);
      return cur;
    }  // if
    //if child != null it will call insert of cur->right
    else {
      cur->right = insert(cur->right, akey, aval);
      bf = findBalanceFactor(cur);
      if (bf < -1 || bf > 1) {
        cur = restoreBalance(cur);
      }  // if
      updateHeight(cur);
      updateSize(cur);
      return cur;
    }  // else
  }    // elseif

  else {
    cur->value.push_back(aval);
    return cur;
  }  // else
  return cur;
}  // instert()

void BST::print_inorder(Tnode *cur) {
  if (cur == NULL) {
    return;
  }  // if
  print_inorder(cur->left);
  cout << '(' << cur->key << ')';
  cout << '{';
  for (size_t i = 0; i < cur->value.size(); i++) {
    cout << cur->value[i] << " ";
  }  // for
  cout << "} ";
  print_inorder(cur->right);
}  // print_inorder();

void BST::clean(Tnode *cur) {
  if (cur == NULL) {
    return;
  }  // if
  clean(cur->left);
  clean(cur->right);
  delete cur;
}  // clean()

void BST::findPrint(Tnode *cur, string akey) {
  if (cur == NULL) {
    return;
  }  // if
  if (cur->key < akey) {
    findPrint(cur->right, akey);
  }  // if
  else if (cur->key > akey) {
    findPrint(cur->left, akey);
  }  // else if
  else {
    for (size_t i = 0; i < cur->value.size(); i++) {
      cout << cur->value[i] << " ";
    }
    cout << endl;
  }  // else
}  // findPrint()

void BST::heightPrint(Tnode *cur) {
  if (cur == NULL) {
    return;
  }  // if
  heightPrint(cur->left);
  cout << cur->height << " ";
  heightPrint(cur->right);
}  // heightPrint()

int BST::getHeight(Tnode *cur) {
  if (cur == NULL) {
    return -1;
  }  // if
  return cur->height;
}  // getHeight()

void BST::updateHeight(Tnode *cur) {
  updateSize(cur);
  int leftHeight = getHeight(cur->left);
  int rightHeight = getHeight(cur->right);
  cur->height = 1 + max(leftHeight, rightHeight);
}  // updateHeight()

void BST::printBF(Tnode *cur) {
  if (cur == NULL) {
    return;
  }  // if
  printBF(cur->left);
  cout << findBalanceFactor(cur) << " ";
  printBF(cur->right);
}  // printBF()

Tnode *BST::rightRotation(Tnode *cur) {
  Tnode *leftChild = cur->left;
  cur->left = cur->left->right;
  updateHeight(cur);
  leftChild->right = cur;
  updateHeight(leftChild);
  return leftChild;
}  // rightRotation();

Tnode *BST::leftRotation(Tnode *cur) {
  Tnode *rightChild = cur->right;
  cur->right = cur->right->left;
  updateHeight(cur);
  rightChild->left = cur;
  updateHeight(rightChild);
  return rightChild;
}  // leftRotation()

int BST::findBalanceFactor(Tnode *cur) {
  if (cur == NULL) {
    return 0;
  }  // if
  return getHeight(cur->left) - getHeight(cur->right);
}  // findBalanceFactor

Tnode *BST::restoreBalance(Tnode *cur) {
  if (findBalanceFactor(cur) < -1 && findBalanceFactor(cur->right) <= 0) {
    return leftRotation(cur);
  }  // if
  else if (findBalanceFactor(cur) < -1 && findBalanceFactor(cur->right) > 0) {
    cur->right = rightRotation(cur->right);
    return leftRotation(cur);
  }  // else if
  else if (findBalanceFactor(cur) > 1 && findBalanceFactor(cur->left) >= 0) {
    return rightRotation(cur);
  }  // else if
  else if (findBalanceFactor(cur) > 1 && findBalanceFactor(cur->left) < 0) {
    cur->left = leftRotation(cur->left);
    return rightRotation(cur);
  }  // else if
  else {
    return cur;
  }  // else
  return cur;
}  // restoreBalance()

Tnode *BST::getLeftMost(Tnode *cur) {
  if (cur != NULL) {
    if (cur->left != NULL)
      return getLeftMost(cur->left);
    else
      return cur;
  }  // if
  return NULL;
}  // getLeftMost()

Tnode *BST::remove(Tnode *cur, string akey) {
  int bf;
  if (cur == NULL) {
    return cur;
  }  // if

  if (akey > cur->key) {
    cur->right = remove(cur->right, akey);
    bf = findBalanceFactor(cur);
    if (bf > 1 || bf < -1) {
      cur = restoreBalance(cur);
    }
    updateHeight(cur);
    updateSize(cur);
  } else if (akey < cur->key) {
    cur->left = remove(cur->left, akey);
    bf = findBalanceFactor(cur);
    if (bf > 1 || bf < -1) {
      cur = restoreBalance(cur);
    }
    updateHeight(cur);
    updateSize(cur);
  } else if (cur->key == akey) {
    if (cur->left == NULL && cur->right == NULL) {  // no children
      delete cur;
      return NULL;
    } else if (cur->left == NULL) {  // one child
      Tnode *temp = cur->right;
      delete cur;
      updateSize(temp);
      return temp;
    } else if (cur->right == NULL) {
      Tnode *temp = cur->left;
      delete cur;
      updateSize(temp);
      return temp;
    } else {  // two children
      Tnode *left = getLeftMost(cur->right);
      cur->key = left->key;
      cur->value = left->value;
      Tnode *temp = remove(cur->right, cur->key);
      cur->right = temp;
      bf = findBalanceFactor(cur);
      if (bf > 1 || bf < -1) {
        cur = restoreBalance(cur);
      }
      updateHeight(cur);
      updateSize(cur);
    }
  }
  return cur;
}

int BST::getSize(Tnode *cur) {
  if (cur == NULL) {
    return 0;
  }  // if
  return cur->size;
}  // getSize()

void BST::updateSize(Tnode *cur) {
  int leftSize = getSize(cur->left);
  int rightSize = getSize(cur->right);
  cur->size = (leftSize + rightSize) + 1;
}  // updateSize()

void BST::printSize(Tnode *cur) {
  if (cur == NULL) {
    return;
  }  // if
  printSize(cur->left);
  cout << getSize(cur) << " ";
  printSize(cur->right);
}  // printSize()

