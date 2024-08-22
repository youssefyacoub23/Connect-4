#include <iostream>
#include <string>
using namespace std;

//Functions Declarations
void play();
void settings_CYC();
void settings();
void rules();
void credit();
int exit();

//Variables Declarations
int Player_turn = 1 , Row_check = 5 , Game_check = 0 , FT_check = 0 , P1WINS = 0, P2WINS = 0 , Play = 0 , FT_setting;
char play_board[6][8] , P1C , P2C , Check_Char;
string P1 , P2 , P;

//Function For The Main Menu
void MainMenu(){
	
	int option;
	
	cout << "Welcome To Connect 4!"<< endl;
	cout << "1) Play Now!"<< endl;
	cout << "2) How To Play"<< endl;
	cout << "3) Credits"<< endl;
	cout << "4) Exit"<< endl;
	
	cin >> option;
	
	if( option == 1 ){
		
		play();
		
	}
	
	else if( option == 2 ){
		
		rules();
		
	}
	
	else if( option == 3 ){
		
		credit();
		
	}
	
	else if( option == 4 ){
		
		exit();
		
	}
	
}

//Function To Print The Playing Board
void display(){
	
	int row , col , drop_num , design;
	
	for( drop_num = 0 ; drop_num <= 6 ; drop_num++ ){
		
		cout << "--" << drop_num + 1 << "--";
		
	}
	
	cout << endl;
	
	for( row = 0 ; row < 6 ; row++ ){
		
		for( col = 0 ; col < 7 ; col++ ){
		
			if( play_board[row][col] == 0 ){
			
				cout << "{ " << " " << " }";
				
			}
			
			else if( play_board[row][col] != 0 ){
			
				cout << "{ " << play_board[row][col] << " }";
				
			}
			
		}
		
		cout << endl;
		
	}
	
	for( design = 0 ; design <= 34 ; design++ ){
		
		cout << "=";
		
	}
	
	cout << endl;
	
}

//Function To Clear The Playing Board
void clear(){
	
	int rowc , colc;
	
	for( rowc = 0 ; rowc < 6 ; rowc++ ){
		
		for( colc = 0 ; colc < 7 ; colc++ ){
		
			play_board[rowc][colc] = 0;
	
		}
		
	}
	
}

//Function To Check If The Move Is Available
void CheckPlay(int x){
	
		if( Row_check >= 0 ){
			
			if( play_board[Row_check][x - 1] != 0 ){
				
				Row_check--;
				CheckPlay(x);
				
			}
			
			else if( play_board[Row_check][x - 1] == 0 ){
				
				if( Player_turn == 1 ){
				
					play_board[Row_check][x - 1] = P1C ;
				
				}
			
				else if( Player_turn == 2 ){
			
					play_board[Row_check][x - 1] = P2C ;
			
				}
				
				Row_check = 5;
				
			}
			
		}
		
		else if( Row_check < 0 ){
			
			cout << "Invalid Move..Try Again!" << endl;
			cout << '\a';
			
			Player_turn++;
			Row_check = 5;
			
		}
	
}

//Function To Check If Someone Won
void CheckWin(){
	
	int CountCell = 0 , row , col , rowt , colt;
	
	for( rowt = 0 ; rowt < 6 ; rowt++ ){
		
		for( colt = 0 ; colt < 7 ; colt++ ){
			
			if( play_board[rowt][colt] != 0 ){
				
				CountCell++;
				
			}
			
		}
		
	}
	
	if( CountCell != 42 ){
	
		for( row = 0 ; row < 6 ; row++ ){
		
			for( col = 0 ; col < 7 ; col++ ){
			
				if( play_board[row][col] == Check_Char && play_board[row][col-1] == Check_Char && play_board[row][col-2] == Check_Char && play_board[row][col-3] == Check_Char ){
			
					display();
				
					cout << P << " Won!" << endl;
					cout << '\a';
				
					Game_check = 1;
				
				}
			
				else if( play_board[row][col] == Check_Char && play_board[row-1][col] == Check_Char && play_board[row-2][col] == Check_Char && play_board[row-3][col] == Check_Char ){
				
					display();
				
					cout << P << " Won!" << endl;
					cout << '\a';

					Game_check = 1;
			
				}
			
				else if( play_board[row][col] == Check_Char && play_board[row-1][col-1] == Check_Char && play_board[row-2][col-2] == Check_Char && play_board[row-3][col-3] == Check_Char ){
				
					display();
				
					cout << P << " Won!" << endl;
					cout << '\a';
				
					Game_check = 1;
			
				}
			
				else if( play_board[row][col] == Check_Char && play_board[row-1][col+1] == Check_Char && play_board[row-2][col+2] == Check_Char && play_board[row-3][col+3] == Check_Char ){
			
					display();
				
					cout << P << " Won!" << endl;
					cout << '\a';

					Game_check = 1;
			
				}
			
			}
		
		}
	
	}
	
	else if( CountCell == 42 ){
		
		cout << "It's a Stalemate!" << endl;
		cout << '\a';
		
		clear();
		
	}
	
}

