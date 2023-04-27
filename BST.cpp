#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);//first traverse left tree
    cout << root->key << " ";//print the root
    traverseInOrder(root->right);//at last traverse the right tree
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    // If tree is empty, create a new node
  if (node == NULL) {
    struct node *temp = new struct node;
    temp->key = key;
    temp->left = temp->right = NULL;//assignning left and right child nodes to null
    return temp;
  }

  // Otherwise, traverse the tree recursively
  if (key <= node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);

  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root; // Base case

 // search for the key while traversing the tree recursively
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  // If key is same as root's key, then this is the node to be deleted
  else {
    // Node with only one child or no child
    if (root->left == NULL) {//directly delete the right child if key matches
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {//directly delete the left child if key matches
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // Node with two children: Get the smallest in the right subtree and assighn to temp
    struct node *temp = root->right;
    while (temp->left != NULL)
      temp = temp->left;

    // Copy the temp's content to this node
    root->key = temp->key;

    // Delete the temp
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
