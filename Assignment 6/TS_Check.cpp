#include <bits/stdc++.h>

using namespace std;

int main(int agrc,char** argv){

	ifstream ifile;
	ifile.open(argv[1]);
	ifstream iofile;
	iofile.open(argv[2]);
	string c;
	vector <pair <int,int>> p;
	vector<int> k;
	int l=0;
	set<int> st;
	while(ifile >> c){
		int u = stoi(c);
		ifile >> c;
		int v = stoi(c);
		pair <int,int> m;
		m.first = u;
		m.second = v;
		p.push_back(m);
		st.insert(u);
		st.insert(v);
	}
	ifile.close();

	while(iofile >> c){
		int u = stoi(c);
		k.push_back(u);
	}
	iofile.close();

	for(int i=0;i<p.size();i++){
		int u = p[i].first;
		int v = p[i].second;
		int j;
		for (j=0;j<k.size();j++ ){
			if (k[j]==v){
				break;
			}
		}
		for (j-1;j<k.size();j++ ){
			if (k[j]==u){
				l=-1;
			}
		}
	}

	if(st.size()!=k.size()){
		l=-1;
	}

	if(l==0){
		cout << "Matched" << endl;
	}
	else{
		cout << "Not Matched" << endl;
	}	

	return 0;	
}