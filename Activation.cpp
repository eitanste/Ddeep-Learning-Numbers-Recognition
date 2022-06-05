//
// Created by Eitan on 04/09/2021.
//

#include <cmath>
#include "Activation.h"

void Activation::relu_activation(const Matrix &input, Matrix &output) const {
    int size = input.get_rows() * input.get_cols();

    for (int i = 0; i < size; ++i) {
        if (input[i] < 0) {
            output[i] = 0;
        } else {
            output[i] = input[i];
        }
    }
}

void Activation::softmax_activation(const Matrix &input, Matrix &output) const {
    float exp_sum = 0;
    float exp_x_value;
    int size = input.get_rows() * input.get_cols();

    for (int i = 0; i < size ; ++i) {
        exp_x_value = std::exp(input[i]);
        exp_sum += exp_x_value;
        output[i] = exp_x_value;
    }
    output = (1/exp_sum)*output;
}

Matrix Activation::operator()(const Matrix &m) const{
    Matrix out(m.get_rows(), m.get_cols());

    switch (_act_type)  {
        case ActivationType::RELU:
            relu_activation(m, out);
            break;
        case ActivationType::SOFTMAX:
            softmax_activation(m, out);
            break;
        default:
            //TODO: error
            break;
    }

    return out;
}


