#include<stdio.h>
#define MAXSIZE 10


void clear_buffer(void){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF){
    }
}


void input_matrix(int row, int col,double M[MAXSIZE][MAXSIZE]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf( "%lf", &M[i][j]);
        }
    }
}


void print_matrix(int row, int col, double M[MAXSIZE][MAXSIZE]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%8.3f",M[i][j]);
        }
        printf("\n");
    }
}


void add_matrix(int row_M, int row_N,int col_M, int col_N,  double M[MAXSIZE][MAXSIZE], double N[MAXSIZE][MAXSIZE]){
    if(row_M != row_N || col_M != col_N){
        printf("The two matrix cannot be added.");
    }else{
        double V[MAXSIZE][MAXSIZE];
        for (int i = 0; i < row_M; i++){
            for (int j = 0; j < col_M; j++){
                V[i][j] = M[i][j] + N[i][j];
            }
        }
        print_matrix(row_M, col_M, V);
    }
}


void trans_matrix(int row_M, int col_M, double M[MAXSIZE][MAXSIZE]){
    double N[MAXSIZE][MAXSIZE];
    for (int i = 0; i < col_M; i++){
        for (int j = 0; j < row_M; j++){
            N[i][j] = M[j][i];
            print_matrix(col_M, row_M, N);
        }
    }
}


void mult_maxtrix(int row_M, int row_N,int col_M, int col_N,  double M[MAXSIZE][MAXSIZE], double N[MAXSIZE][MAXSIZE]){
    double V[MAXSIZE][MAXSIZE] = {0}, S[MAXSIZE][MAXSIZE];
    if (col_M = row_N){
        for (int k = 0; k < col_M; k++){
            for (int i = 0; i < row_M; i++){
                for (int j = 0; j < col_N; j++){
                    S[i+1][j+1] = M[i+1][k+1]*N[k+1][j+1];
                    V[i+1][j+1] = V[i+1][j+1] + S[i+1][j+1];
                }
            }
        }
        print_matrix(row_M, col_N, V);
    }else{
        printf("The two matrix cannot multiple.");
    }
}


int main(void){
    double A[MAXSIZE][MAXSIZE];
    double B[MAXSIZE][MAXSIZE];
    int row_A = 0 ,col_A = 0;
    int row_B = 0 ,col_B = 0;
    int has_A = 0 ,has_B = 0;

    int choose;
    while(1){    
    printf("\n---------------matrix calculator---------------------\n");
    printf("Please enter order according to the tips.\n");
    printf("Enter matrix A : 1 \n");
    printf("Enter matrix B : 2 \n");
    printf("Print matrix A : 3 \n");
    printf("Print matrix B : 4 \n");
    printf("Add two matrix : 5 \n");
    printf("Transpose a matrix A : 6 \n");
    printf("Transpose a matrix B : 7 \n");
    printf("Multiple two matrices (AB) : \n");
    printf("Exit : 0 \n");
    printf("Select an option.\n");
    
    if(scanf("%d",&choose) != 1){
        printf("Invalid option. Plese try it again.\n");
        clear_buffer();
        continue;
    }

    if(choose == 1){
        printf("Please enter row-number and coloumn-number of the matrix.\n");
        if(scanf("%d %d", &row_A,&col_A) != 2){
        printf("Invalid input.");
        clear_buffer();
        continue;
        }else{
            if(row_A < 1||col_A < 1||row_A > MAXSIZE||col_A > MAXSIZE){
                printf("Invalid input.");
                clear_buffer();
                continue;
            }else{
                has_A = 1;
                printf("Please enter the numbers of the matrix accordingly.\n");
                input_matrix(row_A, col_A, A);
                printf("Successfully input.");
        }
        }   
    }
    else if(choose == 2){
        printf("Please enter row-number and coloumn-number of the matrix.\n");
        if(scanf("%d %d", &row_B,&col_B) != 2){
            printf("Invalid input.");
            clear_buffer();
            continue;
        }else{
            if(row_B < 1||col_B < 1||row_B > MAXSIZE||col_B > MAXSIZE){
                printf("Invalid input.");
                clear_buffer();
                continue;
            }else{
                has_B = 1;
                printf("Please enter the numbers of the matrix accordingly.\n");
                input_matrix(row_B, col_B, B);
                printf("Successfully input.");
        }
        }   
    }

    else if (choose == 3){
        if (has_A == 0){
            printf("You should enter matrix A first.\n");
        }else{
            print_matrix(row_A, col_A, A);
        }
    }
    else if (choose == 4){
        if (has_B == 0){
            printf("You should enter matrix B first.\n");
        }else{
            print_matrix(row_B, col_B, B);
        }
    }

    else if(choose == 5){
        if (has_A != 1 || has_B != 1){
            printf("You should enter matrices first.");
            continue;
        }else{
            add_matrix(row_A, row_B, col_A, col_B, A, B);
        }
    }

    else if (choose == 6){
        if (has_A == 0){
            printf("Please enter the matrix A first.");
            continue;
        }else{
            trans_matrix(row_A, col_A, A);
        }
    }
    
    else if (choose == 7){
        if (has_A == 0){
            printf("Please enter the matrix A first.");
            continue;
        }else{
            trans_matrix(row_B, col_B, B);
        }
    }
    
    else if (choose == 8){
        if (has_A == 0 || has_B == 0){
            printf("You should enter the matrices first.");
            continue;
        }else{
            mult_maxtrix(row_A,row_B, col_A, col_B, A, B);
        }
    }


    else if(choose == 0){
        clear_buffer();
        printf("Successfully exited.\n");
        return 0;
    }else{
        printf("Invalid input.");
    }

    }
return 0;   
}
