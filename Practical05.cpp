#include<bits/stdc++.h>
using namespace std;

// Define the structure for a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        return new Node(value);
    }
    
    // If the value is less than the root's data, insert it into the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than or equal to the root's data, insert it into the right subtree
    else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to find the number of nodes in the longest path from the root
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// Function to find the minimum data value found in the tree
int findMin(Node* root) {
    if (root == NULL)
        return INT_MAX;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return min(root->data, min(leftMin, rightMin));
}

// Function to change a tree so that the roles of the left and right pointers are swapped at every node
void swapLeftAndRight(Node* root) {
    if (root == NULL)
        return;
    swap(root->left, root->right);
    swapLeftAndRight(root->left);
    swapLeftAndRight(root->right);
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void display(Node *root){
    if(root != NULL){
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                Node* currentNode = q.front();
                q.pop();
                cout << currentNode->data << " ";
                if (currentNode->left != NULL)
                    q.push(currentNode->left);
                if (currentNode->right != NULL)
                    q.push(currentNode->right);
            }
            cout << endl;
        }
    }
}

int main() {
    Node* root = NULL;
    int choice;
    int result,result2,result3;
    
    char ch;
    do{
        cout<<"1. Insert"<<endl;
        cout<<"2. number of nodes in the longest path from the root"<<endl;
        cout<<"3. minimum data value found in the tree"<<endl;
        cout<<"4. change a tree so that the roles of the left and right pointers are swapped at every node"<<endl;
        cout<<"5. search"<<endl;
        cout<<"6. Display(BFS)"<<endl;
        cout<<"Enter choice :";

        cin>>choice;
        switch(choice){
            case 1:
                int n;
                cout<<"How many nodes you want to insert ? :";
                cin>>n;
                for(int i=0;i<n;i++){
                    int value;
                    cout<<"Enter value to insert :";
                    cin>>value;
                    root=insert(root,value);
                }
                break;
            case 2:
                result=maxDepth(root);
                cout<<"No. of nodes in the longest path from the root are "<<result<<endl;
                break;
            case 3:
                result2=findMin(root);
                cout<<"minimum value found in the tree is "<<result2<<endl;
                break;
            case 4:
                swapLeftAndRight(root);
                break;
            case 5:
                int key;
                cout<<"Enter value to be search :";
                cin>>key;
                result3=search(root,key);
                if(result3==0) cout<<"Value Not Found !"<<endl;
                else cout<<"Value Found !"<<endl;
                break;
            case 6:
                display(root);
                break;
            default:
                cout<<"invalid Input "<<endl;
                break;
        }
        cout<<"Do you want to continue (y/n)? :";
        cin>>ch;
    }while(ch=='y');

    return 0;
}

