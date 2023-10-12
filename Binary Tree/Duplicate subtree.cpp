//same leaf node doesnt mean duplicate subtree

//link: https://www.youtube.com/watch?v=_j7yb_nWFO8&t=603s

//Generate strings and stroe onto a map
//if mp[s] >2 it means duplicate
string stringGen(Node* node,unordered_map<string,int> &mp){
        if(node->left==NULL && node->right==NULL)
        return to_string(node->data);
        
        string s=to_string(node->data);
        if(node->left){
            s+=stringGen(node->left,mp);
        }
        
        else if(!node->left)
        s+="$";
        
        
        if(node->right){
            s+=stringGen(node->right,mp);
        }
        
        else if(!node->right)
        s+="$";
        
        mp[s]++;
        
        return s;
    }
    int dupSub(Node *root) {
        
      unordered_map<string,int> mp; 
      
      stringGen(root,mp);
      
      for(auto it : mp){
          if(it.second>1)
          return 1;
      }
      
      return 0;
    }
