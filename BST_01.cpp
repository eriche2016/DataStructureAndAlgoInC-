// C++ for a binary tree 

#include <iostream>

using namespace std;

// define the node for a tree
// 定义树的节点类
struct Node {
    int key_value;
    Node* left_child;
    Node* right_child;
};

// 定义二叉树类
class BinaryTree {
    // 树的根节点 
    Node* root;
    // helper function
    void destroy_tree(Node* leaf);
    void insert(int key, Node* leaf);
    Node* search(int key, Node* leaf);
    void printAll(Node* root);
public:
    //建钩子
    BinaryTree();
    // 析构子
    ~BinaryTree();

    void insert(int key);
    Node* search(int key);
    // 自底而上的释放树的各个节点
    void destroy_tree();
    bool isEmpty();
    void printTree();
}; 
// 建钩子
BinaryTree::BinaryTree() {
	root = NULL;
}
// 析构子
BinaryTree::~BinaryTree(){
	destroy_tree();
}
//递归释放树的所有节点
void BinaryTree::destroy_tree(Node* leaf) {
	if(leaf != NULL) { 
		destroy_tree(leaf->left_child); // 释放leaf的左子树
		destroy_tree(leaf->right_child); // 释放leaf的右子树
		delete leaf; // 释放完左右子树后，最后释放leaf节点
	}
}
// 插入节点
void BinaryTree::insert(int key, Node* leaf) {
	if(key < leaf->key_value) { // key小于leaf 的键值，则插在leaf左子树
		if(leaf->left_child != NULL)  // 左子树非空
			insert(key, leaf->left_child); // 递归的插入到左孩子节点为根节点的子树上
		else {  // 左子树为空，即此时leaf为叶子节点的左侧
		      // 创建节点
			leaf->left_child = new Node;
			leaf->left_child->key_value = key;
			leaf->left_child->left_child = NULL;
			leaf->left_child->right_child = NULL;
		}

	}
	else if(key > leaf->key_value) { // 同理
		if(leaf->right_child != NULL) {
			insert(key, leaf->right_child);
		}
		else {
			leaf->right_child = new Node;
			leaf->right_child->key_value = key;
			leaf->right_child->left_child = NULL;
			leaf->right_child->right_child = NULL;
		}
	}
}

Node* BinaryTree::search(int key, Node* leaf) {
	if(leaf != NULL) {
		if(key == leaf->key_value) {
			return leaf;
		}
		if(key < leaf->key_value) {
			return search(key, leaf->left_child);
		}
		else 
			return search(key, leaf->right_child);
	}
	else return NULL;
}

void BinaryTree::insert(int key) {
	if(root != NULL) { // 非空树
		insert(key, root);
	}
	else { // 为空树
		root = new Node;
		root->key_value = key;
		root->left_child = NULL;
		root->right_child = NULL;
	}
}

Node* BinaryTree::search(int key) {
	return search(key, root);
}

void BinaryTree::destroy_tree() {
	destroy_tree(root);
}

bool BinaryTree::isEmpty() {
    return (root == NULL);
}

void BinaryTree::printAll(Node* root) {
    if(root != NULL) {
        //中序遍历
        printAll(root->left_child); // 先打印左子树
        cout << root -> key_value << endl; // 打印根节点
        printAll(root->right_child); // 打印右子树
    }
}

void BinaryTree::printTree() {
    printAll(root);
}

int main() {

	cout << "building the tree ...." << endl;
    BinaryTree bt;

    /*

	       10
	     /    \
	    6      14
	   / \    /  \
	  5   8  11  18
	  
	    
     */

    bt.insert(10);
    bt.insert(6); 
    bt.insert(5);
    bt.insert(8); 
    bt.insert(14); 
    bt.insert(11);
    bt.insert(18); 

    cout << "all nodes has been inserted" << endl;
    cout << "tree building done!!!" << endl;

    // print the tree
    cout << "----------请叫我分割线--------" << endl;
    cout << "print the whole tree " << endl;
    bt.printTree();

    // search node 
    cout << "----------请叫我分割线--------" << endl;
    cout << "print a number to search: ";
    int testNumber;
    cin >> testNumber;
    Node* result = bt.search(testNumber);
    if(result != NULL) {
    	cout << "found" << endl;
    }   
    else {
    	cout << "not found" << endl;
    }

    cout << "----------请叫我分割线--------" << endl;
    cout << "destroy_tree" << endl;
    bt.destroy_tree();
    
    return 0;
}



