#include <iostream>
using namespace std;
int findMinVertex(int *weight,bool *visited ,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&(minVertex==-1 || weight[i]<weight[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int **edges,int n)
{
    int *parent=new int[n];
    int *weight=new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        weight[i]=1000;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n;i++)
    {
        int minVertex=findMinVertex(weight,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0 && !visited[j])
            {
                if(edges[minVertex][j]<weight[j])
                {
                    weight[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
   for(int i=1;i<n;i++)
   {   if(parent[i]<i)
   {
       cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
   }
   else
   {
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl; 
   }
       
   }
}
int main()
{
    int n,e;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    int *edges=new int[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    cout<<"Enter source : destination: weight: "<<endl;
    for(int k=0;k<e;k++)
    {
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    cout<<endl;
    prims(edges,n);
    return 0;
}
