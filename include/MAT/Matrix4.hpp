/*
 * File:   Matrix4.hpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 22:53
 */

#ifndef MATRIX4_HPP
#define	MATRIX4_HPP

namespace mat
{
    struct Matrix4
    {
        double a1, a2, a3, a4,
               b1, b2, b3, b4,
               c1, c2, c3, c4,
               d1, d2, d3, d4;

        Matrix4() = default;
        void SetIdentity();
    };

    extern Matrix4 const k_identity;
}

#endif	/* MATRIX4_HPP */

