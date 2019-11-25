#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//-------------------------------------------------------CLASS STACK---------------------------------------------------------------

class stack{
	private:
		int *array; //Pointer to array
		int top; //Number of Elements Presently
		int maxsize; //Maximum Capacity

	public:
		stack(){ //Setting Standard Array
			array=NULL;
			top=0;
		}

		stack(int size){ //Making Array of size req
		top=0;
		maxsize = size;
		array = new int[maxsize]; //Array pointing to it
		}

		~stack(){ // I haven't Implenented
		delete [] array;
		}

		bool push(int newnum){ //Returns if operation is performed
		if (top==maxsize) //Because the element is being added, Top=Maxsize+1
			return false;
		array[top]=newnum; //Assigning the new element at the top
		top++; //Increament the top
		return true;
		}

		int pop(){ //Returns -1 if operation is not performed, returns pop if operaion is successful
		if(top==0) //Stack is empty, Underflow will happen
			return -1;
		top--; //Decreament the top
		return array[top]; //Note array indexing
		}

		bool search(int target){ //Search for target in array
		for(int i=0; i<top; i++){
			if(target==array[i])
				return true;
		}
		return false;
		}

		void display(ofstream& fout){ //Try out once more
		for(int i=top-1;i>-1;i--)
			fout<<array[i]<<" ";
		fout<<endl;
		}

}; // End of Class Stack

//-----------------------------------------------END OF CLASS STACK--------------------------------------------------------------------------------

//---------------------------------------------------CLASS QUEUE-------------------------------------------------------------------------------------

class queue{
private:
	int* array;	//Pointer to the array
	int maxsize; //Maximum Capacity
	int head; //Lim of oldest element
	int tail; //Lim of latest element

public:
	queue(){ //Setting Standard Array
		head=0;
		tail=0;
		array=NULL;
	}

	queue(int size){ //Making Array of size req
		head=0;
		tail=0;
		maxsize = size;
		array = new int[maxsize+1]; //Circular Array idea, Array pointing to it
	}

	~queue(){
		delete[] array;
	}
	
	bool enqueue(int newnum){ //Enqueue from tail, because tail is the latest element, We leave one extra space between head and tail
		int n = maxsize+1; //Overflow Condition
		if( (tail+1)%n == head ) //Wrapping it in cirlce
			return false; //Overflow

		array[tail]=newnum; //Assigning new element
		tail = (tail+1)%n; //Wrapping it in cirlce
		return true;
	}

	int dequeue(){ //Dequeue from head
		if(head==tail)
			return -1; //Returns -1 if Underflow
		int n = maxsize+1; //Increament for extra space
		int ele=array[head]; //Removal
		head= (head+1)%n;
		
		if(tail==head){ //Reassigning Standard array if head=tail
			head=0;
			tail=0;
		}
		return ele;
	}

	bool search(int target){ //Returns if operation is performed
		int i=head;
		while(i!=tail){ //Returing only true cases
			if(array[i]==target)
				return true;
			i=(i+1)%(maxsize+1);
		}
		return false;
	}

	void display(ofstream& fout){
		int i=head;
		while(i!=tail){
			fout<<array[i]<<" ";
			i=(i+1)%(maxsize+1);
		}
		fout<<endl;
	}
};

//-----------------------------------------------END OF CLASS QUEUE--------------------------------------------------------------------------------

//----------------------------------------------------CLASS NODE--------------------------------------------------------------------------------
class node{
public:
	int data;
	node* next;
	node* prev;
	//default
	node(){
		data=-1;
		next=NULL;
		prev=NULL;
	}
};
//-----------------------------------------------END OF CLASS NODE--------------------------------------------------------------------------------

//----------------------------------------------------CLASS dll--------------------------------------------------------------------------------
class dll{
private:
	node* head;
public:
	dll(){
		head=NULL;
	}

