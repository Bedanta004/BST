#include<iostream>
#include<queue>
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

    void preorder(Node* root){
        //base case
        if(root == NULL){
            return;
        }
        // N L R
        // N
        cout<<root->data<<" ";
        // L
        preorder(root->left);
        // R
        preorder(root->right);

    }

    void inorder(Node* root){
        //base case
        if(root == NULL){
            return;
        }
        // L
        inorder(root->left);
        // N
        cout<<root->data<<" ";
        // R
        inorder(root->right);
    }

    void postorder(Node* root){
        //base case
        if(root == NULL){
            return;
        }
        // L
        postorder(root->left);
        // R
        postorder(root->right);
        // N
        cout<<root->data<<" ";
    }

    void levelorder(Node* root){
        queue<Node*> q;
        q.push(root);
        //NULL indicates that level completed
        q.push(NULL);

        //traversal
        while(q.size() > 1){
            Node* front = q.front();
            q.pop();

            if(front == NULL){
                cout<<endl;
                q.push(NULL);

            }
            else{
               //valid node
                cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }

            }
        }
    }

    int main(){
    Node* root = createTree();
    //cout<<root->data<<endl;
    cout<<"Printing Preorder : ";
    preorder(root);
    cout<<endl;

    cout<<"Printing Inorder : ";
    inorder(root);
    cout<<endl;

    cout<<"Printing Postorder: ";
    postorder(root);
    cout<<endl;

    cout<<"Levelorder Traversal : "<<endl;
    levelorder(root);
    cout<<endl;
    }
 