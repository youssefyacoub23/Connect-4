#include <iostream>
using namespace std;

void credit(){
	
	int option_credit;
	
	cout << "Game Programer--------Youssef Yacouba"<<endl;
	cout << "Game Designer--------Youssef Yacouba"<<endl;
	cout << "Sound Effects--------Youssef Yacouba"<<endl<<endl;
	cout << "1) Back To Main Menu";
	
	cin >> option_credit;
	
	if( option_credit == 1){
		
		MainMenu();	
		
	}

int exit(){
	
	return 0;
	
}

void MainMenu(){
	
	int option;
	
	//Main Menu
	cout << "Welcome To Connect 4!"<<endl;
	cout << "1) Play Now!"<<endl;
	cout << "2) Rules"<<endl;
	cout << "3) Settings"<<endl;
	cout << "4) Credits"<<endl;
	cout << "5) Exit"<<endl;
	
	cin>>option;
	
	if(option == 4 ){
		
		credit();
		
	}
	
	else if( option == 5 ){
		
		exit();
		
	}
	
}


	
}

int main(){
	
	MainMenu();
	
	return 0;
}
