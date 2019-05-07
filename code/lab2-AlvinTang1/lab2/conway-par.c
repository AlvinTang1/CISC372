#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// macro expressions for easily computing positions
#define GETPOS(r, c) (r*COLS+c)
#define GETCOL(p)    (p%COLS)
#define GETROW(p)    (p/COLS)
#define D_LEFT(p)    ((GETCOL(p) == 0) ? p+COLS-1 :  p-1)
#define D_RIGHT(p)   ((GETCOL(p) == COLS-1) ? p-COLS+1 :  p+1)
#define D_TOP(p)     ((GETROW(p) == 0) ? GETCOL(p)+((ROWS-1) * COLS) : p-COLS)
#define D_BOTTOM(p)  ((GETROW(p) == ROWS-1) ? GETCOL(p) : p+COLS)

#ifndef cell_type
#define cell_type unsigned char
#endif

#ifndef cell_alive
#define cell_alive 1
#endif

#ifndef cell_dead
#define cell_dead 0
#endif

// global variables, yay!
int ROWS;
int COLS;

void evolve_cell(cell_type* inboard, cell_type* outboard, int position) {
    int count = inboard[D_LEFT(position)];
    count += inboard[D_RIGHT(position)];
    count += inboard[D_TOP(position)];
    count += inboard[D_BOTTOM(position)];
    count += inboard[D_LEFT(D_TOP(position))];
    count += inboard[D_RIGHT(D_TOP(position))];
    count += inboard[D_LEFT(D_BOTTOM(position))];
    count += inboard[D_RIGHT(D_BOTTOM(position))];

    outboard[position] = count == 3 || (inboard[position] && count == 2) ? cell_alive : cell_dead;
}

void update_row(cell_type* inboard, cell_type* outboard, int row) {
    int position = GETPOS(row, 0);
    int end = position + COLS;
    while (position < end) {
        evolve_cell(inboard, outboard, position++);
    }
}

void init_random(cell_type* board) {
    int position = 0;
    int positions = ROWS * COLS;
    while (position < positions) {
        board[position++] = (rand() % 2 == 1) ? cell_alive : cell_dead;
    }
}

void init_glider(cell_type* board) {
    board[GETPOS(1,2)] = cell_alive;
    board[GETPOS(2,2)] = cell_alive;
    board[GETPOS(3,2)] = cell_alive;
    board[GETPOS(3,1)] = cell_alive;
    board[GETPOS(2,0)] = cell_alive;
}

void print(cell_type* board) {
    int position = 0;
    int positions = ROWS * COLS;
    while (position < positions) {
        printf("%c", board[position++] == cell_alive ? 'x' : ' ');
        if (position % COLS == 0) {
            printf("\n");
        }
    }
}


//EDIT THIS
void simulate(cell_type* board[], int ticks, int output) {
	int i, j;
	int rank;
	int pRows;
	int pnodes;
  int count;
	int root = 0;
	int tag = 999;

	//  determine rank within MPI_COMM_WORLD
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &pnodes);

	double start, end;
	start = MPI_Wtime();

	//HERE
	/*
	 * Use MPI_Bcast, MPI_Probe, MPI_Recv, and MPI_Send
	 * Implement ROW-based data decomposition algorithm
	 */

	//Process 0 should broadcast entire source matrix to all other processes.

	//Each process should compute the target value for exactly (ROWS / P) rows where P is the number of total processes in the MPI run.
	pRows = ROWS / pnodes; //done.
 MPI_Status status;
 

	for(i = 0; i < ticks; i++){
		MPI_Bcast(board[i%2], (ROWS * COLS), MPI_UNSIGNED_CHAR, root, MPI_COMM_WORLD);

		if (output >= 2) {
			printf("board at tick %d:\n", i);
			print(board[i%2]);
		}

		for (j = 0; j < pRows; j++) {
			update_row(board[i%2], board[(i+1)%2], (rank * pRows) + j);
		}

		if(rank != 0){
			MPI_Send(&board[(i+1) %2][rank * pRows*COLS], pRows*COLS, MPI_UNSIGNED_CHAR, root, tag, MPI_COMM_WORLD);
		}
		else{
			for(j = 1; j < pnodes; j++){
				MPI_Probe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status,MPI_UNSIGNED_CHAR,&count);
				MPI_Recv(&board[(i+1)%2][count*status.MPI_SOURCE],count, MPI_UNSIGNED_CHAR, status.MPI_SOURCE,  tag, MPI_COMM_WORLD, &status);
			}
		}

	}

	end = MPI_Wtime();

	
    if (rank == 0 && output >= 1) {
		printf("final board:\n");
		print(board[i%2]);
	}
    if (rank == 0) {
    	printf("time at rank 0=%f \n", (end - start));
    }
}

int main(int argc, char **argv) {
    int i;
    int seed = 0;
    ROWS = 10;
    COLS = 10;
    int ticks = 10;
    int output = 1;

    // set command line args if provided
    if (argc > 1) {
        seed = atoi(argv[1]);
    }
    if (argc > 2) {
    	ROWS = atoi(argv[2]);
    }
    if (argc > 3) {
        COLS = atoi(argv[3]);
    }
    if (argc > 4) {
        ticks = atoi(argv[4]);
    }
    if (argc > 5) {
        output = atoi(argv[5]);
    }
    srand(seed);

    // create two boards for the simulation so we can
    // read from one and write to the other
    cell_type* board[] = {(cell_type*)malloc(sizeof(cell_type)*ROWS*COLS),
            (cell_type*)malloc(sizeof(cell_type)*ROWS*COLS)};

    if (argc > 6 && atoi(argv[6]) != 0) {
        init_random(board[0]);
    }
    else {
        init_glider(board[0]);
    }

    MPI_Init(&argc, &argv);

    simulate(board, ticks, output);

    MPI_Finalize();

    free(board[0]);
    free(board[1]);
    return 0;
}