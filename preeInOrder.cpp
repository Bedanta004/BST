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

    int searchInorder(int inorder[], int size, int target){
        for(int i=0; i<size; i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    
    //preIndex always taken with reference
    Node* constructTreeFromPreAndInorderTraversal( int preorder[], int inorder[], int &preIndex, int inorderStart, int inorderEnd, int size) {
  //base case
  if(preIndex >= size || inorderStart > inorderEnd) {
    return NULL;
  }

  //1 case main solve krta hu
  int element = preorder[preIndex];
  preIndex++;
  Node* root = new Node(element);
  //element search krna padega  inorder me 
  int position = searchInorder(inorder, size, element);
  
  //baaaki recursion sambhal lega
  root->left = constructTreeFromPreAndInorderTraversal(preorder, inorder, preIndex, inorderStart, position-1, size);

  root->right = constructTreeFromPreAndInorderTraversal(preorder, inorder, preIndex, position+1, inorderEnd, size);

  return root;

}



int main(){
    int inorder[] = {10,8,6,2,4,12};
    int preorder[] = {2,8,10,6,4,12};
    int size = 6;
    //start
    int preorderIndex = 0;
    int inorderStart = 0;
    //end index
    int inorderEnd = 5;

    Node* root = constructTreeFromPreAndInorderTraversal(preorder, inorder, preorderIndex, inorderStart, inorderEnd, size);
    cout<<"Printing the entire tree: "<<endl;
    levelorder(root);
    return 0; 
}