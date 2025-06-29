#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    //its not the first root
    if(data> root->data){
       root->right = insertIntoBst(root->right, data);
    }
    else{
        root->left = insertIntoBst(root->left, data);
    }
    return root;
}

void levelOederTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void preOrder(Node* root){
    //NLR
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    //LNR
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    //LRN
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void createBST(Node* &root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBst(root, data);
        cin>>data;
    }
}

Node* minValue(Node* root){
    if(root == NULL){
        cout<<"NO Min Value"<<endl;
        return NULL;
    }
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    //leftmost element is the minimum
    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    //rightmost element is max
    return temp;
}


bool searchInBst(Node* root, int target){
  //base case
  if(root == NULL){
    return false;
  }  
   //we will solve 1 case
   if(root->data == target){
    return true;
   }
   //recursion will handle
   //left or right
   bool leftAns = false;
   bool rightAns = false;
   if(target > root->data){
    rightAns = searchInBst(root->right, target);
   }
   else{
    leftAns = searchInBst(root->left, target);
   }
   //if ans is in right or left, true will return
   return leftAns || rightAns;
}

int main(){
    Node* root = NULL;
    createBST(root);

    levelOederTraversal(root);

    cout<<endl<<"Inorder: ";
    inOrder(root);
    cout<<endl<<"Preorder: ";
    preOrder(root);
    cout<<endl<<"PostOrder: ";
    postOrder(root); 

    cout<<endl;
    Node* minNode = minValue(root);
    if(minNode == NULL){
        cout<<"There is no node in tree so no min value"<<endl;
    }
    else{
        cout<<"Min Value: "<<minNode->data<<endl;
    }

    cout<<endl;
    Node* maxNode = maxValue(root);
    if(maxNode == NULL){
        cout<<"There is no node in tree so no max value"<<endl;
    }
    else{
        cout<<"Max Value: "<<maxNode->data<<endl;
    }

    int t;
    cout<<"Enter the target: "<<endl;
    cin>>t;

    while(t != 1){
        bool ans = searchInBst(root, t);
        if(ans == true){
            cout<<"Target found"<<endl;
        }
        else{
            cout<<"Target not found"<<endl;
        }
        cout<<"Enter the target: "<<endl;
        cin>>t;
    }

}