#include<bits/stdc++.h>

using namespace std;

ofstream fout("bst.txt"); //Output file pointer declared

//-------------------------------------------------------------------------STRUCTURE DECLARATION------------------------------------------------
struct node{ //Declaration of Structure of Node
   int data; //For a value to be stored
   node* right=NULL; //Pointers for branches
   node* left=NULL;
   node* parent=NULL; //Pointer for parent
};
//-------------------------------------------------------------------------END OF STRUCTURE DECLARATION-----------------------------------------

//-------------------------------------------------------------------------SEARCH FUNCTION------------------------------------------------------
node* search (node* x , int number){ //Function to search input element 
    while(x!=NULL && x->data!=number){ //While the node pointer is not null and number not already existing
        if(x->data<number) //If the number is greater than data,
            x=x->right; //Put it in right branch
        else
            x=x->left; //Put in left branch
    }
    return x; //Return pointer
}
//-------------------------------------------------------------------------END OF SEARCH FUNCTION------------------------------------------------

//-------------------------------------------------------------------------MINIMUM FUNCTION------------------------------------------------------
node* minimum (node* x){ //Function to return the minimum number in its sub tree 	
    if(x==NULL) //If the node pointer is null
        return x; //Return to the same pointer
    while(x->left!=NULL){ //While the left sub branch is not NULL
            x=x->left; //Go till the end and return the last leftmost leaf
    }
    return x; //Return pointer
}
//-------------------------------------------------------------------------END OF SEARCH FUNCTION------------------------------------------------

//-------------------------------------------------------------------------MAXIMUM FUNCTION------------------------------------------------------
node* maximum (node* x){ //Function to return the maximum number in its sub tree 
    if(x==NULL) //If the node pointer is null
        return x; //Return to the same pointer
    while(x->right!=NULL){ //While the right sub branch is not NULL
            x=x->right; //Go till the end and return the last rightmost leaf
    }
    return x; //Return pointer
}
//-------------------------------------------------------------------------END OF MAXIMUM FUNCTION------------------------------------------------

//-------------------------------------------------------------------------SUCCESSOR FUNCTION-----------------------------------------------------
node* successor(node* x){ //Funtion to point to the next larger number
    if(x==NULL) //If the node pointer is null
        return x; //Return the same pointer
    if(x->right!=NULL) //If the node has right sub tree,
        return minimum(x->right); //Then return the minimum of right sub tree
    else{ 
        node *y = x->parent; // We go the parent node
        while(y!=NULL && y->right==x){ //If y is not null and y right is x only
            x=y; //Assign y to x
            y=y->parent; //Assign y parent pointer to y
        }
        return y; //Return updated pointer
    }
}
//-------------------------------------------------------------------------END OF SUCCESSOR FUNCTION----------------------------------------------

//-------------------------------------------------------------------------PREDECESSOR FUNCTION---------------------------------------------------
node* predecessor(node* x){ //Funtion to point to the previous smaller number
    if(x==NULL) //If the node pointer is null
        return x; //Return the same pointer
    if(x->left!=NULL) //If the node has left sub tree,
        return minimum(x->left); //Then return the minimum of left sub tree
    else{ 
        node *y = x->parent; // We go the parent node
        while(y!=NULL && y->left==x){ //If y is not null and y left is x only
            x=y; //Assign y to x
            y=y->parent; //Assign y parent pointer to y
        }
        return y; //Return updated pointer
    }
}
//-------------------------------------------------------------------------END OF PREDECESSOR FUNCTION--------------------------------------------

//-------------------------------------------------------------------------INORDER FUNCTION-------------------------------------------------------
void inorder(node* x){ //Function to print inorder traversal
    if(x!=NULL){ //If x is not null
        inorder(x->left); //Recursion in x left to get lower number
        fout<<x->data<<" "; //Print in the output file
        inorder(x->right); //Recursion in x left to get higher number
    }
}
//-------------------------------------------------------------------------END OF INORDER FUNCTION-----------------------------------------------

//-------------------------------------------------------------------------PREORDER FUNCTION-----------------------------------------------------
void preorder(node* x){ //Function to print preorder traversal
    if(x!=NULL){ //If x is null
        fout<<x->data<<" "; //Print in the output file
        preorder(x->left); //Recursion for completing the left sub branch
        preorder(x->right); //Recursion for completing the right sub branch
    }
}
//-------------------------------------------------------------------------END OF PREORDER FUNCTION------------------------------------------------------

