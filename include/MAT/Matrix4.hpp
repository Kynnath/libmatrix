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
        double m_data[16];

        Matrix4() = default;
        double & operator()( int const& i_column, int const& i_row ); // 0-indexed
        double const& operator()( int const& i_column, int const& i_row ) const; // 0-indexed
        double & operator[]( int const& i_arrayIndex );
        double const& operator[]( int const& i_arrayIndex ) const;
        void SetIdentity();
        void Multiply( Matrix4 const& i_rhs );
    };

    extern Matrix4 const k_identity;

    Matrix4 Multiply( Matrix4 i_lhs, Matrix4 const& i_rhs );
}

#endif	/* MATRIX4_HPP */

