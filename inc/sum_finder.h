#ifndef HW3_INC_SUM_FINDER_H    //NOLINT
#define HW3_INC_SUM_FINDER_H    //NOLINT

#include <cstddef>
// using size_t
#include <iostream>
using std::cout;
using std::endl;

/* The function accepts an integer, an integer matrix, a pair of unsigned
 * integrals in a size_t array representing matrix size, and an unsigned
 * integral type output parameter storing the number of sums found. It returns
 * an n x 2 matrix with the indicies of any sums found.
 *
 * The function searches the columns, diagonals, and rows of the matrix
 * parameter for a series of integers which sum to the provided sum. It returns
 * the number sums found in the output parameter and pairs of any indices as
 * the function's return value.
 *
 * Preconditions:
 *  - All array parameters are allocated,
 *  - The matrix array's dimensions are correctly represented in the two
 *    elements of the array matrix_size.
 *
 * Parameters:
 *  - sum: the integer sum begin sought
 *  - matrix: a two-dimension integer array
 *  - matrix_size: a two-element size_t array with index 0 storing the number
 *    of rows, and index 1 storing the number of columns in the matrix.
 *    See kRow and kCol below.
 *  - sums_found: an output parameter to store the number of summations found
 *
 * Postconditions:
 *  - The output parameter sums_found corresponds to the number of summations
 *    found.
 *  - The output parameter sums_found holds zero if no summations were found.
 *
 * Returns:
 *  - Returns an unsigned integral type matrix of size n x 4, where n is the
 *    value in sums_found. If any summations are found, row the the matrix
 *    shall correspond to the following:
 *      {start row, start col, end row, end col}
 *    The returned values must be of the form:
 *      start row <= end row AND start column <= end column
 *  - Returns the nullptr if no summations were found.
 */
 size_t** FindSum(
int sum, const int** matrix, const size_t matrix_size[],
    size_t* sums_found);

/*
 * This function detects whether or not the sum we're looking for is equal to any one pair of neighbors in the matrix.
 *
 * Preconditions:
 *  - The integer passed in as the first parameter in the FindSum function is the sum we're looking for
 *
 * Parameters:
 *  - sum_found: unsigned integral representing the sum of the values between one pair of neighboring indices within the matrix
 *  - sum_actual: integer representing the sum we're looking for, passed from FindSum function to this function
 *
 * Postconditions:
 *
 * Returns:
 *  - Boolean determining the parameters are equal or not equal
 */
//bool sumWasDetected(size_t sum_found, int sum_actual);


/*
*   Adds each pair of neighboring indeces together once.
*   Neighbors are defined as those indeces within same row or column of any given index, no diagonal neighbors.
*   Iterator variables representing row and column indices of matrix are successively passed into this function until end column and rows of matrix to detect individual value at all indeces of the matrix
 *  Function is called under two seperate while loops in FindSum function. In first loop under which this function is called, the value at "each" current index is summed together with the value of each of its neighbors on same row. In second loop under which this function is called, the value at "each" current index is summed together with the value of each of its neighbors in same column.
*
* Preconditions:
*  - The matrix was correctly allocated in tester function
*  - The matrix array's dimensions are correctly represented in the two elements of the array matrix_size.
*  - Final parameter passed in equals either 1 or 0.
*  - All loops in FindSum function correctly iterate through matrix such that this function is called x number of times for each individual index, where x is the number of of column neighbors that index has.
*
*  Parameters:
*  - matrix: the two-dimensional array consisting of values we're summing together.
*  - current_row: unsigned integral represents row of current index in matrix...
*       ... determined by iterator variable of outer for loop in FindSum function
*  - current_column: unsigned integral represents column of current index in matrix...
*       ... determined by iterator variablle of nested for loop in FindSum function
* - column_neighbor: unsigned integral represents the column value of neighboring index...
*       ... on first call to function for any given current index, neighbor is offset by 1 from
*       ... the current_column value. Each succesive call to function will offset column_neighbor by 1
*       ... until there are no more column neighbors to be accounted for
*
* Postconditions
*  - Last parameter offset by 1, then function is immediately called again until the function call after which the last param...
*       ... was equal to the amount of column's in the matrix
*
* Returns:
*  - The sum of values at the current index with its next column neighbor to be accounted for
*/


size_t SumColumnNeighbors(const int** matrix, size_t current_row, size_t current_column, size_t column_neighbor);
/*
 *  Function is same as above but the logic is applied to the row neighbors, by the last parameter being initially offset by 1 with the current_row (the current outer for loop iterator variable)
 */
size_t SumRowNeighbors(const int** matrix, size_t, size_t, size_t);


//void Delete(size_t** matrix, size_t* sums_found);
//
//void PrintArray(size_t**, size_t*);
//void InitValues(size_t**, size_t*, size_t, size_t, size_t, int);


const size_t kRow = 0;  // maps to row of matrix_size
const size_t kCol = 1;  // maps to col of matrix_size
const size_t kStartRow = 0;  // maps to index of starting row in indices
const size_t kStartCol = 1;  // maps to index of starting colum in indices
const size_t kEndRow = 2;  // maps to index of ending row in indices
const size_t kEndCol = 3;  // maps to index of ending colum in indices
#endif  //NOLINT