//-------------------------------------------------------------------------POSTORDER FUNCTION------------------------------------------------------
void postorder(node* x){ //Function to print postorder traversal
    if(x!=NULL){ //If x is null
        postorder(x->left); //Recursion for completing the left sub branch
        postorder(x->right); //Recursion for completing the right sub branch
        fout<<x->data<<" "; //Print in the output file
    }
}
//-------------------------------------------------------------------------END OF POSTORDER FUNCTION------------------------------------------------------

//-------------------------------------------------------------------------TRANSPLANT FUNCTION------------------------------------------------------
void transplant(node *&x, node* p, node* q){ //Function to transplant where x is the root node, p is the node to be deleted and replaced by q node
    if(p->parent==NULL) //If p is NULL
        x=q; //Just replacing the pointer to q
    else if(p==(p->parent)->left) //p is in the left sub tree
        (p->parent)->left=q; //Replace the left sub tree element with q
    else
        (p->parent)->right=q; //Replace the right sub tree element with q
    if(q!=NULL) //If q is not NULL
        q->parent=p->parent; //assign p parent node pointer to q parent node pointer
}
//-------------------------------------------------------------------------END OF TRANSPLANT FUNCTION------------------------------------------------------

//==========================================================================================================================================================================================================

int main(int argc, char** argv){ 
    
    ifstream fin(argv[1]); //Input file pointer declared

    vector <string> input; //Vector declared 
    vector <int> value; //Vector declared 

    string buff; //Buffer String for dynamic string

//-----------------------------------------------------------------------------READING INPUT FILES------------------------------------------------------

    while(fin>>buff){ //String input given to input file pointer, Basically loop is just for reading the command
        input.push_back(buff); //buff pushed to input file

        if(buff=="insert"){ //If the read command is insert
            int temp; //Declaring a temporary variable
            fin>>temp; //Reading the number associated with it
            value.push_back(temp); //temp pushed to vector
        }
        else if(buff=="inorder"){ //If the read command is inorder
            value.push_back(0); //number pushed to vector 
        }
        else if(buff=="preorder"){ //If the read command is preorder
            value.push_back(0); //number pushed to vector 
        }
        else if(buff=="postorder"){ //If the read command is postorder
            value.push_back(0); //number pushed to vector 
        }
        else if(buff=="search"){ //If the read command is search
            int temp; //Declaring a temporary variable
            fin>>temp; //Reading the number associated with it
            value.push_back(temp);
        }
        else if(buff=="minimum"){ //If the read command is minimum
            value.push_back(0); //number pushed to vector 
        }
        else if(buff=="maximum"){ //If the read command is maximum
            value.push_back(0); //number pushed to vector 
        }
        else if(buff=="predecessor"){ //If the read command is predecessor
            int temp; //Declaring a temporary variable
            fin>>temp; //Reading the number associated with it
            value.push_back(temp);
        }
        else if(buff=="successor"){ //If the read command is successor
            int temp; //Declaring a temporary variable
            fin>>temp; //Reading the number associated with it
            value.push_back(temp);
        }
        else if(buff=="delete"){ //If the read command is delete
            int temp; //Declaring a temporary variable
            fin>>temp; //Reading the number associated with it
            value.push_back(temp);
        }
        else
        fout<<"Command not Recognised"<<endl; //Garbage Command      
    } //End of buff while loop

//----------------------------------------------------------------------------END OF READING INPUT FILES-------------------------------------------------

//---------------------------------------------------------------------------PERFORMING THE INPUT COMMANDS-----------------------------------------------

int inputsize=input.size(); //Declaring variable for c
node* root = NULL;

for (int i=0;i<inputsize;i++){ //For loop to perform input commands
    
    if (input[i]=="minimum"){ //If the input element is minimum
        node* x=minimum(root); //Assigning the data of structure after applying minimum function
        if(x==NULL) //If the node is NULL
            fout<<endl; //Just no print in output
        else
            fout<<x->data<<endl; //Printing the data in output
    } //End of Minimum if loop

    else if (input[i]=="maximum"){ //If the input element is maximum
        node* x=maximum(root); //Assigning the data of structure after applying maximum function
        if(x==NULL) //If the node is NULL
            fout<<endl; //Just no print in output
        else
            fout<<x->data<<endl; //Printing the data in output
    } //End of Maximum if loop

    else if (input[i]=="search"){ //If the input element is search along with a input number
        node* x=search(root,value[i]); //Assigning the data of structure after applying search function
        if(x==NULL) //If the node is NULL
            fout<<endl; //Just no print in output
        else
            fout<<x->data<<endl; //Printing the data in output
    } //End of search if loop

    else if (input[i]=="predecessor"){ //If the input element is predecessor
        node* x=search(root,value[i]); //Assigning the data of structure after applying search function
        if(x==NULL) //If the node is NULL
            fout<<value[i]<<" does not exist"<<endl; //Just print doesn't exist in output
        else{
            node* y=predecessor(x);
            if(y==NULL)
                fout<<"predecessor of "<<value[i]<<" does not exist"<<endl;
            else
                fout<<y->data<<endl; //Printing the data in output
        } 
    } //End of predecessor if loop

    else if (input[i]=="successor"){ //If the input element is predecessor
        node* x=search(root,value[i]); //Assigning the data of structure after applying search function
        if(x==NULL) //If the node is NULL
            fout<<value[i]<<" does not exist"<<endl; //Just print doesn't exist in output
        else{
            node* y=successor(x);
            if(y==NULL)
                fout<<"successor of "<<value[i]<<" does not exist"<<endl;
            else
                fout<<y->data<<endl; //Printing the data in output
        } 
    } //End of successor if loop

    else if(input[i]=="inorder"){ //If the input element is inorder
        inorder(root); //Passing the root node to inorder function
        fout<<endl; //Printing the data in output
    } //End of inorder if loop

    else if(input[i]=="preorder"){ //If the input element is preorder
        preorder(root); //Passing the root node to preorder function
        fout<<endl; //Printing the data in output
    } //End of preorder if loop

    else if(input[i]=="postorder"){ //If the input element is postorder
        postorder(root); //Passing the root node to postorder function
        fout<<endl; //Printing the data in output
    } //End of postorder if loop

    else if(input[i]=="insert"){ //If the input element is insert
        node *z=new node; //Declaring a new node
        z->data=value[i]; //Passing the value in z node data
        z->parent=NULL; //Checking if the z node is NULL
        z->left=NULL;
        z->right=NULL;

        node *y=NULL; //Keeping y node pointer to NULL
        node *x=root; //Assigning the pointer of x to root node

        while(x!=NULL){ //Data Insertion
        y=x; //Pointing x node to y node
            if(z->data < x->data) //If x data is greater than z data
                x=x->left; //Assigning x pointer to x left
            else 
                x=x->right; //Assigning x pointer to x right
        } //End of Data Insertion 

        z->parent=y; //Assigning z parent to y
   
        if(y==NULL) //Boundary case
        root=z; //We assign z node to root
        else if(z->data < y->data) //If value in z node is less than y node's value
        y->left=z; //Assign in y left
        else
        y->right=z; //Assign in y right

    fout<<value[i]<<" inserted"<<endl; //Printing the data in output
  } //End of insert if loop

    else if (input[i]=="delete"){  //If the input element is insert
        node *z=search(root,value[i]); //Checking if the number is existing already
        if(z==NULL) //If not existing
            fout<<value[i]<<" does not exist"<<endl; //Print it doesn't exist
        else{   
            if(z->left==NULL && z->right==NULL){ //If No leaf for z node
                if(z->parent==NULL) //If z parent is NULL
                    root=NULL; //Root node is NULL
                else if((z->parent)->left==z) //If z is the left leaf
                    (z->parent)->left=NULL; //Assign it NULL
                else //If z is the right leaf
                    (z->parent)->right=NULL; //Assign is NULL
    
                z->parent=NULL; //If not all above cases
                delete z; //Delete z
            }
        else if(z->left==NULL) //If z left node is NULL
            transplant(root,z,z->right); //Transplant under condition that root node given, z is to be deleted and repalced with z right
        else if(z->right==NULL) //If z right node is NULL
            transplant(root,z,z->left); //Transplant under condition that root node given, z is to be deleted and repalced with z left
        else{
            node *y=minimum(z->right); //Assigning y pointer to z right
                if(y->parent!=z){ //y parent is not z
                    transplant(root,y,y->right); //Transplant under condition that root node given, y is to be deleted and repalced with y right
                    y->right=z->right; //z right is assigned to y right
                    (y->right)->parent=y; //Assigning y right parent 
                    }
    
            transplant(root,z,y); //Transplant under condition that root node given, z is to be deleted and repalced with y
            y->left=z->left; //Assigning z left to y left
            (y->left)->parent=y; //Assigning y to y left parent
        }
        fout<<value[i]<<" deleted"<<endl; //Printing the data in output
        }   
    } //End of delete if loop

    else 
    fout<<"command not recognised"<<endl; //Garbage Command

} //End for command for loop

//---------------------------------------------------------------------------END OF PERFORMING THE INPUT COMMANDS-----------------------------------------------

return 0; 
} //End of main function