#include <iostream>
using namespace std;

#include "tnode.h"
#ifndef BST_H
#define BST_H

class BST {
 public:
  BST() : root(NULL){};
  ~BST() {
    clean(root);
    root = NULL;
  };

  void insert(string akey, string aval) {
    if (root == NULL) {
      root = new Tnode(akey, aval);
      return;
    }
    root = insert(root, akey, aval);
    updateHeight(root);
    updateSize(root);
  };
  void print_inorder() {
    print_inorder(root);
    cout << endl;
  };

  void heightPrint() {
    heightPrint(root);
    cout << endl;
  };

  void printLeaves() {
	  printLeaves(root);
  };

  int sizeUnion(string akey1, string akey2) {
	  return sizeUnion(root, akey1, akey2);
  }

  void printHeight1() {
	  printHeight1(root);
  }

  int sizeDifference(string akey1, string akey2) {
	  sizeDifference(root, akey1, akey2);
  }

 private:
  int getSize(Tnode *cur) {
    if (cur == NULL) 
		return 0;
    return 1 + getSize(cur->left) + getSize(cur->right);
  }  // getSize

  void updateSize(Tnode *cur) {
    cur->size = 1 + getSize(cur->left) + getSize(cur->right);
  }  // updateSize

  Tnode *getLeftmost(Tnode *cur);

  int getHeight(Tnode *cur) {
    if (cur == NULL)
      return -1;
    else
      return cur->height;
  };

  void updateHeight(Tnode *cur);

  void heightPrint(Tnode *cur);

  Tnode *insert(Tnode *cur, string akey, string aval);

  void print_inorder(Tnode *cur);

  void clean(Tnode *cur);

  Tnode *copy(Tnode *cur);

  Tnode *root = NULL;

  void printLeaves(Tnode *cur);

  int sizeUnion(Tnode *cur, string akey1, string akey2);

  void printHeight1(Tnode *cur);

  int sizeDifference(Tnode *cur, string akey1, string akey2);
};

#endif
