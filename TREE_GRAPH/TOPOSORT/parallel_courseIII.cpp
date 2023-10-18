#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/parallel-courses-iii/
int minimumTime(int n, vector<vector<int>>relations, vector<int>time) {
        vector<int>adj[n];
        vector<int>in_degree(n,0);
        for(int i=0;i<relations.size();i++){
            //zero based indexing
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adj[u].push_back(v);
            //storing indegree for the topological sort
            in_degree[v]++;
        }
        //now we will do the toposort where in degree is zero
         vector<int>maxtime(n,0);
         queue<int>q;
     //    cout<<"zero\n";
         for(int i=0;i<n;i++){
            if(in_degree[i]==0){
              //  cout<<i+1<<" ";
                q.push(i);
                maxtime[i]=time[i];
            }
         }
         while (!q.empty())
         {
            /* code */
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                maxtime[v]=max(maxtime[v],maxtime[u]+time[v]);
               in_degree[v]--;
               if(in_degree[v]==0){
                q.push(v);
               }
            }
         }
        //  cout<<"\n";
        //  for(auto it:maxtime){
        //     cout<<it<<" ";
        //  }
         return *max_element(begin(maxtime),end(maxtime));
         


    }
int main(){
    
    cout<<minimumTime(5,{{1,5},{2,5},{3,5},{3,4},{4,5}},{1,2,3,4,5});
}