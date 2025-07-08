#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this -> data = val;
        this -> left = NULL;
        this ->right = NULL;
    }
};

Node* createTree(){
    cout<<"Enter the value of node : "<<endl;
    int value;
    cin>>value;

    if(value == -1){
        return NULL;
    }
    //create Node
    Node* root = new Node(value);
    cout<<"Entering in left of: "<<value<<endl;
    root -> left = createTree();
    cout<<"Entering in right of: "<<value<<endl;
    root->right = createTree();
    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){
        queue<Node*> q;
        q.push(root);
        //NULL indicates that level completed
        q.push(NULL);
        cout<<endl;

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
    
    void printLeftView(Node* root, int level, vector<int>& leftView){
        //base case
        if(root == NULL){
            return;
        }
        if(level == leftView.size()){
            //matlab leftview ki node mil gayi, store karlo
            leftView.push_back(root->data);
        }
        //recursion call
        printLeftView(root->left, level+1, leftView);
        printLeftView(root->right, level+1, leftView);

    }

     void printRightView(Node* root, int level, vector<int>& rightView){
        //base case
        if(root == NULL){
            return;
        }
        if(level == rightView.size()){
            //matlab leftview ki node mil gayi, store karlo
            rightView.push_back(root->data);
        }
        //recursion call
        //first the call of right then left
        printRightView(root->right, level+1, rightView);
        printLeftView(root->left, level+1, rightView);
        
    }

    int main(){
        Node* root = createTree();

        // vector<int>leftView;
        // printLeftView(root, 0 , leftView);

        // cout<<"Printing leftview: "<<endl;
        // for(int i=0; i<leftView.size(); i++){
        //     cout<<leftView[i]<<" ";
        // }/

        //rightview
        vector<int>rightView;
        printRightView(root, 0 , rightView);

        cout<<"Printing leftview: "<<endl;
        for(int i=0; i<rightView.size(); i++){
            cout<<rightView[i]<<" ";
        }

    }