/*
 * File:   Matrix4.cpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 22:53
 */

#include "MAT/Matrix4.hpp"

#include <cassert>
#include <cstring>

namespace mat
{
    Matrix4 const k_identity = { { 1.0, 0.0, 0.0, 0.0,
                                   0.0, 1.0, 0.0, 0.0,
                                   0.0, 0.0, 1.0, 0.0,
                                   0.0, 0.0, 0.0, 1.0 } };

    double & Matrix4::operator()( int const& i_column, int const& i_row ) // 0-indexed
    {
        assert( i_column >= 0 && i_column < 4 && i_row >= 0 && i_row < 4);
        return m_data[ i_column * 4 + i_row ];
    }

    double const& Matrix4::operator()( int const& i_column, int const& i_row ) const // 0-indexed
    {
        assert( i_column >= 0 && i_column < 4 && i_row >= 0 && i_row < 4);
        return m_data[ i_column * 4 + i_row ];
    }

    double & Matrix4::operator[]( int const& i_arrayIndex )
    {
        assert( i_arrayIndex >= 0 && i_arrayIndex < 16 );
        return m_data[ i_arrayIndex ];
    }

    double const& Matrix4::operator[]( int const& i_arrayIndex ) const
    {
        assert( i_arrayIndex >= 0 && i_arrayIndex < 16 );
        return m_data[ i_arrayIndex ];
    }

    void Matrix4::SetIdentity()
    {
        *this = k_identity;
    }

    void Matrix4::Multiply( Matrix4 const& i_rhs )
    {
        for ( int column = 0; column < 4; ++column )
        {
            double row0 ( (*this)( column, 0 ) ),
                   row1 ( (*this)( column, 1 ) ),
                   row2 ( (*this)( column, 2 ) ),
                   row3 ( (*this)( column, 3 ) );
            (*this)( column, 0 ) = row0 * i_rhs( 0, 0 ) +
                                   row1 * i_rhs( 1, 0 ) +
                                   row2 * i_rhs( 2, 0 ) +
                                   row3 * i_rhs( 3, 0 );
            (*this)( column, 1 ) = row0 * i_rhs( 0, 1 ) +
                                   row1 * i_rhs( 1, 1 ) +
                                   row2 * i_rhs( 2, 1 ) +
                                   row3 * i_rhs( 3, 1 );
            (*this)( column, 2 ) = row0 * i_rhs( 0, 2 ) +
                                   row1 * i_rhs( 1, 2 ) +
                                   row2 * i_rhs( 2, 2 ) +
                                   row3 * i_rhs( 3, 2 );
            (*this)( column, 3 ) = row0 * i_rhs( 0, 3 ) +
                                   row1 * i_rhs( 1, 3 ) +
                                   row2 * i_rhs( 2, 3 ) +
                                   row3 * i_rhs( 3, 3 );
        }
    }

    Matrix4 Multiply( Matrix4 i_lhs, Matrix4 const& i_rhs )
    {
        i_lhs.Multiply( i_rhs );
        return i_lhs;
    }
}