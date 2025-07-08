#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
   
};
 //it returns root node of the created tree
    Node* createTree(){ 
        cout<<"Enter the value for node :  "<<endl;
        int data;
        cin>>data;
        //base case
        if(data == -1){
            return NULL;
        }
        //step 1: create node
        Node* root = new Node(data);
        //step 2: create left subtree
        cout<<"leaf of Node : "<<root->data<<endl;
        root->left = createTree();
        //step3 :create right subtree
        cout<<"right of Node : "<<root->data<<endl;
        root->right = createTree();
        return root;
    }

int main(){
    Node* root = createTree();
    cout<<root->data<<endl;

}