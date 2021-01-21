#include<iostream>
using namespace std;
int main()
 {
   int i,k,num,tempp,array[50],count=0;
   cout<<"Enter the number of elements:";
   cin>>num;
   cout<<"\nEnter the elements\n";
   for(i=0;i<num;i++)
      {
		cin>>array[i];
      }
	for(i=1;i<=num-1;i++)
      {
        tempp=array[i];
        k=i-1;
    while((tempp<array[k])&&(k>=0))
         {
          array[k+1]=array[k];  
          k=k-1;
         }
    count++;
    array[k+1]=tempp;
      }
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<num;i++)
      {
      cout<<array[i]<<" ";
      }
    cout<<"\nNo of comparisons: "<<count;
    return 0;
 }
