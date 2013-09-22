/*
 * File:   Matrix4.cpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 22:53
 */

#include "MAT/Matrix4.hpp"

namespace mat
{
    Matrix4 const k_identity = { 1.0, 0.0, 0.0, 0.0,
                                 0.0, 1.0, 0.0, 0.0,
                                 0.0, 0.0, 1.0, 0.0,
                                 0.0, 0.0, 0.0, 1.0 };

    void Matrix4::SetIdentity()
    {
        *this = k_identity;
    }
}