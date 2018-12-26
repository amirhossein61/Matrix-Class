//Matrix.h
#pragma once
#include<iostream>
class Matrix
{
	friend std::ostream &operator<<(std::ostream &, const Matrix &);//print Matrix with output operations
	friend std::istream &operator>>(std::istream &, Matrix &);//read matrix values from input
public:
	float **mat;//2D Array
	Matrix(int,int ,float=0);//Matrix class constructor with 3 inputs and a default argument
	Matrix(int);//overload of constructor
	void display()const;//function to display matrix
	float& at(int, int);//at function
	inline int rows() const;//returns number of rows
	inline int cols() const;//returns number of columns 
	inline int size() const;//returns size of matrix
	Matrix add(const Matrix&);//add function
	Matrix add(const int&);//overload of add function to use with numbers
	Matrix subtract(const Matrix&);//subtract function
	Matrix subtract(const int&);//overload of subtract function to use with numbers
	Matrix mult(const Matrix&);//multiply function
	Matrix mult(const int&);//overload of multiply function to use with numbers
	Matrix transpose();//transpose of matrix
	Matrix subMatrix(int, int, int, int);//returns sub matrix of original matrix
	void swapRows(int, int);//swap two rows of matrix
	void linearCombination(int, int, int);//add coef of one row to another
	float trace() const;//total sum of diagonal elements
	void free();//to free allocated memory
	float& operator()(int, int) const;//overload paranthesis to access matrix variables
	int operator=(int) const;//overload assignment operator
	Matrix operator*(const Matrix& );//overload * to multiply matrices 
	Matrix operator+(const Matrix& );//overload + to add matrices 
	Matrix operator-(const Matrix& );//overload - to subtract matrices 
	const Matrix& operator~() const;//overload ~ operator to transpose a matrix
	bool operator==(const Matrix&) const;//overload equality operator

private:
	int row;//number of rows
	int col;//number of columns
	float value;//value of each element
};

Matrix identity_matrix(int);//identity matrix
Matrix random_matrix(int ,int ,int ,int );//matrix with random numbers
