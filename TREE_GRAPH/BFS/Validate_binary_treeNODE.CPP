#include<bits/stdc++.h>
using namespace std;
bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //every child have only one parent 
        //only one component//do bfs if node count not equal to n then return false
        //only one root
        /*   0
            /  \
            1   2 
                /
                3
        */
       /* n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
          0
         / \
        1   2
         \ /
          3
          3 have 1,2 parent not btree
       */
       map<int,int>childhaveparent;
       vector<int>adj[n];
       for(int i=0;i<n;i++){
        int node =i;
        int l=leftChild[i];
        int r=rightChild[i];
        if(l!=-1){
            adj[i].push_back(l);//creating adj list
            if(childhaveparent.find(l)==childhaveparent.end())
            childhaveparent[l]=i;
            else return false;

        }
        if(r!=-1){
            adj[i].push_back(r);
            if(childhaveparent.find(r)==childhaveparent.end())
           childhaveparent[r]=i;
           else
           return false;

        }
        // now if not have to parent then do bfs for tjhe component
        //now if we have more root 

       }
       int root =-1;
       for(int i=0;i<n;i++){
        if(childhaveparent.find(i)==childhaveparent.end()){
            if(root!=-1)return false;
            root=i;
        }

       }
       if(root==-1){
        return false;
       }
       bool visted[n]={false};
       queue<int>q;
       q.push(root);
       visted[root]=true;
       int c=0;
       //bfs isiliye agar koi 2 component ho aur kisi me ek k pass root haai ek k pass nahi tab ham ko checkr na padega
       //kitne hai node  agara number of node==n then tree other wise not
              while(!q.empty()){
        int node=q.front();
        q.pop();
        c++;
        for(auto it:adj[node]){
            if(visted[it]==false){
                visted[it]=true;
                q.push(it);
            }
        }

       }
       if(c==n)
       return true;
       return false;
      

       

    }
int main(){
    int n=4; 
    //           0  1 2  3
    vector<int>l{1,-1,3,-1};
    vector<int>r{2,-1,-1,-1};
    cout<<validateBinaryTreeNodes(n,l,r);
}