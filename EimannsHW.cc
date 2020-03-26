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

        /*
        * 2D array allocation part needs to be set to...
        * ... sums_found because this is the part that initializes...
        * ... the number of rows...
        * ... then each row is set to 1D array of size[cols]
        */

        size_t **summations = new size_t*[cols];

        for (size_t i = 0; i< matrix_size[0]; ++i) {
            for (size_t j = 0; j < matrix_size[1]; ++j) {
               /*
               * I did mine a bit differently so i don't know for sure...
               * ... but i think rowsum and column sum should first be set to...
               * ... matrix[i][j] then incremented with your k variable...
               */

                int rowsum = 0;
                int colsum = 0;

                /*
                * I think k should be initialized to j+1 b/c
                * with the way it is now, if you were to make the changes i just
                * suggested then the first time iterating through loop, it'd add the current index...
                */
                for (size_t k = j; k < matrix_size[1]; ++k) {
                     rowsum += matrix[i][k];
                     colsum += matrix[j][i];
         

                if (rowsum == sum || colsum == sum) {
                        ++(*sums_found);
                        /*
                        * Unless it happens in code below, this is where seg fault occurs b/c
                        * ... you set summations equal to "cols," amount of pointers...
                        * ... but those pointers aren't pointing to anything themself I think.
                        * ... so you're trying to write to memory space that doesn't exist at this point
                        * ... because there are no columns for summations yet...
                        * so the line: size_t **summations = new size_t*[cols] 
                        * I think sets a pointer of a pointer var equal to "cols" amount of pointers
                        * so address that points to address is equal to cols amount of addresses
                        * so summations contains amount of space needed to store cols amount of variables 
                        * ... and the amount of variables needs to be equal to the amount of sums detected
                        * ... each pointer from 1 to sums_found needs to contain a 1D array of size 4 size_t...
                        * ... so lets why in loops below ret[i] = new size_t[4];
                        * ... so it's supposed go like this...
                        * ... 1. First sum is found
                        * ... 2. Create row, store indeces as values in the row summations[*sums_found]
                        * ... 3. But each time sum_found increments to value above 1,
                        * ... we know there's already an existing row so we have to like copy the contents of that...
                        * ... existing matrix we found after the previous time sums_found was incremented... 
                        * ... into new array with *sums_found amount of pointers... so like we then 
                        * ... copy the rows 0 to *sums_found-1 of the previously made array
                        * ... into the new array, delete previous in loop then store the values for new row in new array
                        * ... each time new sum is detected and I only have a vague idea of how to do that but my code does                        * ... but at least you can check my code out to see how I'm setting up the columns to the 2 rows i made then adding the values 
                        */
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
