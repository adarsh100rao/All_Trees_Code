#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;

    }

};
node* buildtree(node* root){
    cout << "enter the root: " << '\n';
    int data;
    cin >> data;
    root  = new node(data);
    if(data == -1){
        return NULL;

    }
    
    cout << "enter data for inserting in left of  " << data <<'\n';
    root -> left = buildtree(root -> left);
    cout << "enter data for iinserting in right of " << data << '\n';
    root -> right = buildtree(root -> right);
    return root;
    
}
void levelorder(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        //cout << temp -> data << " ";
        q.pop();
        if(temp == NULL){ // purana level complee ho chuka h 
            cout << '\n';
            if(!q.empty()){
                q.push(NULL); 
            }
        } 
        else{
            cout << temp -> data << " ";
        if(temp -> left){ 
            q.push(temp -> left);
            
        }
        if(temp -> right){
            q.push(temp ->right);
        }
        } 
    }


}
int main(){
    node* root = NULL;
    // creating 
    root = buildtree(root);
    // level order
    cout << "printing the level orde travesdal:" << '\n';
    levelorder(root);
    return 0;
}