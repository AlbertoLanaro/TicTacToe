#include "tic_funs.h"

using namespace std;

const int n_rows = 3;
const int n_cols = 3;

std::vector<std::vector<int> > init_table(){
	std::vector<std::vector<int> > table;
	table.resize(n_rows,std::vector<int>(n_cols));

	for(int i=0; i<n_rows;i++)
		for(int j=0; j<n_cols;j++)
			table[i][j] = 0;

	return table;
}

std::pair<int,int> map_move(int n){
	switch(n){
		case 0:
			return std::make_pair(0,0);
			break;
		case 1:
			return std::make_pair(0,1);
			break;
		case 2:
			return std::make_pair(0,2);
			break;
		case 3:
			return std::make_pair(1,0);
			break;
		case 4:
			return std::make_pair(1,1);
			break;
		case 5:
			return std::make_pair(1,2);
			break;
		case 6:
			return std::make_pair(2,0);
			break;
		case 7:
			return std::make_pair(2,1);
			break;
		case 8:
			return std::make_pair(2,2);
			break;
		default:
			cout << "Wrong input!" << endl;
			exit(-1);
	}
}
void disp_table(vector< vector<int> > t){
	std::cout << t[0][0] <<  "  |  " << t[0][1] << "  |  " << t[0][2] << std::endl;
	std::cout << "---|-----|----" << std::endl;
	std::cout << t[1][0] <<  "  |  " << t[1][1] << "  |  " << t[1][2] << std::endl;
	std::cout << "---|-----|----" << std::endl;
	std::cout << t[2][0] <<  "  |  " << t[2][1] << "  |  " << t[2][2] << std::endl;
	std::cout << std::endl;
}

bool check_move(int move, int available[]){
	return available[move] == 0; // true if move is ok
}

void update_table(std::vector<std::vector<int> >& table, int move, int player){
	enum player{p1 = 0, p2 = 1};
	int x = map_move(move).first;
	int y = map_move(move).second;
	// p1
	if (player == p1){
	table[x][y] = 1;
	}
	// p2
	if (player == p2){
	table[x][y] = 2;
	}
}
// check if someone won the game
int check_win(std::vector< std::vector<int> > t){
	// rows win
	if(t[0][0]==1 && t[0][1]==1 && t[0][2]==1){
		return 1;
	}
	else if(t[0][0]==2 && t[0][1]==2 && t[0][2]==2){
		return 2;
	}
	else if(t[1][0]==1 && t[1][1]==1 && t[1][2]==1){
		return 1;
	}
	else if(t[1][0]==2 && t[1][1]==2 && t[1][2]==2){
		return 2;
	}
	else if(t[2][0]==1 && t[2][1]==1 && t[2][2]==1){
		return 1;
	}
	else if(t[2][0]==2 && t[2][1]==2 && t[2][2]==2){
		return 2;
	}
	// cols win
	else if(t[0][0]==1 && t[1][0]==1 && t[2][0]==1){
		return 1;
	}
	else if(t[0][0]==2 && t[1][0]==2 && t[2][0]==2){
		return 2;
	}
	else if(t[0][1]==1 && t[1][1]==1 && t[2][1]==1){
		return 1;
	}
	else if(t[0][1]==2 && t[1][1]==2 && t[2][1]==2){
		return 2;
	}
	else if(t[0][2]==1 && t[1][2]==1 && t[2][2]==1){
		return 1;
	}
	else if(t[0][2]==2 && t[1][2]==2 && t[2][2]==2){
		return 2;
	}
	// diags win
	else if(t[0][0]==1 && t[1][1]==1 && t[2][2]==1){
		return 1;
	}
	else if(t[0][0]==2 && t[1][1]==2 && t[2][2]==2){
		return 2;
	}
	else if(t[0][2]==1 && t[1][1]==1 && t[2][0]==1){
		return 1;
	}
	else if(t[0][2]==2 && t[1][1]==2 && t[2][0]==2){
		return 2;
	}
	// no win
	else{
		return 0;
	}
}
