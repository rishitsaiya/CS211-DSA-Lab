#include<bits/stdc++.h>
using namespace std;

ofstream fout("radix.txt"); //Output File pointer declared

int max(int arr[], int n) { //Function to extract the maximum element in the array
    int maximum = arr[0]; //Intial assumption for max element
    for (int i = 1; i < n; i++) //For loop to check all the elements
        if (arr[i] > maximum) //If the number is greater
            maximum = arr[i]; //Then replace the assumption with the latest max element
    return maximum; //Returning the max
}

void count_sort(int arr[], int n, int exp) { //Count Sort Implementation
    int out[n]; //Output array declaration 
    int i, count[10] = {0}; //Variable initial values,
  
    for (i = 0; i < n; i++) //For loop for counting number of occureneces
        count[ (arr[i]/exp)%10 ]++; //Storing in array
      
    for (i = 1; i < 10; i++) //For loop to change count[i] such that count[i] now contains actual position of this digit in out[]
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) { //For loop to build out array
        out[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; //Positioning in out array
        count[ (arr[i]/exp)%10 ]--; //Decreament
    }
   
    for (i = 0; i < n; i++) //Copy the out array to arr[], so that arr[] now contains sorted numbers according to current digit 
        arr[i] = out[i]; //Putting each element
}

void radix_sort(int arr[],int n){ //Function for Radix Sort 
    
    int m = max(arr, n); //Finding the max number to know no of digits
     
    for (int exp = 1; m/exp > 0; exp *= 10) //For loop to do counting sort for every digit
        count_sort(arr, n, exp);
    } //Instead of passing the digit number, we pass the exponent

void display(int arr[],int n){ //For loop to print array
	for(int i=0; i<n; i++){ //For loop to printing in fout
        if(i<n-1) 
		  fout<<arr[i]<<endl; 
        if(i==n-1) //For the last endl
          fout<<arr[i]; 
	}
}

int main(int argc, char** argv){
    ifstream fin(argv[1]); //Input file pointer declared
    
    vector <int> a; //Vector declared for taking in the input
    int value; //Integer for the value

    while(fin >> value) //Value inputs
        a.push_back(value); //Passing the value in vector
    
    int n = a.size(); //Input size declared

    int arr[n]; //Declaration of array for passing values of vector

   for(int i=0;i<n;i++) //For loop for passing the values
       arr[i]=a[i]; //Passing it to an array, because passing the vector would need a pointer and would lead complications. So we copy the values in an empty array

    radix_sort(arr, n); //Calling the Radix sort
    display(arr, n); //Calling the display function
    return 0; 
} //End of main