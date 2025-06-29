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

Node* deleteFromBST(Node* root, int target){
    //find target
    //delete target
    if(root == NULL){
        return NULL;
    }
    if(root->data == target){
        //now delete
        //4 cases

        //case 1, left node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //case 2, left non null and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        //case 3, left null and right non null
        else if(root->left == NULL && root->right != NULL){
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        //case 4, left and right both are non null
        else{
            //a -> left subtree ki max value lao
            Node* maxi = maxValue(root->left);
            //replacement
            root->data = maxi->data;

            //delete actual maxi wala node
            //updated tree will be linked to root->left
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }

    }
    else if(root->data > target){
        //go to left
        //updated tree added at left or attatched
        root->left = deleteFromBST(root->left, target);
    }
    else{
        //goto right
        //updated tree added at right or attatched
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

Node* bstFromInorder(int inorder[], int s, int e){
    //base case
    if(s>e){
        return NULL;
    }

    //1 case solve 
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    //recursion will handle
    //we are traveling from start to mid-1
    root->left = bstFromInorder(inorder, s, mid-1);
     //we are traveling from mid+1 to end
    root->right = bstFromInorder(inorder, mid+1, e);

    return root;
}

int main(){
    int inorder[] = {10,20,30,40,50,60,70};
    int size = 7;
    int start = 0;
    int end = size-1;
    Node* root=bstFromInorder(inorder, start, end);
    levelOederTraversal(root);

}