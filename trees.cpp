
/*
LEVEL ORDER TRAVERSAL
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                    
                    
                }
                level.push_back(node -> val);
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};


ITERATIVE PREORDER TRAVERSAL
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root -> val);
            if(root -> right){
                st.push(root -> right);
            }
            if(root -> left){
                st.push(root -> left);
            }
        }
        return preorder;
        
        
    }
};


ITERATIVE INORDER LEETCODE
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>  inorder;
        while(true){
            if(root){
                st.push(root);
                root = root -> left;
            }
            else{
                if(st.empty()){
                    break;
                }
                root = st.top();
                st.pop();
                inorder.push_back(root -> val);
                root = root -> right;
            }
        }
        return inorder;
        
    }
};


PREORDER, POSTORDER, INORDER IN ONE TRAVDERSAL
#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({
    root,
    1
  });
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({
          it.first -> left,
          1
        });
      }
    }

    // this is a part of in 
    // increment 2 to 3 
    // push right 
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({
          it.first -> right,
          1
        });
      }
    }
    // don't push it back again 
    else {
      post.push_back(it.first -> data);
    }
  }
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right = newNode(3);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  vector < int > pre, in , post;
  allTraversal(root, pre, in , post);

  cout << "The preorder Traversal is : ";
  for (auto nodeVal: pre) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto nodeVal: in ) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto nodeVal: post) {
    cout << nodeVal << " ";
  }
  cout << endl;

  return 0;
}   


MAXIMUM HEIGHT OF A BINARY TREE
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return 1 + max(left, right);
        
    }
};


CHECK FOR BALANCED BINARY TREE
class Solution {
public:
int dfs_height(TreeNode* root){
        if(root == NULL) return 0;

        int left_height = dfs_height(root -> left);
        if(left_height == -1) return -1;

        int right_height = dfs_height(root -> right);
        if(right_height == -1) return -1;

        if(abs(left_height - right_height) > 1) return -1;
        return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs_height(root) != -1;
        
    }
};


DIAMETER OF A BINARY TREE
class Solution {
public:
    int find(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int lh = find(root -> left,maxi);
        int rh = find(root -> right , maxi);
        maxi = max(maxi, lh+rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =  0;
        find(root,diameter);
        return diameter;
        
    }
};


MAXIMUM PATH SUM 
class Solution {
public:
    int max_sum(TreeNode* root, int &maxi){
        if(!root) return 0;
        int leftsum = max(0,max_sum(root -> left, maxi));
        int rightsum  = max(0, max_sum(root -> right, maxi));
        maxi = max(maxi , leftsum + rightsum + root -> val);
        return max(leftsum, rightsum) + root -> val;
        
    }
    int maxPathSum(TreeNode* root) {
        int currsum = INT_MIN;
        max_sum(root, currsum);
        return currsum;
        
    }
};

CHECK TWO TREES ARE INDENTICAL OR NOT
class Solution {
public:
    // preorder traversal check kiya h dono ka
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return p == q;
        }
        return (p -> val == q -> val) && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        
    }
};


ZIG-ZAG TRAVERSAL
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // finding position to fill the values;
                int index = flag ? i : (size - i - 1);
                row[index] = node -> val;
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;
        
    }
};



BOUNDARY TRAVERSAL
#include <bits/stdc++.h>

using namespace std;

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}


VERTICAL ORDER TRAVERSAL
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node -> val);
            if(node -> left){
                q.push({node -> left, {x-1, y+1}});
            }
            if(node -> right){
                q.push({node -> right, {x+1, y+1}});
            }

        }
        vector<vector<int>> ans;
        for(auto p : mp){
            vector<int> col;
            for(auto r : p.second){
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};


TOP VIEW OF BINARY TREE
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(mp.find(line) == mp.end()){
                mp[line] = node -> data;
                
            }
            if(node -> left != NULL){
                q.push({node -> left, line - 1});
            }
            if(node -> right != NULL){
                q.push({node -> right,line + 1});
            }
        
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};


BOTTOM VIEW OF BINARY TREE
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == NULL)return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            mp[line] = node -> data;
            if(node -> left != NULL){
                q.push({node -> left, line -1});
            }
            if(node -> right != NULL){
                q.push({node -> right, line + 1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


RIGHT VIEW OF A BINARY TREE
class Solution {
public:
    void recursion(TreeNode* root, int level, vector<int> &res){
        if(root == NULL){
            return;
        }
        if(level == res.size()){
            res.push_back(root -> val);

        }
        recursion(root -> right, level + 1, res);
        recursion(root -> left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;

        
    }
};

CHECK FOR SYMMETRIC TREES (MIRRORED TREES)
class Solution {
public:
    bool is_sym(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left -> val != right -> val){
            return 0;
        }
        return is_sym(left -> left, right -> right) && is_sym(left -> right, right -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return 1;
        return is_sym(root -> left, root -> right);
        
    }
};


ROOT TO NODE PATH
bool getPath(node * root, vector < int > & arr, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  arr.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, arr, x) ||
    getPath(root -> right, arr, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  arr.pop_back();
  return false;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}


LOWEST COMMON ANCESTOR 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }


        
    }
};


// MAXIMUM WIDTH OF A BINARY TREE
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int sz = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i = 0; i<sz; i++){
                long long cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = cur_id;
                if(i == sz - 1) last = cur_id;
                if(node -> left){
                    q.push({node -> left, cur_id*2 + 1});
                }
                if(node -> right){
                    q.push({node -> right, cur_id*2 + 2});
                }
                ans = max(ans, last - first + 1);
            }
           
        }
        return ans;
        
    }
};


CHILDREN SUM PROPERTY {GFG}
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        int leftnode = 0, rightnode = 0;
        if(root == NULL) return 1;
        if(root -> left == NULL && root -> right == NULL) return 1;
        if(root -> left){
            leftnode += root -> left -> data;
        }
        if(root -> right){
            rightnode += root -> right -> data;
        }
        if(root -> data == leftnode + rightnode && isSumProperty(root -> left) && isSumProperty(root -> right) ){
            return 1;
        }
        else{
            return 0;
        }
        
     
    }
};



PRINT ALL NODES AT DISTANCE K 
class Solution {
public:
    void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left){
                mp[current -> left] = current;
                q.push(current -> left);
            }
            if(current -> right){
                mp[current -> right] = current;
                q.push(current -> right);
            }

        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mark_parents(root, mp, target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            int sz = q.size();
                if(curr_level++ == k){
                    break;
                }
                for(int i = 0; i<sz; i++){
                    TreeNode* current  = q.front();
                    q.pop();
                    if(current -> left && !visited[current -> left]){
                        q.push(current -> left);
                        visited[current -> left]= true;
                    }
                    if(current -> right && !visited[current -> right]){
                        q.push(current -> right);
                        visited[current -> right] = true;
                    }
                    if(mp[current] && !visited[mp[current]]){
                        q.push(mp[current]);
                        visited[mp[current]] = true;
                    }
                }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current -> val);
        }
        return result;


        
    }
};  

MINIMUM TIME TO BURN A BINARY TREE
class Solution {
  public:
  int burn_tree(Node*root, map<Node*,Node*>&node_to_parent ){
      map<Node* , bool> visited;
      queue<Node*> q;
      q.push(root);
      visited[root] = true;
      int ans = 0;
      while(!q.empty()){
          bool flag = 0;
          int sz = q.size();
          for(int i = 0; i<sz; i++){
                    Node* current  = q.front();
                    q.pop();
                    if(current -> left && !visited[current -> left]){
                        q.push(current -> left);
                        visited[current -> left]= true;
                        flag =1;
                    }
                    if(current -> right && !visited[current -> right]){
                        q.push(current -> right);
                        visited[current -> right] = true;
                         flag =1;
                    }
                    if(node_to_parent[current] && !visited[node_to_parent[current]]){
                        q.push(node_to_parent[current]);
                        visited[node_to_parent[current]] = true;
                         flag =1;
                    }
             } 
             if(flag){
                 ans++;
             }
          
      }
      return ans;
      
  }
  
  
  Node* create_parent_mapping(Node* root, int target, map<Node*,Node*>&node_to_parent){
      Node* res = NULL;
      queue<Node*> q;
      node_to_parent[root] = NULL;
      
      q.push(root);
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          if(front -> data == target){
              res = front;
          }
          if(front -> left){
              node_to_parent[front -> left] = front;
              q.push(front -> left);

          }
          if(front -> right){
              node_to_parent[front -> right] = front;
              q.push(front -> right);
          }
      }
      return res;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        // algo:
        // step 1 create a mapping to parent
        // step 2 find target node
        // step3 burn the tree in minimum time
        
        map<Node*, Node*> node_to_parent;
        Node* target_node = create_parent_mapping(root, target, node_to_parent);
        int ans = burn_tree(target_node, node_to_parent);
        return ans;
    }
};


CONSTRUCT A BINARY TREE FROM INORDER AND PREORDER
class Solution {
public:
    int find_position(vector<int> &in, int element, int n){
        for(int i = 0; i<n; i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int> &in, vector<int> &pre, int &index, int inorder_start, int inorder_end, int n){
        // base case
        if(index >= n || inorder_start > inorder_end) return NULL;
        int element = pre[index++];
        TreeNode*temp = new TreeNode(element);
        int position = find_position(in, element, n);

        // recursive calls;
        temp -> left = solve(in, pre, index, inorder_start, position-1, n);
        temp -> right = solve(in, pre, index, position+1, inorder_end, n);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;
        int n = preorder.size();
        TreeNode* ans = solve(inorder, preorder,preorderindex,0, n-1, n);
        return ans;
        
    }
};

SLIGHT OPTIMISATION IN THE ABOVE CODE USING MAP
class Solution {
public:
    void  create_mapping(vector<int> &in, map<int, int> &node_to_index, int n){
        for(int i = 0; i<n; i++){
            node_to_index[in[i]]=  i;
        }
    }
    TreeNode* solve(vector<int> &in, vector<int> &pre, int &index, int inorder_start, int inorder_end, int n, map<int,int> &node_to_index){
        // base case
        if(index >= n || inorder_start > inorder_end) return NULL;
        int element = pre[index++];
        TreeNode*temp = new TreeNode(element);
        int position = node_to_index[element];
     
        // recursive calls;
        temp -> left = solve(in, pre, index, inorder_start, position-1, n,node_to_index);
        temp -> right = solve(in, pre, index, position+1, inorder_end, n,node_to_index);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;
        int n = preorder.size();
        map<int, int> node_to_index;
        //create node to index map
        create_mapping(inorder, node_to_index, n);
        TreeNode* ans = solve(inorder, preorder,preorderindex,0, n-1, n,node_to_index);
        return ans;
        
    }
};


CONSTRUCT A BINARY TREE FROM INORDER AND POSTORDER
class Solution {
public:
    void  create_mapping(vector<int> &in, map<int, int> &node_to_index, int n){
        for(int i = 0; i<n; i++){
            node_to_index[in[i]]=  i;
        }
    }
    TreeNode* solve(vector<int> &in, vector<int> &post, int &index, int inorder_start, int inorder_end, int n, map<int,int> &node_to_index){
        // base case
        if(index < 0 || inorder_start > inorder_end) return NULL;
        int element = post[index--];
        TreeNode*temp = new TreeNode(element);
        int position = node_to_index[element];
     
        // recursive calls;
        temp -> right = solve(in, post, index, position+1, inorder_end, n,node_to_index);
        temp -> left = solve(in, post, index, inorder_start, position-1, n,node_to_index);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int postorderindex = n-1;
        map<int, int> node_to_index;
        //create node to index map
        create_mapping(inorder, node_to_index, n);
        TreeNode* ans = solve(inorder, postorder,postorderindex,0, n-1, n,node_to_index);
        return ans;
        
    }
};


SERIALISE AND DESERIALISE A BINARY TREE
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) s.append("#,");
            else{
                s.append(to_string(curr -> val) + ',');
            }
            if(curr != NULL){
                q.push(curr -> left);
                q.push(curr -> right);
            }

        }
       
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(s,str, ',');
            if(str == "#"){
                curr -> left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr -> left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str == "#"){
                curr -> right = NULL;

            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
        
    }
};

MORRIS TRAVERSAL FOR INORDER
vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL){
            inorder.push_back(curr -> val);
            curr = curr -> right;
        
        }
        else{
            TreeNode* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = pre -> right;
                

            }
            if(prev -> right == NULL){
                prev ->right = curr;
                curr = curr -> left;
            }
            else{
                prev -> right = NULL;
                inorder.push_back(curr -> val); 
                curr = curr -> right;
            }
        }
    }
    return inorder;
}


MORRIS TRAVERSAL FOR PREORDER
vector<int> getpreorder(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL){
            preorder.push_back(curr -> val);
            curr = curr -> right;
        
        }
        else{
            TreeNode* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = pre -> right;
                

            }
            if(prev -> right == NULL){
                prev ->right = curr;
                preorder.push_back(curr -> val);
                curr = curr -> left;
            }
            else{
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return preorder;
}


FLATTEN A BINARY TREE
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        while(temp != NULL){
             if(temp -> left){
                 TreeNode* pred = temp -> left;
                 while(pred -> right){
                     pred = pred -> right;
                 }
                 pred -> right = temp -> right;
                 temp -> right = temp -> left;
                 temp -> left = NULL;
             }
             temp = temp -> right;
             
        }
           /// left part ko nuLL
    }
};
 

 CEIL IN BINARY SEARCH TREE
 int findCeil(struct Node* root, int input) {
    // your code here
    int ceil = -1;
    while(root){
        if(root -> data == input){
            ceil = root -> data;
            return ceil;
        }
        else if(input > root -> data){
            root = root -> right;
        }
        else{
            ceil = root -> data;
            root = root -> left;
        }
    }
    return ceil;
}


FLOOR IN BINARY SEARCH TREE
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor = -1;
    while(root){
        if(root -> val == X){
            floor = root -> val;
            return floor;
        }
        else if(X > root -> val){
            floor = root -> val;
            root = root -> right;
        }
        else{
            
            root = root -> left;
        }
        
        
    }
    return floor;
}


INSERT IN A BINARY SEARCH TREE
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while(true){
            if(curr -> val <= val){
                if(curr -> right != NULL) curr = curr -> right;
                else{
                    curr -> right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr -> left != NULL) curr = curr -> left;
                else{
                    curr -> left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
        
    }
};


DELETE A NODE IN BINARY SEARCH TREE
class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(root -> left == NULL) return root -> right;
        if(root -> right == NULL) return root -> left;
        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLastRight(root -> left);
        lastRight -> right = rightChild;
        return root -> left;

    }
    TreeNode* findLastRight(TreeNode* root){
        if(root -> right == NULL) return root;
        return findLastRight(root -> right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) return helper(root);
        TreeNode* dummy = root;
        while(root != NULL){
            if(root -> val > key){
                if(root -> left != NULL && root -> left -> val == key){
                    root -> left = helper(root -> left);
                    break;
                }
                else{
                    root = root -> left;
                }
            }
            else{
                if(root -> right != NULL && root -> right -> val == key){
                    root -> right =  helper(root -> right);
                    break;
                }
                else{
                    root = root -> right;
                }
            }
        }
        return dummy;
        
    }
};

Kth SMALLEST IN A BINARY SEARCH TREE
class Solution {
public:
    vector<int> inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL)return arr;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
        return arr;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        return nums[k-1];
        
        
        
    }
};


VALIDATE A BINARY SEARCH TREE
class Solution {
public:
vector<int> vec;
    vector<int> inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            vec.push_back(root->val);
            inorder(root->right);
        }
        return vec;

   
}
    bool isValidBST(TreeNode* root) {
        inorder(root);
        bool ans = is_sorted(vec.begin(), vec.end());
        for(int i = 0; i<vec.size()-1; i++){
            if(vec[i] == vec[i+1]){
                ans = false;
            }
        }
        return ans;
        
        
    }
};


LOWERST COMMON ANCESSTOR IN BINARY SEARCH TREE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int curr = root -> val;
        if(curr < p -> val && curr < q -> val){
            return lowestCommonAncestor(root -> right, p, q);

        }
        if(curr > p -> val && curr > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        return root;
        
    }
};


CONSTRUCT A BINARY SEARCH TREE FROM PREORDER TRAVERSAL
class Solution {
public:
    TreeNode* build(vector<int>&pre, int &i, int bound){
        if(i == pre.size() || pre[i] > bound ) return NULL;
        TreeNode* root = new TreeNode(pre[i++]);
        root -> left = build(pre, i, root -> val);
        root -> right = build(pre, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
        
    }
};


INORDER SUCCESSOR IN A BINARY SEARCH TREE
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* successor = NULL;
        while(root != NULL){
            if(x -> data >= root -> data){
                root = root -> right;
            }
            else{
                successor = root;
                root = root -> left;
            }
        }
        return successor;
    }
}; 


BST ITERATOR
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
        
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp -> right);
        return temp -> val;
        
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
private:
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            root = root -> left;
        }
        //for(; root != NULL; st.push(root), root = root -> left);
    }
};


TWO SUM BINARY SEARCH TREE
class BSTIterator{
     stack<TreeNode*> st;
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
        
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse){
            pushAll(temp -> right);
        }
        else{
            pushAll(temp -> left);
        }
        return temp -> val;
        
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
private:
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(reverse == true){
                root = root -> right;
            }
            else{
                root = root -> left;
            }
        }
       
    }

};
class Solution {
    public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j  == k){
                return true;
            }
            else if(i + j < k){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        return false;
        
    }
};


RECOVER BINARY SEARCH TREE
class Solution {
    private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root -> left);
        if(prev != NULL && (root -> val < prev -> val)){
            // if this is first violation mark these two nodes as 'first' , 'middle' 
            if(first == NULL){
                first = prev;
                middle = root;

            }
            else{
                // if this is a second violation makrk this node as 'last'
                last = root;
            }
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
        
    }
};


LARGEST BST IN A BINARY TREE


class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this -> maxNode = maxNode;
        this -> minNode = minNode;
        this -> maxSize = maxSize;
        
    }
    
};
class Solution{
    public:
     
    NodeValue largestBSTSubtreeHelper(Node* root){
        // an empty tree is a BST of size 0
        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        // get value from left and rightsubtree of current tree
        auto left = largestBSTSubtreeHelper(root -> left);
        auto right = largestBSTSubtreeHelper(root -> right);
        
        // current node is greater than max in left and smaller than min in right, it is a BST
        if(left.maxNode < root -> data && root -> data < right.minNode){
            // it is a BST
            return NodeValue(min(root -> data, left.minNode), max(root -> data, right.maxNode), left.maxSize + right.maxSize + 1);
            
        }
        // otherwise , return [-inf, inf] so that parent can't be a valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    //You are required to complete this method 
    // Return the size of the largest sub-tree which is also a BST
    
    int largestBst(Node *root)
    {
    	//Your code here
    	 return largestBSTSubtreeHelper(root).maxSize;
    }
};





*/