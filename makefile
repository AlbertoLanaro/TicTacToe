OBJS = tic_tac_toe.cpp tic_funs.cpp
HEADER = tic_funs.h
CC = g++ --std=c++11

tic_tac_toe: $(OBJS) $(HEADER)
	$(CC) $(OBJS) -o tic_tac_toe.o
