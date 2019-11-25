#include<bits/stdc++.h>
using namespace std;

ofstream fout1("mergesort.txt"); //Mergesort Output file declared
ofstream fout2("quicksort.txt"); //Quicksort Output file declared

int partition(int qsort[],int p, int r){ //Function for partition
    int pivot=qsort[r]; //Defining pivot
    int k=p-1; //
    for(int j=p;j<r;j++){ //For loop for internal sorts
        if(qsort[j]<= pivot){ //Condition for pivot in quick sort
            k++; 
            int temp=qsort[j]; //Swap statements
            qsort[j]=qsort[k]; //Swap statements
            qsort[k]=temp; //Swap statements
        }
    }
   int temp=qsort[k+1]; //Reassigning values
   qsort[k+1]=qsort[r];
   qsort[r]=temp; 

   return (k+1); //Return the index
}

void quick_sort(int qsort[],int p,int r){ //Quick Sort Algo
    if(p<r){ //If p is less than r
        int q=partition(qsort,p,r); //Using Partition function
        quick_sort(qsort,p,q-1); //Quick sort the sub array
        quick_sort(qsort,q+1,r); //Quick sort the sub array
    }
}

void merge(int msort[],int p,int q,int r){ //Merge Algo
    int size1 = q-p+1; //Size of sub array 1
    int size2 = r-q; //Size of sub array 2
  
    int L[size1]; //Left sub array with size defined
    int R[size2]; //Left sub array with size defined
  
    for (int i=0;i<size1;i++) //For loop left sub array
        L[i] = msort[p+i]; //Assigning the values in left sub array
    for (int j=0;j<size2;j++) //For loop right sub array
        R[j] = msort[q+1+j]; //Assigning the values in right sub array
  
    int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int b = p; // Initial index of merged subarray 
    while (size1>i && size2>j) { //If size1 is greater than i and size2 is greater than j
        if (L[i] <= R[j]) { //if the ith element of L is less than equal to jth element of R
            msort[b] = L[i]; //Putting ith element of L in sorted array
            i++; //Increament in i
        } 
        else{ 
            msort[b] = R[j]; //Putting jth element of R in sorted array
            j++; //Increament in j
        }
        b++; //Increament in b
    }
    while (i < size1){ //If i is less than size1
        msort[b] = L[i]; //Put it into msort array
        i++; //Increament in i
        b++; //Increament in b
    } 
    while (j < size2) { //If j is less than size2
        msort[b] = R[j]; //Put it into msort array
        j++; //Increament in j
        b++; //INcreament in b
    } 
}

void merge_sort(int msort[],int p,int r){ //Merge sort algo
    if(p<r){ //If pth index is less than rth index
        int q = (p+r)/2; //Going to middle index
        merge_sort(msort,p,q); //Recursively sorting the left sub array
        merge_sort(msort,q+1,r); //Recursively sorting the left sub array
        merge(msort,p,q,r); //Merge both sub arrays
    }
}

int main(int argc, char** argv){ //Main Function
    
    ifstream fin(argv[1]); //Input file pointer declared

    vector <int> input; //Vector declared for taking in the input
    int value; //Integer for the value

    while(fin>>value){ //Value inputs
        input.push_back(value); //Passing the value in vector
    }

    int size = input.size(); //Input size declared

    int qsort[size]; //Declaring Quick sorted array
    int msort[size+1]; //Declaring Merge sorted array

    for(int i=0;i<size;i++){ //For loop for passing the values
        qsort[i]=input[i]; //Putting the values in the quick sorted array intially
        msort[i+1]=input[i]; //Putting the values in the merge sorted array intially
    }

    quick_sort(qsort,0,size-1); //Calling Quick-Sort Funtcion
	for(int i=0; i<size; i++){ //For loop for displaying the values in quick sorted array
        if(i<size-1) //For all values except the last value
		  fout2<<qsort[i]<<endl; //Output in file
        if(i==size-1) //Forbidding the last space in the line
           fout2<<qsort[i]; //Output in file
	}

    merge_sort(msort,1,size); //Calling Merge-Sort Function
	for(int i=1; i<=size; i++){ //For loop for displaying the values in merge sorted array
        if(i<size) //For all values except the last value
		  fout1<<msort[i]<<endl; //Output in file
        if(i==size) //Forbidding the last space in the line
           fout1<<msort[i]; //Output in file
    }

return 0;
} //End of Main