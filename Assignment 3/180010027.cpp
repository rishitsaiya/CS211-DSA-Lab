#include<bits/stdc++.h>
using namespace std;

ofstream fout("heap.txt"); //Declaration of output file pointer

    int parent(int i, int size){ //Function to find the parent
        if(i%2==0) //If even,
            return (i/2-1);
        else //If odd,
            return (i/2);
    }

    int left(int i, int size){ //To get the left child
        if(size-1>=((2*i)+1)) //If the element index is less than total length
            return ((2*i)+1);
        else
            return -1;
    }

    int right(int i,int size){ //To get the left child
        if(size-1>=((2*i)+2)) //If the element index is less than total length
            return ((2*i)+2);
        else
            return -1;
    }

    void max_heapify(int queue[],int size,int i){ //Function to max-heapify
        int left_child=left(i,size); //Left child
        int right_child=right(i,size); //Right child
        int largest = i; 
        if(left_child!=-1 && (queue[left_child]>queue[i])) //If left child is greater than parent
            largest=left_child; //Replace
        else
            largest=i; //Remains
        if(right_child != -1 && (queue[right_child] > queue[largest])) //If left child is greater than parent
            largest = right_child; //Replace
        if(largest!=i){ //If i is not the largest, swap function
            int temp=queue[i]; 
            queue[i]=queue[largest];
            queue[largest]=temp;
            max_heapify(queue,size,largest);
        }    
    }

    void sort(int queue[], int size){ //Function to sort
        for(int i=size-1;i>=1;i--){ //Starting from the last node
            int temp = queue[0]; //Storing it dynamically for operation
            queue[0] = queue[size-1];
            queue[size-1] = temp;
            size--;
            max_heapify(queue,size,0); //Using Max-Heapify
        }
    }

    int maximum(int queue[], int size){ //Function to get maximum
        return queue[0];
    }

    int heap_extract_max(int queue[], int &size){ //Function to find maximum when a heap is given unsorted
    	if(size<1)
			return -1;
		int max = queue[0];
		queue[0]=queue[size-1];
		size--;
		max_heapify(queue,size,0);
		return max;
    }
    
    void heap_increase_key(int queue[], int size, int i, int key){ //Function to replace the given key with our input if the key is less than our input
        queue[i] = key;
        while(i>0 && queue[i]>queue[parent(i,size)]){
            int temp = queue[i];
            queue[i] = queue[parent(i,size)];
            queue[parent(i,size)] = temp;
            i = parent(i,size);
        }
    }    

    void max_heap_insert(int queue[], int &size, int key){ //Just inserting the key keeping the heap conditions same
        size++;
        queue[size-1] = key;
        heap_increase_key(queue,size,size-1,key); 
    }

//------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------
int main(int argc, char** argv){
    
    ifstream fin(argv[1]); //Input file name extracting from Command Line Argument

    vector <string> input; //Vector for commands declared 
    vector <int> value; //Vector for numbers declared 
    vector <int> index; //Vector for index declared
    string buff; //Buffer String for dynamic string

    while(fin>>buff){ //While loop for buff string
        input.push_back(buff);

        if(buff=="insert"){ //If the string is insert
            int temp; 
            fin>>temp;
            value.push_back(temp);
            index.push_back(0); //Set other inputs to zero
        }

        else if(buff=="maximum"){ //If the string is maximum
            value.push_back(0); //Set other inputs to zero
            index.push_back(0); //Set other inputs to zero
        }

        else if(buff=="extract-max"){ //If the string is extract-max
            value.push_back(0); //Set other inputs to zero
            index.push_back(0); //Set other inputs to zero
        }

        else if(buff=="increase-key"){ //If the string is increase-key
            int temp;
            fin>>temp;
            index.push_back(temp);
            fin>>temp;
            value.push_back(temp);
        }

        else if(buff=="sort"){ //If the string is sort
            value.push_back(0); //Set other inputs to zero
            index.push_back(0); //Set other inputs to zero
        }

        else
            fout<<"Command not recognised."<<endl;
    
    } //End of buff while loop
//------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------
    int inputsize=input.size(); //Declaring variable for c
    int queue[inputsize+1]; //Implementing queue as array 
    int size=0; //Intial Declaration for Queue Length

    for(int i=0;i<inputsize;i++){ //Functions for respective inputs
        
        if(input[i]=="insert"){ 
            max_heap_insert(queue,size,value[i]);
            fout<<value[i]<<" inserted"<<endl;
        }

        else if(input[i]=="maximum"){
            if(size<1)
                fout<<endl;
            else
                fout<<maximum(queue,size)<<endl;
        }

        else if(input[i]=="extract-max"){
            if(size<1)
                fout<<endl;
            else
                fout<<heap_extract_max(queue,size)<<endl;
        }

        else if(input[i]=="increase-key"){
            if(size<1)
                fout<<endl;
            else if(queue[index[i]]>value[i])
                fout<<value[i]<<" is less than the current key at "<<index[i]<<endl;
            else{
                heap_increase_key(queue,size,index[i],value[i]);
	            fout<<"Key at "<<index[i]<<" changed to "<<value[i]<<endl;
            }
        }

        else if(input[i]=="sort"){
            if(size<1)
                fout<<endl;
            else{
                int temp_queue[size];
                for(int k=0;k<size;k++)
                    temp_queue[k]=queue[k];
                sort(temp_queue,size);
                for(int k=0;k<size;k++){
                    if(k<=size-2)
                    fout<<temp_queue[k]<<" ";
                    else if(k==size-1)
                    fout<<temp_queue[k];
                }
                fout<<endl;
            }
        }
    
    } //End of command for loop

//------------------------------------------------------------------------------------------------------------------------

    return 0;
} //End of main
