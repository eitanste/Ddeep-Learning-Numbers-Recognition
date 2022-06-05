#ifndef C___PROJECT_DENSE_H
#define C___PROJECT_DENSE_H

#include "Activation.h"

// implement class Dense here...


class Dense{
    const Matrix _weights;
    const Matrix _bias;
    Activation _activation;

public:
    Dense(const Matrix &w, const Matrix &bias, ActivationType type)
    : _weights(w), _bias(bias), _activation(type) {};

    /**
     *
     * @return
     */
    const Matrix &get_weights() const{return _weights;}

    /**
     *
     * @return
     */
    const Matrix &get_bias() const{return _bias;}

    /**
     *
     * @return
     */
    Activation get_activation() const {return _activation;}

    /**
     *
     * @param input
     * @return
     */
    Matrix operator()(const Matrix &input) const;

};

#endif //C___PROJECT_DENSE_H
