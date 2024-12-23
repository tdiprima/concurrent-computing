/*
This code contains two templates - Allocate2DArray and Free2DArray.
Allocate2DArray function takes the number of rows and columns as arguments and allocates memory for a 2D array of specified type. It first allocates a block of memory for the array that will hold the pointers to the rows, then it allocates a block of memory for all the array elements (row*column). Finally, it correctly assigns the row pointers to the appropriate positions. The function returns a pointer to the allocated 2D array.

Free2DArray function takes a 2D array as an argument and frees up the memory previously allocated for the array. It starts by freeing the memory that was allocated for the array elements, then it liberates the memory that was allocated for the array of row pointers.
*/
template < typename T >
T **Allocate2DArray( int nRows, int nCols)
{
    //(step 1) allocate memory for array of elements of column
    T **ppi = (T **) malloc(sizeof(T *)*nRows);

    //(step 2) allocate memory for array of elements of each row
    T *curPtr = (T *) malloc(sizeof(T) * nRows * nCols);

    // Now point the pointers in the right place
    for( int i = 0; i < nRows; ++i)
    {
        *(ppi + i) = curPtr;
         curPtr += nCols;
    }
    return ppi;
}

template < typename T >
void Free2DArray(T** Array)
{
    free(*Array);
    free(Array);
}
