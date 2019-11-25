//Second Evaluation
#include<bits/stdc++.h>
using namespace std;

ofstream fout ("mst.txt");

class Edge{
public:
	int source;
	int destination;
	int weight;
};

bool compare (Edge a, Edge b){
	return a.weight < b.weight;
}

int search_parent(int v, int *parent){
	if(parent[v] == v)
		return v;
	return search_parent(parent[v], parent);
}

void kruskal(Edge *input, int n, int E){
	//Sorting the input array in ascending order
	sort (input, input + E, compare);

	Edge *output = new Edge[n-1];

	int *parent = new int[1000000]; //Parent array defined

	for(int i = 0; i < 1000000; i++){
		parent[i] = i;
	}

	int count = 0;
	int i = 0;
	while(count != n-1){
		Edge current = input[i];
		
		int source_p = search_parent(current.source, parent);
		int destination_p = search_parent(current.destination, parent);
	
		if(source_p != destination_p){ //Checking if current can be added to MST or not
			output[count] = current;
			count++;
			parent[source_p] = destination_p;
		}
		i++;
	}
	
	int r = 0; 
	while(r<n-1){
		fout << output[r].source << " " << output[r].destination << " " << output[r].weight << endl;
		r++;
	}
}

int main(int argc, char** argv){

	int n, E; //Here n is the number of distinct vertices & E is the number of edges
	ifstream fin (argv[1]); 
	int a, b, c; 
	int cv = 0;
	set <int> vertices; //To take out the duplications


	while(fin >> a >> b >> c){ //Taking input to find number of edges and number of vertices
		cv++;
		vertices.insert(a);
		vertices.insert(b);
	}
	n = vertices.size();
	E = cv;
	Edge *input = new Edge[E]; //Array of edges defined whose data type is Edge class
	fin.close();
	fin.open(argv[1]);

	for (int i = 0; i < E; i++){
		int s, d, w;
		fin >> s >> d >> w; //Inputs
		input[i].source = s; //Storing source
		input[i].destination = d; //Storing destination
		input[i].weight = w; //Storing weight
	}
	kruskal(input, n, E); 

	return 0;
}