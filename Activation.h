//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    RELU,
    SOFTMAX
};

// Insert Activation class here...

class Activation {
    ActivationType _act_type;

    void relu_activation(const Matrix &input, Matrix &output) const;

    void softmax_activation(const Matrix &input, Matrix &output) const;

public:

    Activation(ActivationType act_type) : _act_type(act_type) {}

    ActivationType get_activation_type() const {
        return _act_type;
    }

    Matrix operator()(const Matrix &m) const;
};


#endif //ACTIVATION_H
