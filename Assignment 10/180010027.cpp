#include<bits/stdc++.h>
using namespace std;

tuple <int, int, int> ex_euclid(int a, int b){

	if(a == 0){
		return make_tuple(b, 0 ,1);
	}

	int gcd, x, y;

	tie(gcd, x, y) = ex_euclid(b%a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

int main(int argc, char** argv){

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

		tuple <int, int, int> t = ex_euclid (b,a);
		int gcd = get <0> (t);
		int x = get <1> (t);
		int y = get <2> (t);

	cout << gcd << " " << y << " " << x << endl;

	return 0;
}