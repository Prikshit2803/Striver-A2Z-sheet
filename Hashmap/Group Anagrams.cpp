//Anagrams : words with same letters but different irder of letters 

//sort the letter and store in map and this way all anagrams grouped

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         unordered_map<string,vector<string>> mp;
       for(auto str : strs){
           
           string a=str;
           
           sort(a.begin(),a.end());
           
        //    if(mp.find(a)!=mp.end())
        //    mp[a].push_back(str);
           
        //    else not needed
           mp[a].push_back(str);
       }
       
       vector<vector<string>> ans;
       for(auto p: mp){
           vector<string> temp;
           for(auto it : p.second){
               temp.push_back(it);
           }
           
           ans.push_back(temp);
       }
       
       return ans;
    }
