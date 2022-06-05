#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Matrix.h"

#define MATRIX_INIT_SIZE_ERROR "Error: invalid matrix size params"
#define MATRIX_SIZE_DIF_ERROR "Error: the matrices is not of the same dimensions"
#define FILE_NOT_OPEN_ERROR "Error: the file weren't able to open correctly"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using std::cout;
using std::cerr;
using std::endl;
using std::_Exit;


void exit_func(int exit_status, const std::string &message) {
    std::cerr << message << std::endl;
    std::_Exit(exit_status);
}

void mat_size_compere(const Matrix matrix_a, const Matrix matrix_b) {
    if (matrix_a.get_cols() != matrix_b.get_cols() ||
        matrix_a.get_rows() != matrix_b.get_rows()) {
        exit_func(EXIT_FAILURE, MATRIX_SIZE_DIF_ERROR);
    }
}

Matrix::Matrix(int rows, int cols) {
    if (rows >= 0 || cols >= 0) {
        _rows = rows;
        _cols = cols;
        _size = _rows * _cols;
        _data = new float[_size]{0};
    } else {
        exit_func(EXIT_FAILURE, MATRIX_INIT_SIZE_ERROR);
//        exit(EXIT_FAILURE);
    }


//    for (int i = 0; i < size; ++i) { // TODO: chek if () in new statement initializing the values?
//        data[i] = 0;
//    }
}

Matrix::Matrix(void) : Matrix(1, 1) {}


Matrix::Matrix(const Matrix &matrix) {
    _rows = matrix._rows;
    _cols = matrix._cols;
    _size = matrix._size;
    _data = new float[_size]{0};
    for (int i = 0; i < _size; ++i) {
        this->_data[i] = matrix._data[i];
    }
}

Matrix::~Matrix() {
    delete _data;
}

int Matrix::get_rows() const {
    return _rows;
}

int Matrix::get_cols() const {
    return _cols;
}

Matrix &Matrix::transpose(void) {
    Matrix temp(*this);
    int temp_rows;
    int placement_ind = 0;

    for (int i = 0; i < _cols; ++i) {
        for (int j = 0; j < _rows; ++j) {
            (*this)[placement_ind] = temp[i + j*_cols];
            ++placement_ind;
        }
    }

    temp_rows = _rows;
    _rows = _cols;
    _cols = temp_rows;
    return *this;
}

Matrix &Matrix::vectorize() {
    _rows = _rows * _cols;
    _cols = 1;

    return *this;
}

void Matrix::plain_print(void) const {
    for (int j = 0; j < _rows; ++j) {
        for (int i = 0; i < _cols; ++i) {
            std::cout << _data[j * _cols + i] << ' ';
        }
        std::cout << '\n';
    }
}

Matrix Matrix::dot(const Matrix &matrix) const {
    Matrix res(_rows, _cols);

    mat_size_compere(*this, matrix);

    for (int i = 0; i < _size; ++i) {
        res._data[i] = (_data[i] * matrix._data[i]);
    }
    return res;
}

float Matrix::norm() const {
    float sum = 0;

    for (int i = 0; i < _size; ++i) {
        sum += _data[i] * _data[i];
    }
    return std::sqrt(sum);
}

int read_binary_file(std::istream &is, Matrix &matrix) {
    is.read((char *)matrix._data, matrix._size * sizeof(float));
    if (is) {
        // TODO: print read error
        return 0;
    }
    return 1;
}
//
//
// read content of binary file binfile, assuming it contains a list
// of floats in binary format
//std::vector<float>
//read_floats_from_binary(const std::string& binfile) noexcept(false)
//{
//    std::ifstream is;
//    // open a file in binary mode and empty any prior content
//    is.open(FILENAME, std::ios_base::binary);
//    if(!is.is_open())
//    {
//        throw std::ios_base::failure("Cannot open file " + binfile);
//    }
//    is.seekg(0, is.end); // go to end of file
//    int n_bytes = is.tellg(); // tell how many bytes since beginning of fil
//    assert((n_bytes != -1) && (n_bytes%sizeof(float)==0));
//    is.seekg(0, is.beg); // go to beginning of file
//    unsigned int n = n_bytes/sizeof(float);
//    std::vector<float> v(n); // construct a vector with n elements
//
//    is.read((char*)v.data(), n_bytes);
//
//    // WRITE-ME using a single is.read() command
//    // https://www.cplusplus.com/reference/istream/istream/read/
//    // HINT 1: To access the data in the vector, use v.data() of type float*
//    // HINT 2: convert it to char* using (char*)v.data()
//
//
//    is.close();
//    return v;
//}
//


std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m._rows; ++i) {
        for (int j = 0; j < m._cols; ++j) {
            if (m(i, j) >= 0.1)
                std::cout << "  ";
            else
                std::cout << "**";
        }
        std::cout << '\n';
    }
    return os;
}


Matrix Matrix::operator+(const Matrix &matrix) const {

    mat_size_compere(*this, matrix);

    Matrix temp(*this);

    for (int i = 0; i < _size; ++i) {
        temp._data[i] = (_data[i] + matrix._data[i]);
    }
    return temp;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix)
        return *this;
    _data = new float[matrix._size];
    _cols = matrix.get_cols();
    _rows = matrix.get_rows();
    for (int i = 0; i < _size; ++i) {
        this->_data[i] = matrix._data[i];
    }
    return *this;

}

Matrix Matrix::operator*(const Matrix &matrix) const {
    if (_cols != matrix._rows) {
        exit_func(EXIT_FAILURE, MATRIX_SIZE_DIF_ERROR);
    }
    Matrix temp(this->_rows, matrix._cols);
    float sum;

    for (int j = 0; j < _rows; ++j) {
        for (int k = 0; k < matrix._cols; ++k) {
            sum = 0;
            for (int i = 0; i < _rows; ++i) {
                sum += (*this)(j, i) * matrix(i, k);
            }
            temp(j, k) = sum;
        }
    }
    return temp;
}

Matrix Matrix::operator*(float x) const {
    Matrix temp(*this);

    for (int j = 0; j < _size; ++j) {
        temp._data[j] = temp._data[j] * x;
    }
    return temp;
}

Matrix operator*(float x, const Matrix &mat) {
    Matrix temp(mat);

    for (int j = 0; j < mat._size; ++j) {
        temp._data[j] = temp._data[j] * x;
    }
    return temp;
}

Matrix &Matrix::operator+=(const Matrix &matrix) {
    mat_size_compere(*this, matrix);

    for (int i = 0; i < _size; ++i) {
        _data[i] = (_data[i] + matrix._data[i]);
    }
    return *this;
}


float Matrix::operator()(int i, int j) const {
    return _data[i * _cols + j];
}

float &Matrix::operator()(int i, int j) {
    return _data[i * _cols + j];

}

/**
     *
     * @param i
     * @return
     */
float Matrix::operator[](const int i) const {
    return _data[i];
}

/**
 *
 * @param i
 * @return
 */
float &Matrix::operator[](int i) {
    return _data[i];
}

// n
