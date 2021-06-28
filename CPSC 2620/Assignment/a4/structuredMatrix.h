//********************************************************************
// CPSC 2620 Fall 2017
// Assignment 4
// Structured Matrix class definition file
// Written by Quoc Ho
// Date: Nov 28, 2017
//********************************************************************
#ifndef STRUCTUREDMATRIX_H
#define STRUCTUREDMATRIX_H

#include<istream>
#include<fstream>

using namespace std;

class Structured_Matrix
{
 public:
  Structured_Matrix(int = 0, double = 0.0); //constructor can not be virtual

  virtual const double& operator()(int, int) const = 0; //pure virtual because
  // this function does not have to implement in abstract class

  virtual double& operator() (int, int) = 0; //pure virtual becuase this
  // function does not have to implement in abstract class

  virtual void read(); //virtual beccause need this function for Structured
  // Matrix

  virtual void print(); //virtual because we need this function for Symmetric
  // Matrix class

  virtual double infnorm(); //virtual because we need this function for this
  // structured matrix class
  
 private:
  double* arr;
  int dim;
  int numSize;
};
#endif
