//
// Created by Eitan on 04/09/2021.
//

# include "Dense.h"


Matrix Dense::operator()(const Matrix &input) const {
    return _activation(_weights * input + _bias);
}
