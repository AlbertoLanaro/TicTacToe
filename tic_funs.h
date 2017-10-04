#ifndef TIC_FUNS_H
#define TIC_FUNS_H

#include <iostream>
#include <vector>

std::vector< std::vector<int> > init_table();
std::pair<int,int> map_move(int);
void disp_table(std::vector< std::vector<int>>);
bool check_move(int, int[]);
void update_table(std::vector<std::vector<int>>&, int, int);
int check_win(std::vector<std::vector<int>>);

#endif