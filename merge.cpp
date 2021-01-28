#include<iostream>
 using namespace std;
 int  count=0; /* to count the number of comparisions */

 int merge( int arr [ ], int l, int m, int r)
{
 int i=l; /* left subarray*/
 int j=m+1; /* right  subarray*/
 int k=l; /* temporary array*/
 int temp[r+1];
 while( i<=m && j<=r)
 {
   if ( arr[i]<= arr[j])
  {
    temp[k]=arr[i];
    i++;
  }
   else
  {
    temp[k]=arr[j];
    j++;
  }
    k++;
    count++;

  }
   while( i<=m)
  {
    temp[k]=arr[i];
    i++;
    k++;
  }
    while( j<=r)
  {
    temp[k]=arr[j];
    j++;
    k++;
  }
  for( int p=l; p<=r; p++)
  {
    arr[p]=temp[p];
  }
   return count;
  }


  int  mergesort( int arr[ ], int l, int r)
  {
    int comparisons;
    if(l<r)
  {
   int m= ( l+r)/2;
   mergesort(arr,l,m);
   mergesort(arr,m+1,r);
   comparisons = merge(arr,l,m,r);
  }
   return comparisons;
  }

 int main ()
 {
   int size;
   cout<<" Enter the size of an array "<< endl;
   cin>>size;
   int myarr[size];
   cout<<"  Enter the elements of array "<<endl;
   for ( int i=0; i< size; i++)
 {
   cin>>myarr[i];
 }
 cout<<"  Elements of array before sorting are  "<<endl;
 for ( int i=0; i< size; i++)
 {
   cout<<myarr[i]<<"  " ;
 }
  cout<<endl;
  int c=mergesort(myarr, 0, size-1);
  cout<<"  Elements of array after sorting are  "<<endl;
  for ( int i=0; i< size; i++)
 {
   cout<<myarr[i]<<"  " ;
 }
   cout<<endl;
   cout<<"  Number of comaprisions while sorting the given array"<< c <<endl;
   return 0;
 }
