#include "tic_funs.h"

using namespace std;

int main(){
	bool another_play = 1;
	int score_p1, score_p2 = 0;
	int N_MAX_MOVES = 9;

	while(another_play){
		enum player{p1 = 0, p2 = 1};
		// win
		int win; 
		// table initialization
		vector< vector<int> > table = init_table();
		// available moves init
		int av_moves[9] = {0};
		// players' current move
		int p1_move, p2_move;
		// initial game table
		cout << "Score: " << endl;
		cout << "P1: " << score_p1 << endl;
		cout << "P2: " << score_p2 << endl; 
		cout << endl;
		disp_table(table);
		// number of moves played
		int tot_moves = 0;
		while(true){
			// ---------------- P1 MOVE -------------------------
			P1:
			cout << "P1 move: ";
			cin >> p1_move;
			// check if move is valid
			if(check_move(p1_move, av_moves)){
				// mark move as done
				av_moves[p1_move] = 1;
				tot_moves ++;
				// update game table
				update_table(table, p1_move, p1);
				// check win : 0: no win, 1: p1 wins, 2: p2 wins
				win = check_win(table);
				if(win == 0 && tot_moves == N_MAX_MOVES){
					cout << "Tie game!";
					break;
				}
					
			}
			else{
				cout << "Move is not valid!" << endl;
				goto P1;
			}
			disp_table(table);
			if(win == 1){
				cout << "--- P1 WINS! ---" << endl;
				score_p1++;
				break;
			}
			// ---------------- P2 MOVE -------------------------
			P2:
			cout << "P2 move: ";
			cin >> p2_move;
			// check if move is valid
			if(check_move(p2_move, av_moves)){
				// mark move as done
				av_moves[p2_move] = 1;
				tot_moves ++;
				// update game table
				update_table(table, p2_move, p2);
				// check win : 0: no win, 1: p1 wins, 2: p2 wins
				win = check_win(table);
				if(win == 0 && tot_moves == N_MAX_MOVES){
					cout << "Tie game!";
					break;
				}				
			}
			else{
				cout << "Move is not valid!" << endl;
				goto P2;
			}
			disp_table(table);
			if(win == 2){
				cout << "--- P2 WINS! ---" << endl;
				score_p2++;
				break;
			}		
		}
		cout << endl;
		cout << "Score: " << endl;
		cout << "P1: " << score_p1 << endl;
		cout << "P2: " << score_p2 << endl; 
		cout << endl;
		cout << "Another game?" << endl;
		cout << "1: YES" << endl << "0: NO" << endl;
		cin >> another_play;
	}
	return 0;
}