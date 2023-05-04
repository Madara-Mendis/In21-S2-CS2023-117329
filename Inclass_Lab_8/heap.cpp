#include <iostream>
#include <limits>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;  //assigning root as the largest value
   int left = 2*root + 1;  //Index of left child node
   int right = 2*root + 2;  //Index of right child node

   //If left node is larger than the root,update the index of the largest value as left
   if (left<n && arr[left]>arr[largest]){
        largest = left;
   }

   //If right node is larger than largest so far,update the index of the largest value as right
   if (right<n && arr[right]>arr[largest]){
        largest = right;
   }

   //If largest is not the root,exchange the current largest value and the root
   if (largest != root) {
        swap(arr[root], arr[largest]);

        //Recursively call heapify
        heapify(arr, n, largest);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=n/2-1; i>=0; i--){//calling heapify from bottom to top
        heapify(arr, n, i);
   }


   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--) {
        //exchanging current root with the end
        swap(arr[0], arr[i]);

        //call max heapify
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int n;
   cout << "Enter the size of the array: ";//taking the size of the arry as user input
   cin >> n;
   int heap_arr[n];
   cout << "Enter " << n << " elements of the array: ";//taking elements of the array from user
   for (int i = 0; i < n; i++) {
        if (!(cin >> heap_arr[i])) {//if user inputs non integer values display an error
            cout << "Error: Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
        }
   }
   if (cin.get() != '\n') {//if user inputs elements exceeding the size he mentioned display an error
        cout << "Error: Too many elements entered. Only the first " << n << " elements will be used." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
