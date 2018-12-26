//Matrix.cpp
#include "stdafx.h"
#include "Matrix.h"
#include<iomanip>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Matrix::Matrix(int m,int n,float c):row(m),col(n),value(c)//class constructor
{
	//allocating memory for matrix
	mat = new float*[row];
	for (size_t i = 0; i < row; i++)
	{
		mat[i] = new float[col];
	}
	//initializing matrix
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			mat[i][j] = value;
		}
	}

}

Matrix::Matrix(int n):row(n),col(n),value(0)//overloading the constructor
{

	mat = new float*[row];
	for (size_t i = 0; i < row; i++)
	{
		mat[i] = new float[col];
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			mat[i][j] = value;
		}
	}

}


void Matrix::display() const//function to display matrix
{
	cout << setprecision(2) << fixed;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout <<setw(6)<< mat[i][j] << " ";
		}
		cout << endl;
	}

}

float& Matrix::at(int i, int j)//at function
{
	return mat[i][j];
}


  int Matrix::rows()const//returns number of rows
{
	return row;
}

 int Matrix::cols()const//returns number of columns
{
	return col;
}


 int Matrix::size()const//returns size of matrix
{
	return row*col;
}

 Matrix Matrix::add(const Matrix &a)//add function
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = a.mat[i][j]+mat[i][j];
		 }
	 }

	 return c;
 }

 Matrix Matrix::add(const int &a)//overload of add function to use with numbers
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = a + mat[i][j];
		 }
	 }

	 return c;
 }

 Matrix Matrix::subtract(const Matrix &a)//subtract function
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] =  mat[i][j] - a.mat[i][j];
		 }
	 }

	 return c;
 }

 Matrix Matrix::subtract(const int &a)//overload of subtract function to use with numbers
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = mat[i][j] - a;
		 }
	 }

	 return c;
 }

 Matrix Matrix::mult(const Matrix &a)//multiply function
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = a.mat[i][j] * mat[i][j];
		 }
	 }

	 return c;
 }

 Matrix Matrix::mult(const int &a)//overload of multiply function to use with numbers
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = a * mat[i][j];
		 }
	 }

	 return c;
 }

 Matrix Matrix::transpose()//function for transposing matrix
 {

	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = mat[j][i];
		 }
	 }
	 return c;
 }

 Matrix Matrix::subMatrix(int r, int s, int p, int q)//returning a submatrix of original matrix
 {
	 Matrix c(r, s);
	 int count = 0;
	 int q1 = q;
	 for (size_t i = 0; i <r; i++)
	 {
		 for (size_t j = 0; j <s; j++)
		 {

			 c.mat[i][j] = mat[p][q1];
			 if (count == s - 1)
			 {
				 count = 0;
				 q1 = q;
				 continue;

			 }
			 q1++;
			 count++;
		 }
		 p++;
	 }
	
	 return c;
 }

 void Matrix::swapRows(int row1, int row2)//function for swap 2 rows of matrix
 {
	 for (size_t j = 0; j < col; j++)
	 {
		 swap(mat[row1][j], mat[row2][j]);
	 }


 }

 void Matrix::linearCombination(int row1, int row2 , int coef)//function to add row2*coef elements to row1 elements
 {
	 for (size_t j = 0; j < col; j++)
	 {
		 mat[row1][j] += mat[row2][j] * coef;
	 }
 }

 float Matrix::trace() const//returns total sum of diagonal elements
 {
	 float total = 0;
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 if (i == j)
			 {
				 total += mat[i][j];
			 }
		 }
	 }

	 return total;
 }

 void Matrix::free()//to free allocated memory
 {
	 for (size_t i = 0; i < row; i++)
	 {
		 delete[] mat[i];
	 }
	 delete[] mat;

 }

 float& Matrix::operator()(int i, int j) const//overload paranthesis to access matrix variables
 {
	 return mat[i][j];
 }

 int Matrix::operator=(int num) const//overload assignment operator
 {
	return num;
 }

 Matrix Matrix::operator*(const Matrix &a)//overload * to multiply matrices 
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = a.mat[i][j] * mat[i][j];
		 }
	 }
	 return c;
 }


 Matrix Matrix::operator+(const Matrix &a)//overload + to add matrices
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = a.mat[i][j] + mat[i][j];
		 }
	 }

	 return c;

 }

 Matrix Matrix::operator-(const Matrix &a)//overload - to subtract matrices
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = mat[i][j] - a.mat[i][j];
		 }
	 }

	 return c;
 }

 const Matrix & Matrix::operator~() const//overload ~ operator to transpose a matrix
 {
	 Matrix c(row, col);
	 for (size_t i = 0; i < row; i++)
	 {
		 for (size_t j = 0; j < col; j++)
		 {
			 c.mat[i][j] = mat[j][i];
		 }
	 }
	 return c;
 }

 bool Matrix::operator==(const Matrix &a) const//overload equality operator
 {
	 if ((row != a.row) || (col != a.col))
		 return false;


	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (mat[i][j] != a.mat[i][j])
			{
				return false;
			}
		}
	}
	
		return true;
	 
 }


 Matrix identity_matrix(int n)//returns an identity matrix
 {
	 Matrix c(n);
	 for (size_t i = 0; i < n; i++)
	 {
		 for (size_t j = 0; j < n; j++)
		 {
			 if (i == j)
				 c.mat[i][j] = 1;
		 }
	 }
	 return c;
 }

 Matrix random_matrix(int m, int n,int start,int end)//returns a matrix with random numbers
 {
	 Matrix c(m, n);
	 srand(static_cast<unsigned int>(time(0)));
	 for (size_t i = 0; i < m; i++)
	 {
		 for (size_t j = 0; j < n; j++)
		 {
			 c.mat[i][j] = static_cast<float>((start + rand() % end));
		 }
	 }
	 return c;
 }


 ostream &operator<<(ostream &output, const Matrix &Mat)//print Matrix with output operations
 {

	 output << setprecision(2) << fixed;
	 for (size_t i = 0; i < Mat.row; i++)
	 {
		 for (size_t j = 0; j < Mat.col; j++)
		 {
			 output << setw(6) << Mat.mat[i][j] << " ";
		 }
		 output << endl;
	 }
	 return output;
 }

 istream &operator>>(istream &input, Matrix &Mat)//read matrix values from input
 {
	  for (size_t i = 0; i < Mat.row; i++)
	  {
		  for (size_t j = 0; j < Mat.col; j++)
		  {
			  cout << "Please enter value of mat[" << i << "][" << j << "] : ";
			  input >> Mat.mat[i][j];
		  }
	  }

	  return input;
 }
