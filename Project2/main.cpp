#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "bst.h"

int main(int argc, char const *argv[]) {
  BST arbol;
  string command;
  string word;
  string akey;
  int len;
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
    } else {
      cerr << "ERROR: command " << command << " ist not found." << endl;
    }  // else
  }    /// while
  return 0;
}  // main()
