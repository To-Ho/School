//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Symmetric Matrix class implementation file
// Written by Quoc Ho
// Date: Nov 28, 2017
//********************************************************************
#include "symetricMatrix.h"
#include<iostream>

using namespace std;

//*******************************************************************
// Symetric Matrix constructor given a dimension number, and input
//*******************************************************************
Symmetric_Matrix::Symmetric_Matrix(int i, double value)
{
  dim = i;
  numSize = (dim*(dim + 1))/2;
  numSize =+ 1;
  arr = new double [numSize];
  arr[numSize] = 0;
  for(int a = 0; a<numSize; a++)
    arr[a] = value;
}

//*******************************************************************
// Indexing operator to work on const objects
//*******************************************************************
const double& Symmetric_Matrix::operator() (int i, int j)
{
  int k; //index position
  if ((i<dim) & (j<=i))
    {
      k = ((i*(i+1))/2) + j;
    }
  else if((i<dim) & (j>i) & (j<dim))
    {
      k = (dim*i) - ((i*(i+1))/2) + j;
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
double& Symetric_Matrix::operator() (int i, int j)
{
  int k; //index position
  if ((i<dim) & (j<=i))
    {
      k = ((i*(i+1))/2) + j;
    }
  else if((i<dim) & (j>i) & (j<dim))
    {
      k = (dim*i) - ((i*(i+1))/2) + j;
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
void Symmetric_Matrix::print();
{
  int k; //index position
  cout << "The Symmetric Matrix:" << endl;
  for(int r = 0; r<dim; r++)
    {
      for(int c =0; c<dim; c++)
	{
	  if (c<=r)
	    {
	      k = ((r*(r+1))/2) + c;
	    }
	  else if(c>r)
	    {
	      k = (dim*r) - ((r*(r+1))/2) + c;
	    }
	  cout << arr[k] << " ";
	}
      cout << endl;
    }
}

//*******************************************************************
// Function to compute and return the absolute value of the largest
// rown sum
//*******************************************************************
double Symmetric_Matrix::infnorm()
{
  int k;
  double sum  = 0;
  double temp = 0;
  
  for(int r = 0; r<dim; r++)
    {
      for(int c =0; c<dim; c++)
	{
	  if (c<=r)
	    {
	      k = ((r*(r+1))/2) + c;
	    }
	  else if(c>r)
	    {
	      k = (dim*r) - ((r*(r+1))/2) + c;
	    }
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

//*******************************************************************
// This function read input from the user. Overwirte structured_matrix::read()
// because symmetric matrx required different input than structured matrix
//*******************************************************************
void Symmetric_Matric::read()
{
  cout << "Please enter input for Symmetric Matrix array" << endl;
  for (int i = 0; i < numSize; i++)
    {
      cout << "Index " << i << ": ";
      cin >> arr[i];
      cout << endl;
    }
}
