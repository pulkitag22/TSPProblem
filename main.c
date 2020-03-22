#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int next_index_matrix [10][100];
    int input_matrix [10][100];
    int i = 0;
    int j = 0;
    int temp_sum_weight;
    int temp_weight;
    int final_min_weight;
    int final_path_initial_index;
    int final_path[100];
    int rows, cols;

    for (i=0; i<10; i++){
            for (j=0; j<100; j++){
                next_index_matrix[i][j] = 0;
            }
        }

    while (scanf("%d", &rows) != EOF){
        scanf("%d", &cols);
        /*Code for taking the input from the file.*/
        for (i=0; i<rows; i++){
            for (j=0; j<cols; j++){
                scanf("%d", &input_matrix[i][j]);
            }
        }
        /*-----------------------------------------*/
        /*For evaluating the weight and path*/
        for (j=cols-2; j>=0; j--){
            for (i=0; i<rows; i++){

                temp_weight = input_matrix[i][j];
                input_matrix[i][j] = input_matrix[i][j] + input_matrix[i][j+1];
                next_index_matrix[i][j] = i;
                temp_sum_weight = temp_weight + input_matrix[(i+rows-1)%rows][j+1];

                if (input_matrix[i][j] > temp_sum_weight){
                    input_matrix[i][j] = temp_sum_weight;
                    next_index_matrix[i][j] = (i+rows-1)%rows;
                }
                if ((input_matrix[i][j] == temp_sum_weight)&&(next_index_matrix[i][j] > ((i+rows-1)%rows))){
                    next_index_matrix[i][j] = (i+rows-1)%rows;
                }

                temp_sum_weight = temp_weight + input_matrix[(i+1)%rows][j+1];

                if (input_matrix[i][j] > temp_sum_weight){
                    input_matrix[i][j] = temp_sum_weight;
                    next_index_matrix[i][j] = (i+1)%rows;
                }
                if ((input_matrix[i][j] == temp_sum_weight)&&(next_index_matrix[i][j] > (i+1)%rows)){
                    next_index_matrix[i][j] = (i+1)%rows;
                }

            }
        }
        /*to print the output and find the minimum weight path*/
        final_min_weight = 999999999;
        final_path_initial_index = -1;
        i=0;
        for (i=0; i<rows; i++){
            if (final_min_weight > input_matrix[i][0]){
                final_min_weight = input_matrix[i][0];
                final_path_initial_index = i;
            }
        }
        final_path[0] = final_path_initial_index;
        for (i=1; i<cols; i++){
            final_path[i] = next_index_matrix[final_path[i-1]][i-1];
        }
        for (i=0; i<cols-1; i++){
            printf("%d ", final_path[i] + 1);
        }printf("%d", final_path[cols] + 1)
        printf("\n");
        printf("%d\n", final_min_weight);

    }
    return(0);

}
