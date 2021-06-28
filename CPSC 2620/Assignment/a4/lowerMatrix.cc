//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Lower Triangular Matrix class implementation file
// Written by Quoc Ho
// Date: Dec 2, 2017
//********************************************************************
#include "lowerMatrix.h"

using namespace std;

//*******************************************************************
// Lower Triangular Matrix constructor given a dimension number, and input
//*******************************************************************
Lower_Triangular_Matrix::Lower_Triangular_Matrix(int i, double value)
{
  dim = i;
  numSize = (dim*(dim+1))/2;
  arr = new double [numSize+];
  arr[numSize]=0;
  for(int a = 0; a<dim; a++)
    arr[a] = value;
}

//*******************************************************************
// Indexing operator to work on const objects
//*******************************************************************
const double& Lower_Triangular_Matrix::operator() (int i, int j)
{
  int k;
  if ((i<dim) & (j<=i))
    {
      k = ((r*(r+1))/2) + c;
    }
  else if((i<dim) & (j>i) & (j<dim))
    {
      cout << "Outside the size of index. Return 0.0" << endl;
      return arr[numSize];
    }
  else
    {
      cout << "Invalid row or column value!" <<endl;
      cout << "The structure has the dimension of " << dim << endl;
      cout << "Exiting....." << endl;
      exit(1);
    }
  return arr[k];
}

//*******************************************************************
// Indexing operator to work with non-const objects
//*******************************************************************
double& Lower_Triangular_Matrix::operator() (int i, int j)
{
  int k;
  if ((i<dim) & (j<=i))
    {
      k = ((r*(r+1))/2) + c;
    }
  else if((i<dim) & (j>i) & (j<dim))
    {
      cout << "Outside the size of index. Return 0.0" << endl;
      return arr[numSize];
    }
  else
    {
      cout << "Invalid row or column value!" <<endl;
      cout << "The structure has the dimension of " << dim << endl;
      cout << "Exiting....." << endl;
      exit(1);
    }
  return arr[k];
}

//*******************************************************************
// Print function for Symmetric Matrix
//*******************************************************************
void Lower_Triangular_Matrix::print()
{
  int k;
  cout << "A Lower triangular matrix:" << endl;
  for(int r = 0; r<dim; r++)
    {
      for(int c =0; c<dim; c++)
	{
	  if (c<=r)
	    {
	      k = ((r*(r+1))/2) + c;
	      cout << arr[k] << " ";
	    }
	  else if(c>r)
	    {
	      cout << arr[numSize] << " "; //print 0
	    }
	}
      cout << endl;
    }
}

//*******************************************************************
// Function to compute and return the absolute value of the largest
// row sum
//*******************************************************************
double Lower_Triangular_Matrix::infnorm()
{
  int k;
  double sum = 0;
  double temp = 0;
  for (int r = 0; r < dim; r++)
    {
      for(int c = 0; c<=r; c++)
	{
	  k = ((r*(r+1))/2) + c;
	  temp = abs(arr[k]) + temp;
	}
      if(temp >= sum)
	{
	  sum = temp;
	  temp = 0;
	}
      else
	temp = 0;
    }
  return sum;
}
