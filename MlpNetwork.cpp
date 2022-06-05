//
// Created by Eitan on 04/09/2021.
//

#include "MlpNetwork.h"

MlpNetwork::MlpNetwork(const Matrix weights[MLP_SIZE],
                       const Matrix biases[MLP_SIZE])
                       : _dense_1(weights[0], biases[0], ActivationType::RELU),
                       _dense_2(weights[1], biases[1], ActivationType::RELU),
                       _dense_3(weights[2], biases[2], ActivationType::RELU),
                       _dense_4(weights[3], biases[3], ActivationType::SOFTMAX)
                       {}


Digit MlpNetwork::operator()(const Matrix &in) {
    Matrix res[MLP_SIZE];
    Digit output = { 0, 0.0};

    res[0] =  _dense_1(in);
    res[1] = _dense_2(res[0]);
    res[2] = _dense_3(res[1]);
    res[3] = _dense_4(res[2]);

    for (int i = 0; i < res[3].get_rows() * res[3].get_cols(); ++i) {
        if (res[3][i] > output.probability) {
            output.value = i;
            output.probability = res[3][i];
        }
    }
    return output;
}