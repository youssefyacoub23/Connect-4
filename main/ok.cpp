#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	int x; 
	int y;
	int sum;
	cout<<"hi,insert the first number "<<endl;
	cin>>x;
	cout<<"sry for being a dickhead ,insert the second number"<<endl;
	cin>>y;
	if( x>0 && y>0 ){
		sum=x+y;
		cout<<sum;
	}
	else if(x<0 && y<0) 
	{
		sum=x*y;
		cout<<sum;
	}
	else{
		cout<<"go fuck your self"<<endl;
	}
	return 0;
}
