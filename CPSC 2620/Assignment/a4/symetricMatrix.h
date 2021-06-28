//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Symetric Matrix class definition file
// Written by Quoc Ho
// Date: Nov 28, 2017
//********************************************************************
#include<iostream>
#inlcude "structuredMatrix.h"

using namespace std;

class Symmetric_Matrix : public Structured_Matrix
{
 public:
  Symmetric_Matrix(int = 0, double = 0.0); 
  const double& operator() (int, int) const;
  double& operator() (int, int) = 0;
  void print();
  void read(); //New read function because symmetric matrix class requires
  // diffrent inputs
  double infnorm();

 private:
  double* arr;
  int dim;
  int numSize;
};

// For this symmetric matrix, I use both the mapping for lower and upper
// triangular matrices. FOr example; we have a symmetric matrix with the
// dimension, n, equal 3. So the array would have (n(n+1))/2 = (3(3+1))/2
// = 6. So we have an array of 6 indexes.
// The for an example; we have an array of arr[6] = {1,2,3,4,5,6}
// We will using the lower triangular to map the lower half and the
// diagonal line of the matrix; using the indexing formular:
// (row*(row+1))/2 + column
// For the upper half above the diagonal line, we will use upper triangular
// mapping with the indexing formular
// (dimesion*row) - ((row*(row+1))/2) + column
// we can do this because M(i,j) = M(j,i) in the symmetric matrix
// Example of indexing map for symmetric matrix with a dimension of 3
// 0 1 2
// 1 2 4
// 3 4 5
