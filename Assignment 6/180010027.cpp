#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
 
map<int , int> ans;   	//VERTEX , DIST
bool Visited[MAX];


void BFS(map<int , vector<int>> mp , int temp){
		queue<int>q;
		q.push(temp);
		Visited[temp] = true;
		ans[temp] = 0;
		while(q.size() > 0){
			int t = q.front();
			q.pop();
			for(int i=0;i<mp[t].size();i++){
				if(!Visited[mp[t][i]]){
					q.push(mp[t][i]);
					Visited[mp[t][i]] = true;
					ans[mp[t][i]] = ans[t]+1;
				}
			}
		}
}



stack<int>s;

void topo(map<int , vector<int>> mp ,int temp){
	Visited[temp] = true;
	for(auto i = mp[temp].begin();i!=mp[temp].end();i++){
		if(!Visited[*i]){
			topo(mp , *i);
		}
	}

	s.push(temp);
}

void topoSort(map<int , vector<int>> mp){
	memset(Visited , false , sizeof(Visited));


	for(auto i = mp.begin();i!=mp.end();i++){
		if(! Visited[i->first]){
			topo(mp , i->first);
		}
	}

}


void show_topo(){
	ofstream fout;
	fout.open("ts.txt");
	while(s.size() > 0){
		fout << s.top() << endl;
		s.pop();
	}
	fout.close();
}



int main(int argc , char** argv){
	ifstream fin;
	fin.open(argv[1]);
	memset(Visited , false , sizeof(Visited));
	map<int , vector<int>> mp;
	set<int>ref;
	int a,b;
	int test = stoi(argv[2]);


	// for(int i =0;i<n;i++){
	// 	cin >>a >>b;
	// 	mp[a].emplace_back(b);
	// 	ref.insert(a);
	// 	ref.insert(b);
	// }


	ofstream f;
	f.open("sd.txt");
	while(fin >>a >> b){
			mp[a].emplace_back(b);
			ref.insert(a);
			ref.insert(b);
	}

	BFS(mp ,  test);
	
	for(auto i=ans.begin();i!=ans.end();i++){
		f << i->first << " " << i->second  << endl;
	}
	for(auto x = ref.begin();x!=ref.end();x++){
		if(!Visited[*x]){
			f << *x << " " << -1 << endl;
		}
	}
	f.close();

	topoSort(mp);
	show_topo();
	return 0;
}
