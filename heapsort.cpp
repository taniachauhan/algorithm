#include<iostream>
using namespace std;
 
int arr[], n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l &lt; n &amp;&amp; arr[l] &gt; arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r &lt; n &amp;&amp; arr[r] &gt; arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i &gt;= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i&gt;=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i&lt;n; ++i)
        cout &lt;&lt; arr[i] &lt;&lt; &quot; &quot;;
    cout &lt;&lt; &quot;\n&quot;;
}

 
// Driver program
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout &lt;&lt; &quot;Sorted array is \n&quot;;
    printArray(arr, n);
}
