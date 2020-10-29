#include <stdlib.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<fstream>
using namespace std;

#include "bst.h"


int main(int argc, char* argv[]){

	
    BST numbers;
	string command;
	while(cin >> command){//
		if(command == "print_inorder"){
			numbers.print_inorder();
			cout << endl;
		}else if(command == "heightPrint"){
			numbers.heightPrint();
			cout << endl;
		}else if(command == "insert"){
			string word;
			cin >> word;
			int len ;
			cin >> len;
			string akey = word.substr(0, len);
			numbers.insert(akey, word);
		}else if(command == "sizeDifference"){
			string k1, k2;
			cin >> k1 >> k2;
			int res = numbers.sizeDifference(k1, k2);
			cout << "The size of the difference of " << k1 << " and " << k2 << " is " << res << endl;
		}else if(command == "printHeight1"){
			numbers.printHeight1();
		}else if(command == "sizeUnion"){
			string k1, k2;
			cin >> k1 >> k2;
			int res = numbers.sizeUnion(k1, k2);
			cout << "The size of the union of " << k1 << " and " << k2 << " is " << res << endl;		
		}
		else if(command == "printLeaves"){
			cout << "Leaves of the tree are:" <<  endl;
			numbers.printLeaves();
		}else{
			cerr << "ERROR: command " << command << " is not found." << endl;
		}
	}//while

    return 0;

}//main()
