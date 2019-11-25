#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

ofstream fout("dijsktra.txt"); //Output file pointer declared
int arr[MAX][MAX]; //Adjcency matrix approach
int ans[MAX]; //Final array to store distances

set<int>vertex; //Set to remove duplications
int visited[MAX]; //Int visited for a vertex, 1 if yes otherwise initialised with 0
			//W  u
vector<pair<int,int>> completed; //In adjecency list, we are going through a particular row

void dijkstra(int arr[MAX][MAX], int source ){ //Dijkstra's Function
	completed.push_back(make_pair(0,source)); //Source distance setting to 0
	ans[source] = 0;
	while(completed.size() !=0){ 
		int weight = completed[0].first; //Since I wanted to sort the weights, I kept them first in the paor of the vector
		int u = completed[0].second; //Getting u
		completed.erase(completed.begin()); //Popping it out

		if(visited[u]) //If already visited
			continue; //Continue
		visited[u] = 1; //If not then, we change it to visited now
		
		for(int i=0;i<MAX;i++){ 
			if(i==u){ //Exploring all the links in that row
				for(int j=0;j<MAX;j++){
					if(arr[u][j] != -1){ //If the edge exists
						if(arr[u][j] + ans[u] < ans[j]){ //Relaxation
							ans[j] = arr[u][j] + ans[u]; 
							completed.push_back(make_pair(ans[j],j)); //Completed
						}
					}
				}
			}
		}
		sort(completed.begin(),completed.end()); //Taking the one with less weight
	}
}


int main(int argc, char** argv){ //Main function

	for(int i=0;i<MAX;i++) //Intialising the whole visited array to 0
		 visited[i] = 0;
	
	ifstream fin (argv[1]); //Input file pointer declared
	int source = atoi(argv[2]); //Source taken input from command line argument

	int x,y,z; //Integers declared for input from file

	for(int i = 0;i < MAX;i++){ //Initialising all to -1
		for(int j=0;j<MAX;j++){
			arr[i][j] = -1;
		}
	}

	for(int i=0;i<MAX;i++) //Initialising all the distances to infinity
		ans[i] = INT_MAX;

	while(fin >> x >> y >> z){
		arr[x][y] = z; //Taking the weight in
		vertex.insert(x); //Take in the source vertex
		vertex.insert(y); //Take in the destination vertex
	}

	dijkstra(arr, source); //Call dijkstra's function
	
	for(auto i = vertex.begin() ; i!=vertex.end() ;i++){
		if(ans[*i] == INT_MAX)
			fout  << *i << " " << -1 << endl; //Was getting INT_MAX as the distance, so changed the conditions accordingly
		else
			fout  << *i << " " << ans[*i] << endl;
	}
return 0;
} //End of main function