//Function To Check If Someone Reached The " First To " Target
void CheckFT(){
	
	if( P1WINS == FT_setting ){
		
		cout << P1 << " Won The Whole Game!";
		
		FT_check = 1;
		
	}
	
	else if( P2WINS == FT_setting ){
		
		cout << P1 << " Won The Whole Game!";
		
		FT_check = 1;
		
	}
	
	else if( P1WINS != FT_setting && P2WINS != FT_setting ){
		
		Game_check = 0;
		
	}
	
}

//Function With The Actual Game
void Game(){
	
			display();
	
			if ( Player_turn % 2 == 1 ){
			
				Player_turn = 1;
				P = P1;
				Check_Char = P1C;
			
			}
		
			else if ( Player_turn % 2 == 0 ){
			
				Player_turn = 2;
				P = P2;
				Check_Char = P2C;
			
			}
			
		
			while( Play < 1 || Play > 7 ){
		
				cout << P << " 's turn : ";
				cin >> Play;
				
				system ("cls");
				
				if( Play < 1 || Play > 7 ){
				
					cout << "Move Invalid..Try Again!" << endl;
					cout << '\a';
				
				}		

			}
		
			CheckPlay(Play);
		
			CheckWin();
		
			Player_turn++;
			Play = 0;
		
	
}

//Function For The Play Option
void play(){
	
	int option_GM ;
	
	FT_check = 0;
	
	//Taking The First Player's Name
	cout << "Enter Player One's name : ";
	cin.ignore();
	getline(cin , P1);
	
	//Taking The Second Player's Name
	cout << "Enter Player Two's name : ";
	getline(cin , P2);
	
	//Taking The First Player's Character
	cout << "Choose " << P1 <<"'s character : ";
	cin >> P1C;
	
	//Taking The First Player's Name
	cout << "Choose " << P2 <<"'s character : ";
	cin >> P2C;
	
	cout << "Choose a Gamemode :" << endl << "1) Quick Game!" << endl << "2) First to.." << endl;
	cin >> option_GM;
	

	if ( option_GM == 1 ){
		
		cout << P1 << " VS " << P2 << endl;
		
		while( Game_check == 0 ){
		
			Game();
		
		}
		
	}


	else if ( option_GM == 2 ){
		
		cout << "Set a number : ";
		cin >> FT_setting;
		
		cout << P1 << " VS " << P2 << endl;
		cout << "First to " << FT_setting << endl;
	
		while( FT_check == 0 ){
		
			while( Game_check == 0 ){
		
				Game();
		
			}
		
			if( Player_turn == 2 ){
				
				P1WINS++;
				cout << P1 << " " << P1WINS << "-" << P2WINS << " " << P2 << endl;
				
			}
			
			else if( Player_turn == 1 || Player_turn == 3 ){
				
				P2WINS++;
				cout << P1 << " " << P1WINS << "-" << P2WINS << " " << P2 << endl;
				
			}
			
			clear();
			
			CheckFT();
		
		}
	
	}
	
}

//Function For The Rules Option
void rules(){
	
	int option_rules;
	
	cout << "How to play Connect 4.."<< endl;
	cout << "- First, decide who goes first and what character each player will have."<< endl;
	cout << "- Players must alternate turns, and only one character can be placed in each turn."<< endl;
	cout << "- On your turn, place a character from the top into any of the seven slots."<< endl;
	cout << "- The game ends when there is a 4-in-a-row ( Upwards, horizontally or diagonally ) or a stalemate."<< endl;
	cout << "- The starter of the previous game goes second on the next game."<< endl;
	cout << "1) Back To Main Menu"<< endl;
	
	cin >> option_rules;
	
	if( option_rules == 1){
		
		MainMenu();	
		
	}
	
}

//Function For The Credit Option
void credit(){
	
	int option_credit;
	
	cout << "Game Programer--------Youssef Yacouba"<< endl;
	cout << "Game Designer--------Youssef Yacouba"<< endl;
	cout << "Sound Effects--------Youssef Yacouba"<< endl << endl;
	cout << "1) Back To Main Menu"<< endl;
	
	cin >> option_credit;
	
	if( option_credit == 1){
		
		MainMenu();	
		
	}
	
}

//Function For The Exit Option
int exit(){
	
	return 0;
	
}

