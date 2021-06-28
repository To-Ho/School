// Polynomial.cc
#include "./polynomial.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

Polynomial::Polynomial()
{
    vector<int> P;
}

Polynomial::Polynomial(const vector<int>& coeff)
{
  int degree; //polynomial degree
  int coef = coeff.size(); //polynomial coefficient
  degree = coeff.size() - 1;
  vector<int> P;
  int n;
  for(int a = coef ; a <= coef && a >= 0; a--)
    {
      coeff[a] = n;
      P.push_back(n);
    }
  return *this;
}

const Polynomial& Polynomial::operator+(const Polynomial& RHS) const
{
  int s1 = max(P.size, RHS.P.size);
  vector<int> TempSum(s1);
  for(int i = 0; i<= s1; i++)
    {
      if(i > P.size && i < RHS.P.size)
	{
	  TempSum[i] = 0 + RHS.P[i];
	}
      if(i > RHS.P.size && i < P.size)
	{
	  TempSum[i] = P[i] + 0;
	}
      else
      TempSum[i] = P[i] + RHS.P[i];
    }
  return TempSum;
}


const Polynomial& Polynomial::operator-(const Polynomial& RHS) const
{
  int s2 = max(P.size, RHS.P.size);
  vector<int> TempSub(s2);
  for(int i = 0; i<= s2; i++)
    {
      if(i > P.size && i < RHS.P.size)
	{
	  TempSub[i] = 0 - RHS.P[i];
	}
      if(i > RHS.P.size && i < P.size)
	{
	  TempSub[i] = P[i] - 0;
	}
      else
      TempSub[i] = P[i] - RHS.P[i];
    }
  return TempSub;
}

double Polynomial::operator()(double x) const
{
  int val = P[0];
  for(int i = 1; i < degree; i++)
    {
      val += (pow(x, i) * P[i])
    }
  return val;
  
}

bool  Polynomial::setCoeff(int k, int c)
{
  
  if(k >= 0 && k<= degree)
    {
      c = P[k];
      return true;
    }
  else
    return false;
}

bool  Polynomial::getCoeff(int k, int& c)
{
  if( k>= 0 && k<=degree)
    {
      P[k] = c;
      return true;
    }
  else
    return false;
}

ostream& Polynomial::insert(ostream& ostr)
{
  if(P[degree] < 0)
    cout << "(" << P[degree] << ")" << "x^" << degree;
  else
    cout << P[degree] << "x^" << degree;
  
  for(int b = degree - 1; b < degree && b > 0; b--)
    {
      if(P[b} < 0)
	cout << " + (" << P[b] << ")" << "x^" << b;
      else
	cout << " + " << P[b] << "x^" << b;
    }
	  if(P[0] < 0)
	    cout << " + (" << P[0] << ")";
	  else
	    cout << " + " << P[0];
      cout << endl;

      return ostr;
}       

ostream& operator<<(ostream& ostr, const Polynomial& RHS)
{
  RHS.insert(ostr);
  return ostr;
}



