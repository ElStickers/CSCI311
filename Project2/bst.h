#include <iostream>
using namespace std;

#include "tnode.h"
#ifndef BST_H
#define BST_H

class BST {
 private:
  Tnode *insert(Tnode *cur, string akey, string aval);
  void print_inorder(Tnode *cur);
  Tnode *root = NULL;
  void clean(Tnode *cur);
  void findPrint(Tnode *cur, string akey);
  void heightPrint(Tnode *cur);
  int getHeight(Tnode *cur);
  void updateHeight(Tnode *cur);
  void printBF(Tnode *cur);
  Tnode *rightRotation(Tnode *cur);
  Tnode *leftRotation(Tnode *cur);
  int findBalanceFactor(Tnode *cur);
  Tnode *restoreBalance(Tnode *cur);
  Tnode *getLeftMost(Tnode *cur);
  Tnode *remove(Tnode *cur, string akey);
  Tnode *removeLeftMost(Tnode *cur);
  int getSize(Tnode *cur);
  void updateSize(Tnode *cur);
  void printSize(Tnode *cur);
  bool findK(Tnode *cur, string k);
  void collect(Tnode *cur, string k, vector<string> &v);
  string scan(vector<string> k1, vector<string> k2);
  string findKthSmallest(Tnode *cur, int k);

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
    } else {
      root = insert(root, akey, aval);
    }
  };

  void print_inorder() {
    print_inorder(root);
    cout << endl;
  };

  void findPrint(string akey) {
    findPrint(root, akey); 
  };

  void heightPrint() {
    heightPrint(root);
    cout << endl;
  };

  void printBF() {
    printBF(root);
    cout << endl;
  };

  void remove(string akey) { 
    root = remove(root, akey); 
  };

  void printSize() {
    printSize(root);
    cout << endl;
  };

  string findLCA(string k1, string k2) {
    vector<string> v1, v2;
    if (findK(root, k1) == false || findK(root, k2) == false) {
      return " ";
    }
    collect(root, k1, v1);
    collect(root, k2, v2);
    return scan(v1, v2);
  };

  string findKthSmallest(int k) {
    return findKthSmallest(root, k);
  }
};

#endif