#pragma once
#include <iostream>
#include <utility>

class Matrix{
    private:
    int rows;
    int columns;
    double **matrix;

    public:
    Matrix(int rows, int columns);

    explicit Matrix(int rows);

    ~Matrix();
    void set_matrixValue(int row, int column, double value);
    double get_matrixValue(int row, int column) const;


    double *operator[](int row);

    int get_rows() const{ return rows; }
    int get_columns() const{ return columns; }

    Matrix& operator=(Matrix newMatrix);

    Matrix(const Matrix& newMatrix);
};

std::ostream &operator<<(std::ostream &out, const Matrix &elem);
