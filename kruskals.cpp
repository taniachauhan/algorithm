#include <iostream>
#include <algorithm>
using namespace std;
class Edge{
public :
    int source;
    int destination;
    int weight;
};
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
int findParent(int i,int *parent)
{
    if(parent[i]==i)
    {
        return i;
    }
    else   
        return findParent(parent[i],parent);
}
void kruskals(Edge *input,int e,int n)
{
    sort(input,input+e,compare);
    int *parent=new int[n];
    Edge *output=new Edge[n-1];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count!=n-1)
    {
        Edge currentedge=input[i];
        int sourceParent=findParent(currentedge.source,parent);
        int destParent=findParent(currentedge.destination,parent);
        if(sourceParent!=destParent)
        {
            output[count]=currentedge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    cout<<endl<<endl;
    cout<<"Displaying the output of kruskal's algorithm "<<endl<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }
}
int main()
{   int e,n;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>e;
    Edge *input = new Edge[e];
    cout<<"Enter source: destination: weight"<<endl;
    for(int i=0;i<e;i++)
    {   int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].destination=d;
        input[i].weight=w;
    }
    kruskals(input,e,n);
    return 0;
}