	~dll(){
		node* p=head->next;
		while(p!=NULL){
			node* q=p->prev;
			delete q;
			p=p->next;
		}	
	}
	node* getHead(){
		return head;
	}
	//insert, remove, search, display
	void insert(int num){
		
		if(head==NULL){
			head= new node;
			head->data=num;
		}

		else{
			node* p=head;
			head=new node;
			head->data=num;
			head->prev=NULL;
			head->next=p;
			p->prev=head;
		}

	}

	bool search(int num){
		node* p=head;
		while(p!=NULL){
			if(p->data==num)
				return true;
			p=p->next;
		}
		return false;
	}

	bool del(int num){
		node* p=head;
		if(p==NULL) return false;
		while(p!=NULL){
			if(p->data==num){
				if(p->prev==NULL)
					head=p->next;
				if(p->prev!=NULL)
					p->prev->next=p->next;
				if(p->next!=NULL)
					p->next->prev=p->prev;

				delete p;
				return true;
			}
			p=p->next;
		}
		return false;	

	}

	void display(ofstream& fout){
		node* p= head;
		while(p){
			fout<<p->data<<" ";
			p=p->next;
		}
		fout<<endl;
	}

};
//-----------------------------------------------END OF CLASS dll--------------------------------------------------------------------------------


int main(int argc, char *argv[]){
	ifstream fin(argv[1]);
	ofstream task1("stack.txt"),task2("queue.txt"),task3("dll.txt");
			
	int k=atoi(argv[2]);; //Scanning the number given in the command line
	stack objs(k);
	queue objq(k);
	dll objd;

	int n; //For array, be it a stack/dll/queue
	char c; //Character Definition for Scanning from file

	while(fin>>c){ //Scanning the character

		if(c == '+' || c == '-' || c == '?') //If it is either one of them, we input the integer
		fin >> n;
		
		if(c=='+'){ //Where c = '+'
			
			bool flag1; //Declaration of flag

			flag1=objs.push(n); //Push object into array (Stacks)
			if(flag1) 	task1<<"pushed "<<n<<endl; //If true, we show the given statement
			else		task1<<"overflow"<<endl; //Else we show overflow

			flag1=objq.enqueue(n); //Push object into array (Queue)
			if(flag1)	task2<<"enqueued "<<n<<endl; //If true, we show the given statement
			else		task2<<"overflow"<<endl; //Else we show overflow

			objd.insert(n); //Push object into array (DLL)
			task3<<"inserted "<<n<<endl; //If true, we show the given statement
			} //End of '+' if loop  
		
			if(c=='-'){ //Where c = '-'
			
			int key; //Declaration of key
			
			key=objs.pop(); //Push object into array (Stacks)
			if(key!=-1)	task1<<"popped "<<key<<endl;//If true, we show the given statement
			else		task1<<"underflow"<<endl;//Else we show underflow

			key=objq.dequeue(); //Push object into array (Queue)
			if(key!=-1)	task2<<"dequeued "<<key<<endl;//If true, we show the given statement
			else		task2<<"underflow"<<endl;//Else we show underflow

			bool f=objd.del(n); //Push object into array (DLL)
			if(f)		task3<<"deleted "<<n<<endl;//If true, we show the given statement
			else		task3<<"cannot delete "<<n<<endl;

			}//End of '-' if loop  
		
			if(c=='?'){ //Where c = '?'

			if(objs.search(n)) task1<<  "found "	<< n <<endl;
			else task1<< "not found "<< n <<endl;

			if(objq.search(n)) task2<<  "found "	<< n <<endl;
			else task2<< "not found "<< n <<endl;

			if(objd.search(n)) task3<<  "found "	<< n <<endl;
			else task3<< "not found "<< n <<endl;
			
			}//End of '?' if loop  
		
			if(c=='!'){ //Where c = '!'
			objs.display(task1);
			
			objq.display(task2);

			objd.display(task3);
			} //End of '!' if loop
		
		} //End of while c loop
		
	fin.close();
	task1.close();
	task2.close();
	task3.close();
		
return 0;
} //End of Main
