class Solution {
  public:
  
    int countNodes(struct Node* root){
        if(root == NULL) return 0;
        int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
        return ans;
        
    }
    
    
    
    bool iscbt(struct Node* root, int index, int cnt){
        if(root == NULL) return true;
        if(index >= cnt) return false;
        else{
            bool left = iscbt(root -> left, 2*index +1 ,cnt);
            bool right = iscbt(root -> right, 2*index +2 ,cnt);
            return left && right;


        }
    }
    
    
    
    bool isMaxOrder(struct Node* root){
        if(root -> left == NULL && root -> right == NULL){
            return true;
        }
        if(root -> right == NULL){
            return root -> data > root -> left -> data;
        }
        else{
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            if(left && right && root -> data > root -> right -> data && root -> data > root -> left -> data){
                return true;
            }
            return false;
        }
    }
    
    
    
    
    
    bool isHeap(struct Node* tree) {
        // code here
        int index =0;
        int totalcount = countNodes(tree);
        if(iscbt(tree, index, totalcount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};