// #include <bits/stdc++.h>
// using namespace std;
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int data){
//         this->data = data;
//         this->left = nullptr;
//         this->right = nullptr;
// }
// };

// class BinaryTree {
//     public:
//     Node* root;

//     BinaryTree(){
//         root = nullptr;
//     }

//     // void addNode(int data) {
//     //     Node* newNode = new Node(data);

//     //     if (root == nullptr) {
//     //     root = newNode;
//     //     } 
//     //     else {
//     //         Node* focusNode = root;
//     //         Node* parent;

//     //         while (true) {
//     //             parent = focusNode;

//     //             if (data < focusNode->data) {
//     //                 focusNode = focusNode->left;
//     //                 if (focusNode == nullptr) {
//     //                     parent->left = newNode;
//     //                     return;
//     //                     }
//     //                 } 
//     //             else {
//     //                 focusNode = focusNode->right;
//     //                 if (focusNode == nullptr) {
//     //                     parent->right = newNode;
//     //                     return;
//     //                 }
//     //             }
//     //         }
//     //     }
//     // }
//     void addNode(Node* root, int val){
//         if(root = NULL){
//             root = new Node(val);
            
//         }
//         else{

//         }
//     }

//     //50 25 12 37 30 43 75
//     void preOrderTraversal(Node* focusNode) {
//         if (focusNode != nullptr) {
//             std::cout << focusNode->data << " ";
//             preOrderTraversal(focusNode->left);
//             preOrderTraversal(focusNode->right);
//         }
//     }

//     //12 25 30 37 43 50 75
//     void Inorder(struct Node* node){
//     if (node == NULL)
//         return;
 
//     /* first recur on left child */
//     Inorder(node->left);
 
//     /* then print the data of node */
//     std::cout << node->data << " ";
 
//     /* now recur on right child */
//     Inorder(node->right);
// }
// };

// int main() {
//     BinaryTree tree;

//     tree.addNode(50);
//     tree.addNode(25);
//     tree.addNode(75);
//     tree.addNode(12);
//     tree.addNode(37);
//     tree.addNode(43);
//     tree.addNode(30);
//     cout << "pre Ordered traversal" << endl;
//     tree.preOrderTraversal(tree.root);
//     std::cout << std::endl;
//     cout <<"in order traversal" <<endl;
//     tree.Inorder(tree.root);

//     return 0;
// }


