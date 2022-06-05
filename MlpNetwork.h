//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

//
const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
                                    {64, 128},
                                    {20, 64},
                                    {10, 20}};
const matrix_dims bias_dims[]    = {{128, 1},
                                    {64, 1},
                                    {20, 1},
                                    {10, 1}};

// Insert MlpNetwork class here...

class MlpNetwork {
    Dense _dense_1;
    Dense _dense_2;
    Dense _dense_3;
    Dense _dense_4;



public:

    /**
     *
     * @param weights
     * @param biases
     */
    MlpNetwork(const Matrix weights[MLP_SIZE], const Matrix biases[MLP_SIZE]);



    /**
     *
     * @param mat
     * @return
     */
    Digit operator()(const Matrix &mat);

};

#endif // MLPNETWORK_H
