#include <bits/stdc++.h> 
using namespace std;

ofstream fout ("anagram.txt");

string sortString(string str){ //Function to sort string
   sort(str.begin(), str.end());
   return str;
}

int hash_function(string s, int key){ //Function to hash according to given requirements
	int sum = 0;
		for(int k = 0 ; k < s.length(); k++){
			sum += s[k]; //Implicit type casting
		} 
		sum = sum % key; // Storing the value of last word 
return sum;
}

int main(int argc, char** argv) {

	ifstream fin1 (argv[1]); //argv[1]
	int key = stoi(argv[2]); //argv[2]
	ifstream fin2 (argv[3]); //argv[3]
	
	string s, a, b;
	
	list <string> ll [key]; //List for anagrams

	vector<long long int> sumArr_words; //vector to store words from words of argv[1]
	vector<long long int> sumArr_query; //vector to store words from words of argv[2]

	while(fin1 >> s){
		int result = hash_function(s, key); //Hashing
		ll[result].push_front(s); //Pushing it to the list
	}
	
	while(fin2 >> s){
		int result = hash_function(s, key);
		for(auto i : ll[result]){
			string str = i;
			a = sortString(str); b = sortString(s); //Process to check anagram
			if(a == b){ //Checking for anagram
				fout << str << " " ; 
			}
		}
		fout << endl;
	}
	return 0; 
}