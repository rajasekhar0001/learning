/*
WAP to multiply two matrices using multiple threads
 Pre-requisites:- 
• Knowledge about multi-thread process, How to read and understand ‘man pages’.
• Good knowledge about pthread library functions.
• Multiplication of two matrices.
• Dynamic allocation for 2D array.
Objective: -
• To understand working and flow of multithread programs.
Requirements: -
1. Create three local matrices, M1 MxN M2 NxP and Result MxP (M1 columns = M2 
rows) where M, N & P values are provided by user. 
2. In case M1 columns != M2 rows print error message to user.
3. Create all matrices using dynamic allocation.
4. Use structure to pass arguments to threads
sample structure.
typedef struct thread_data
{
        short m1_row;
        short m1_col;
        short m2_col;
        int **matrix1;
        int **matrix2;
        int **result;
        short cur_row;
}Thread_data_t;
5. Each thread will calculate and store single row in result. So number of threads 
equals number of rows in M1.
Eg: M1= 1 2 3 M2 = 1 1 1
 1 1 1 2 2 2
 2 2 2 3 3 3
Thread 1 M1 row1 x M2 col1, col2, col3 →
 1x1 + 2x2 + 3x3 1x1 + 2x2 + 3x3 1x1 + 2x2 + 3x3
14 14 14
Thread 2 M1 row2 x M2 col1, col2, col3 →
 1x1 + 1x2 + 1x3 1x1 + 1x2 + 1x3 1x1 + 1x2 + 1x3
6 6 6
Thread 3 M1 row3 x M2 col1, col2, col3 →
 2x1 + 2x2 + 2x3 2x1 + 2x2 + 2x3 2x1 + 2x2 + 2x3
12 12 12
6. Don't create any global variables. 
7. Create generic function for matrix dynamic allocation and deallocating. 
Sample execution: -
1. ./matrix_mul
Enter M1 rows and columns
3  3
Enter M2 rows and columns
3  3
Enter M1 values
1  2  3  1  1  1  2  2  2
Enter M2 values
1  2  3  1  2  3  1  2  3
Result is
14 14 14
6 6 6
12 12 12
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_data {
        short m1_row;
        short m1_col;
        short m2_col;
        int matrix1[3][3];
        int matrix2[3][3];
        // int **result;
        short cur_row;
}Thread_data_t;

pthread_mutex_t mutex;

int result[3][3];

void *mul(void *data) {

    Thread_data_t *d = (Thread_data_t*) data;
    // printf("m")

    printf("Working in......\n");


    for (int i=0;i< 3;i++) {

        result[d->cur_row][i] = 0;
        for (int j=0;j<3;j++) {
            pthread_mutex_lock(&mutex);
            result[d->cur_row][i] += (d->matrix1[i][j] * d->matrix2[j][i]);
            pthread_mutex_unlock(&mutex);
        }
        
    }
    printf("Working end......\n");

}

int main() {

    pthread_mutex_init(&mutex, NULL);

    Thread_data_t obj[3] = {{3, 3, 3, {1, 2, 3, 1, 1, 1,2, 2, 2}, {1, 2, 3, 1, 2, 3, 1, 2, 3}},
    {3, 3, 3, {1, 2, 3, 1, 1, 1,2, 2, 2}, {1, 2, 3, 1, 2, 3, 1, 2, 3}},
    {3, 3, 3, {1, 2, 3, 1, 1, 1,2, 2, 2}, {1, 2, 3, 1, 2, 3, 1, 2, 3}}
    };
    
    pthread_t tid[3];

    

    for (int i=0;i<3; i++) {
        obj[i].cur_row = i;
        pthread_create(&tid[0], NULL, mul, &obj[i]);
    }
    

    // for (int i=0;i<3;i++) {
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);
        pthread_join(tid[2], NULL);
    // }
    printf("Working.......\n");

    for (int i=0;i<3;i++) {
        for (int j =3;j <3;j++) {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }

    pthread_mutex_destroy(&mutex);

}