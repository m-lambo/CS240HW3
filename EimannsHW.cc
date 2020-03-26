/* Copyright 2020 Eiman Najjar */
#include <sum_finder.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

    size_t** FindSum(
    int sum, const int** matrix, const size_t matrix_size[],
    size_t* sums_found) {
        *sums_found = 0;
        int cols = 4;
        size_t **summations = new size_t*[cols];
        for (size_t i = 0; i< matrix_size[0]; ++i) {
            for (size_t j = 0; j < matrix_size[1]; ++j) {
                int rowsum = 0;
                int colsum = 0;
                for (size_t k = j; k < matrix_size[1]; ++k) {
                     rowsum += matrix[i][k];
                     colsum += matrix[j][i];
                    if (rowsum == sum || colsum == sum) {
                        ++(*sums_found);
                        summations[0][0] = i;
                        summations[0][1] = j;
                        summations[0][2] = i;
                        summations[0][3] = k;
                    }
                }
            }
        }

        // create matrix
        size_t** ret = new size_t*[*sums_found];
        for (size_t i = 0; i < *sums_found; ++i) {
            ret[i] = new size_t[4];
            for (size_t j = 0; j < 4; ++j) {
                ret[i][j] = 0;            
            }
        }
        /*
        size_t temp[] = {0, 0, 0, 0};
        ret[0] = temp;
        return ret;
        */
       //ret[4] = *summations;
        for (int i = 0; i < *sums_found; ++i) {
            delete ret[i];
            ret[i] = new size_t[4];
            for (int j = 0; j < 4; j++) {
                ret[i][j] = summations[i][j];
            }
        }
        // delete ret[0];
        // ret[0] = new size_t[4];

        // for (int i = 0; i < 4; ++i) {
        //     ret[0][i] = *summations[i];
        // }
        return ret;
    }
