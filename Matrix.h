// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
    int rows, cols;
} matrix_dims;

// Insert Matrix class here...

class Matrix {
    private:
        int _rows;
        int _cols;
        int _size;
        float *_data;

    public:

    /**
     * Default ctor
     */
    Matrix(void);

    /**
     * Ctor specifying rows and cols
     * @param rows
     * @param cols
     */
    Matrix(int rows, int cols);

    /**
     * Copy ctor
     * @param matrix
     */
    Matrix(const Matrix &matrix);

    /**
     * Matrix destructor
     */
    ~Matrix(void);

    /**
     *
     * @return
     */
    int get_rows(void) const;

    /**
     *
     * @return
     */
    int get_cols(void) const;

    /**
     *
     */
    Matrix &transpose(void);
    /**
     *
     */
    Matrix &vectorize(void);

    /**
     *
     */
    void plain_print(void) const;

    /**
     *
     * @param matrix
     * @return
     */
    Matrix dot(const Matrix &matrix) const;

    /**
     *
     * @return
     */
    float norm(void) const;

    /**
     * Read matrix values from istream.
     * @param istream
     * @param matrix
     */
    friend int read_binary_file(std::istream &is, Matrix &matrix);

    /**
     *
     * @param matrix
     * @return
     */
    Matrix operator+(const Matrix& matrix) const;

    /**
     *
     * @param matrix
     * @return
     */
    Matrix& operator=(const Matrix& matrix);

    /**
     *
     * @param matrix
     * @return
     */
    Matrix operator*(const Matrix& matrix) const; // matrix mult

    /**
     *
     * @param x
     * @return
     */
    Matrix operator*(float x) const; // scalar mult from right

    // TODO: check int * Mattrix case
    /**
     *
     * @param x
     * @param mat
     * @return
     */
    friend Matrix operator*(float x, const Matrix &mat) ; // scalar mult from left TODO: how this is implemented?

    /**
     *
     * @param matrix
     * @return
     */
    Matrix& operator+=(const Matrix& matrix);

    /**
     *
     * @param i
     * @param j
     * @return
     */
    float operator()(int i,int j) const;
    float &operator()(int i,int j);

    /**
     *
     * @param i
     * @return
     */
    float operator[](int i) const;

    /**n
     *
     * @param i
     * @return
     */
    float &operator[](int i);

    /**
     *
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
};


#endif //MATRIX_H
