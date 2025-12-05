#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int d_count(int *c, int rows, int cols){
	int dead_count = 0;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			int pos = i*cols+j;
			if (c[pos] == 1){
				dead_count++;
			}
		}
	}
	return dead_count;
}

void game_engine(int *c, int *n, int rows, int cols){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			int neighbour_count = 0;
			int pos = i*cols+j;
			
			for (int k = -1; k <= 1; k++) {
        			for (int m = -1; m <= 1; m++) {
            
            				if (k == 0 && m == 0) continue;
            
            				int nr = i + k;
            				int nc = j + m;
            
            				if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                
                				int idx = nr * cols + nc;
               					if (c[idx] == 0) {
                    					neighbour_count++;
                				}
            				}
        			}
        		}
			
			if (c[pos] == 0){
				if(neighbour_count < 2 || neighbour_count > 3){
					n[pos] = 1;
				} else{
					n[pos] = 0;
				}
			} else{
				if(neighbour_count == 3){
					n[pos] = 0;
				} else{
					n[pos] = 1;
				}
			}
		}
	}				
}

void view(int *c, int *n, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int pos = i*cols+j;
			if(j == cols-1){
				if(n[pos] == 1){				
					printf("|   |\n");
				} else{
					printf("| # |\n");
				}
			} else{
				if(n[pos] == 1){				
					printf("|   ");
				} else{
					printf("| # ");
				}
			}
		}
	}
}

void rand_gen(int *c, int *n, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int pos = i*cols+j;
			int choice = rand() % 2;
			if(choice == 0){
				c[pos] = 0;
				n[pos] = 0;
			} else{
				c[pos] = 1;
				n[pos] = 1;
			}
		}
	}
}
			
int main(){
	srand(time(NULL));
	int rows, cols;
	printf("Enter the no. of rows: ");
	scanf("%d",&rows);
	printf("Enter the no. of columns: ");
	scanf("%d",&cols);
	printf("\n");
	
	int *current = (int *)malloc(rows * cols * sizeof(int));
	if (current == NULL){
		printf("Memory allocation failed!!!\n");
		return 1;
	}
	int *next = (int *)malloc(rows * cols * sizeof(int));
	if (current == NULL){
		printf("Memory allocation failed!!!\n");
		return 1;
	}
	
	int size = rows * cols;
	int step = 0;
	int dead_count = 0;
	int alive_count = 0;
	
	rand_gen(current,next,rows,cols);
	dead_count = d_count(current,rows,cols);
	alive_count = size - dead_count;
	view(current,next,rows,cols);	
	printf("INITIAL GRID\n");
	printf("Dead: %d Alive: %d\n\n",dead_count,alive_count);
	
	while(dead_count != size && alive_count != size){
		game_engine(current,next,rows,cols);
		view(current,next,rows,cols);
		int *temp = current;
		current = next;
		next = temp;
		step++;
		printf("STEP No. %d\n",step);
		dead_count = d_count(current,rows,cols);
		alive_count = size - dead_count;
		printf("Dead: %d Alive: %d\n\n",dead_count,alive_count);
		usleep(200000);
	}	
	
	free(current);
	current = NULL;
	free(next);
	next = NULL;
	return 0;
}
