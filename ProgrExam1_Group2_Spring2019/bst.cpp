#include<iostream>
using namespace std;

#include "bst.h"
	



Tnode* BST::getLeftmost(Tnode* cur){
	if(cur == NULL)
		return NULL;
	if(cur->left == NULL)
		return cur;
	return getLeftmost(cur->left);
}//getLeftmost

void BST::updateHeight(Tnode *cur){
	if(cur == NULL)
		return;
	int hl = -1, hr = -1;
	if(cur->left != NULL)
		hl = cur->left->height;
	if(cur->right != NULL)
		hr = cur->right->height;
	cur->height = (hl > hr) ? (hl + 1) : (hr + 1);

}//updateHeight
				


void BST::heightPrint(Tnode *cur){
	if(cur != NULL){
		heightPrint(cur->left);
		cout << cur->height << " ";
		heightPrint(cur->right);
	}

}

void BST::print_inorder(Tnode *cur){
        if(cur == NULL)
                return;
        print_inorder(cur->left);
        cout << "(" << cur->key << "){";
		int asize = (int)(cur->value).size();
		for(int i = 0; i < asize; i++)
			cout << (cur->value)[i] << " " ;
		cout << "} ";
        print_inorder(cur->right);
}//print_inorder


void BST::clean(Tnode *cur){
        if(cur == NULL)
                return;
        clean(cur->left);
        clean(cur->right);
        delete cur;
}//clean()

Tnode* BST::insert(Tnode *cur, string akey, string aval){
               if(akey < cur->key){
                        if(cur->left == NULL){
                                cur->left = new Tnode(akey, aval);
								updateHeight(cur);
								updateSize(cur);
                                }//if found place
                        else{
                                cur->left = insert(cur->left, akey, aval);
								updateHeight(cur);
								updateSize(cur);
						}//else
						
                }//if 
                else if(akey > cur->key){
                        if(cur->right == NULL){
                                cur->right = new Tnode(akey, aval);
								updateHeight(cur);
								updateSize(cur);
                                }
                        else{
                                cur->right = insert(cur->right, akey, aval);
									updateHeight(cur);
								updateSize(cur);
						
						}
						
                }//else if
                else{
					(cur->value).push_back(aval);
                        }

				return cur;
      
}//insert()

