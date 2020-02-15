#include<iostream>
using namespace std;
int main(){
	int x,n,k,cont;
	cin>>x>>k>>n;
	cont=1;
	while(k!=0){
		if(k%2==1){
			cont = (cont*x)%n;
		}
		x=(x*x)%n;
		k/=2;
	}
	cout<<cont;
	return 0;
}
