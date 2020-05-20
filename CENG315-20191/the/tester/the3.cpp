#include "the3.h"

#define MAX_N 1005

// You  can define extra functions here



// INPUT :
//            n         : number of nodes in the graph
//            edgeList  : edges in the graph
//            scores    : importance scores
// return value : 
//                 number of disconnected components
long long int min(long long int a, long long int b)
   {
      return a > b ? b : a;
   }
void dfs(int ind, int c, int n, std::vector<std::vector<int> > &adj, std::vector<int>& color)
   {
      color[ind] = c;
      for (auto i = adj[ind].begin(); i < adj[ind].end(); i++)
      {
         if (color[*i] == 0)
         {
            dfs(*i, c, n, adj, color);
         }
      }
      return;
   }

double score(int s, int t, int v, std::vector<std::vector<long long int> > &p)
   {
      if(v == s || v == t)
         return 0.0;
      if(p[s][t] >= INT_MAX || p[s][v] >= INT_MAX)
         return 0.0;
      double x = (s == t ? 1.0 : (double)p[s][t]);
      double y = (double)p[s][v] + (double)p[v][t];
      return x/y;
   }

int Important (int n, int**& edgeList, double*& scores)
{ 
   std::vector<std::vector<long long int> > p;
   std::vector<std::vector<int> > adjList;
   p.resize(n);
   adjList.resize(n);
   for (int i = 0; i < n; i++)
   {
      p[i].resize(n);
      adjList[i].resize(n);
   }
   
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         p[i][j] = edgeList[i][j] != 0 ? edgeList[i][j] : INT_MAX;
         if(i == j)
            p[i][j] = 1;
         if (edgeList[i][j] > 0 && i > j)
         {
            adjList[i].push_back(j);
            adjList[j].push_back(i);
         }
         
      }
   }
   for (int k = 0; k < n; k++)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
         }
      }
   }
   std::cout<<"-----"<<std::endl;
   for(int i = 0; i<n; i++)
   {
      for(int j = 0; j<n; j++)
         std::cout<<(p[i][j] < INT_MAX ? p[i][j] : 0)<<" ";
      std::cout<<std::endl;
   }
   std::vector<int> color;
   color.resize(n);
   int c = 0;
   for (int i = 0; i < n; i++)
   {
      if (color[i] > 0)
      {
         continue;
      }
      ++c;
      dfs(i, c, n, adjList, color);
   }
   for (int i = 0; i < n; i++)
   {
      double s = 0.0;
      for (int j = 0; j < n; j++)
      {
         for (int k = 0; k < n; k++)
         {
            s+=score(j,k,i,p);
         }
      }
      scores[i] = s;
   }
   return c; 
}
/*
int main()
   {
      size_t n;
      int **edgeList;
      double *scores;
      std::cin>>n;
      edgeList = new int*[n];
      for (size_t i = 0; i < n; i++)
      {
         edgeList[i] = new int[n];
      }
      scores = new double[n];
      for (size_t i = 0; i < n; i++)
      {
         for (size_t j = 0; j < n; j++)
         {
            std::cin>>edgeList[i][j];
         }
      }
      int ret = Important(n, edgeList, scores);
      std::cout<<"Ret = "<<ret<<std::endl;
      for (int i = 0; i < n; i++)
      {
         std::cout<<scores[i]<<" ";
      }
      std::cout<<std::endl;
      delete[] scores;
      for (size_t i = 0; i < n; i++)
      {
         delete[] edgeList[i];
      }
      
   }*/