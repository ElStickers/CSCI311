#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef TNODE_H
#define TNODE_H

class Tnode {
 private:
  /* data */
 public:
  Tnode() : left(NULL), right(NULL){};
  Tnode(string akey, string aval) {
    key = akey;
    value.push_back(aval);
    height = 0;
    left = NULL;
    right = NULL;
    bf = 0;
    size = 1;
  };
  string key;
  vector<string> value;
  int height;
  Tnode *left;
  Tnode *right;
  int bf;
  int size;
};

#endif
