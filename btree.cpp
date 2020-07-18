#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Btree_node {
public:
	int num_keys;
	vector<int> keys;
	bool leaf;
	vector<Btree_node*> children;
	Btree_node();
	Btree_node(int);
};


class Btree {
public:
	Btree_node *root;
	int min_degree;
	Btree(int);
};


Btree_node::Btree_node() {
	num_keys = 0;
	leaf = true;
}


Btree_node::Btree_node(int key) {
	keys.push_back(key);
	num_keys = 1;
}


Btree::Btree(int y) {
	min_degree = y;
	root = new Btree_node();
}

// For insert we need to consider 2 cases:
// 	1) Tree is Full.
// 	2) Tree is not Full.
// We must write function that splits tree if tree is full.

//////////////////////////// Why split child argument is 1? ///////////////////////////////////////////
void Insert_Btree(Btree* T, int val) {
	Btree_node* root = T->root;
	if (root->num_keys == (2*T->min_degree+1)) {
		Btree_node *new_node = new Btree_node(val);
		T->root = new_node;
		new_node->leaf = false;
		new_node->num_keys = 0;
		new_node->children.push_back(root);
		Split_Children(new_node, 1);
		Insert_Nonfull_Btree(new_node, val);
	} else 	Insert_Nonfull_Btree(root, val);
}

int main() {
	printf("Hello, Girl!\n");
	Btree *T = new Btree(2);\
	
	free(T);
	return 0;
}
