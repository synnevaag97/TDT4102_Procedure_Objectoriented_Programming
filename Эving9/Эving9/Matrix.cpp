#include "Matrix.h"

Matrix::Matrix(int rows, int columns):rows(rows), columns(columns)
{
    matrix = new double*[rows];

    for(int i = 0; i<rows;i++){
        matrix[i] = new double[columns];

        for(int j = 0; j < columns; j++){
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows): Matrix(rows, rows) // Delegerende konstruktør
{
    for(int i = 0; i<rows;i++){
        for(int j = 0; j < rows; j++){
            if(i==j){
                matrix[i][j] = 1;
            }
        }
    }
}

Matrix::~Matrix()
{
    for(int i = 0; i<rows;i++){
         delete matrix[i];
         matrix[i] = nullptr;
    }  
    delete[] matrix;
    matrix = nullptr;
}

void Matrix::set_matrixValue(int row, int column, double value){
    matrix[row][column] = value;
}
double Matrix::get_matrixValue(int row, int column) const{
    return matrix[row][column];
}

double *Matrix::operator[](int row){
    return matrix[row];
}

std::ostream &operator<<(std::ostream &out, const Matrix &elem){
    for(int i = 0;i<elem.get_rows();i++){
        std::cout << "Column " << i << '\n';
        for(int j = 0;j<elem.get_columns();j++){
            out << elem.get_matrixValue(i,j) << '\n';
        }
    }
    return out;
}


Matrix& Matrix::operator=(Matrix newMatrix){
    std::swap(this->matrix,newMatrix.matrix);
    std::swap(this->rows,newMatrix.rows);
    std::swap(this->columns,newMatrix.columns);
    return *this;
}

Matrix::Matrix(const Matrix & newMatrix): rows(newMatrix.rows), columns(newMatrix.columns), matrix(newMatrix.matrix)
{

    matrix = new double*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = newMatrix.matrix[i][j];
		}
	}
}