#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "bst.h"

int main(int argc, char const *argv[]) {
  BST arbol;
  vector<string> sub;
  string command;
  string word;
  string akey;
  string kSmallest;
  string LCA;
  int len;
  int k;
  while (cin >> command) {
    if (command == "print_inorder") {
      arbol.print_inorder();
      cout << endl;
    } else if (command == "heightPrint") {
      arbol.heightPrint();
      cout << endl;
    } else if (command == "printBF") {
      arbol.printBF();
      cout << endl;
    } else if (command == "findPrint") {
      cin >> akey;
      arbol.findPrint(akey);
    } else if (command == "insert") {
      cin >> word;
      cin >> len;
      string subWord = word.substr(0, len);
      arbol.insert(subWord, word);
    } else if (command == "remove") {
      cin >> akey;
      arbol.remove(akey);
    } else if (command == "printSize") {
      arbol.printSize();
      cout << endl;
    } else if (command == "findLCA") {
      string k1;
      string k2;
      cin >> k1;
      cin >> k2;
      LCA = arbol.findLCA(k1, k2);
      cout << LCA << endl;
    } else if (command == "findKthSmallest") {
      cin >> k;
      cout << arbol.findKthSmallest(k) << endl;
    } else if (command == "printLongestPath") {
      arbol.printLongestPath();
      cout << endl;
    } else if (command == "collectSubtree") {
      cin >> akey;
      arbol.collectSubtree(sub, akey);
      cout << endl;
    }else {
      cerr << "ERROR: command " << command << " ist not found." << endl;
    }  // else
  }    /// while
  return 0;
}  // main()
