// Copyright 2020 Mitchell Lambert(
#include "sum_finder.h" //NOLINT

size_t** FindSum (int sum, const int** matrix, const size_t matrix_size [], size_t* sums_found) {

    *sums_found = 0;
    size_t** summations = new size_t *[2];
    for (size_t i = 0; i < 2; ++i)
        summations[i] = new size_t [4];
    size_t sum_as_size_t = static_cast<size_t>(sum);
    
    for (size_t i = matrix_size[0]-matrix_size[0]; i < matrix_size[0]; ++i) {
        size_t row_neighbor = i+1;

        for (size_t j = matrix_size[1]-matrix_size[1]; j < matrix_size[1]; ++j) {
            size_t column_neighbor = j+1;
            
            while (column_neighbor < matrix_size[1]) {
                size_t result = SumColumnNeighbors(matrix, i, j, column_neighbor);
                if (result == sum_as_size_t) {
                    ++(*sums_found);
                    if (*sums_found == 1) {
                        summations[0][kStartRow] = i;
                        summations[0][kStartCol] = j;
                        summations[0][kEndRow] = i;
                        summations[0][kEndCol] = column_neighbor;
                    }
                    summations[1][kStartRow] = i;
                    summations[1][kStartCol] = j;
                    summations[1][kEndRow] = i;
                    summations[1][kEndCol] = column_neighbor;
                }
//                    summations = UpdateDynamicArray(summations, sums_found);
//                    InitValues(summations, sums_found, i, j, column_neighbor, 1);
//                    PrintArray(summations, sums_found);
                ++column_neighbor;
            }
            while (row_neighbor < matrix_size[0]) {
                    size_t result = SumRowNeighbors(matrix, i, j, row_neighbor);
                    if (result == sum_as_size_t) {
                        ++(*sums_found);
//                        summations = UpdateDynamicArray(summations, sums_found);
//                        InitValues(summations,sums_found, i, j, row_neighbor, 0);
//                        PrintArray(summations, sums_found);
                    }
                    ++row_neighbor;

            }
            
        }
        continue;
    }

    return summations;
}

size_t SumColumnNeighbors(const int** matrix, size_t current_row, size_t current_col, size_t column_neighbor) {
    return matrix[current_row][current_col] + matrix[current_row][column_neighbor];
    }

size_t SumRowNeighbors (const int** matrix, size_t current_row, size_t current_col, size_t row_neighbor)  {
    return matrix[current_row][current_col] + matrix[row_neighbor][current_col];
 }

//
//void InitValues(size_t** array, size_t* sums_found, size_t i, size_t j, size_t neighbor, int which_neighbor) {
//    if (which_neighbor == 0) {
//    array[*sums_found][kStartRow] = i;
//    array[*sums_found][kStartCol] = j;
//    array[*sums_found][kEndRow] = neighbor;
//    array[*sums_found][kEndCol] = j;
//    }
//    array[*sums_found][kStartRow] = i;
//    array[*sums_found][kStartCol] = j;
//    array[*sums_found][kEndRow] = i;
//    array[*sums_found][kEndCol] = neighbor;
//}


