#ifndef __Matrix_INCLUDE__
#define __Matrix_INCLUDE__

#include <iostream>
#include "Vector.h"
using namespace std;

class Matrix
{
public:
    Matrix( int nRow = 2, int nCol = 2, int nElem = 0 );
    Matrix( const Matrix& m );
    virtual ~Matrix();
    Matrix& operator=( const Matrix& m );

    int GetRowNo() const;
    int GetColNo() const;
    operator Vector* ( ) const;

    // multiplication
    friend const Vector operator*( const Matrix& m, const Vector& v );
    friend const Matrix operator*( const Matrix& m1, const Matrix& m2 );

    // comparison
    friend bool operator==( const Matrix& m1, const Matrix& m2 );
    friend bool operator!=( const Matrix& m1, const Matrix& m2 );

    // indexation
    Vector& operator[]( int ix );             
    const Vector& operator[]( int ix ) const;   

    // io
    friend ostream& operator<<( ostream& out, const Matrix& m );
    friend istream& operator>>( istream& out, Matrix& m );

private:
    int m_nRow;         
    Vector* m_pVectors; 
    void createMatrix( int nRow = 2, int nCol = 2, int nElem = 0 );
    void copyMatrix( const Matrix& m );
    const Matrix transposition() const;
};

#endif __Matrix_INCLUDE__

inline Vector& Matrix::operator[]( int ix )
{
    if( ix >= 0 && ix < GetRowNo() ) return m_pVectors[ix];
    throw( INDEX_OUT_OF_RANGE );
}

inline const Vector& Matrix::operator[]( int ix ) const
{
    if( ix >= 0 && ix < GetRowNo() ) return m_pVectors[ix];
    throw( INDEX_OUT_OF_RANGE );
}

inline void Matrix::createMatrix( int nRow, int nCol, int nElem )
{
    if( nRow < 2 ) nRow = 2;
    if( nCol < 2 ) nCol = 2;
    m_nRow = nRow;
    m_pVectors = new( nothrow ) Vector[nRow];
    if( !m_pVectors ) throw ( ALLOCATION_ERROR );
    for( int i = 0; i < nRow; i++ )
        m_pVectors[i] = Vector( nCol, nElem );
}

inline void Matrix::copyMatrix( const Matrix& m )
{
    for( int i = 0; i < GetRowNo(); i++ )
        m_pVectors[i] = m[i];
}

inline int Matrix::GetRowNo() const
{
    return m_nRow;
}

inline int Matrix::GetColNo() const
{
    return m_pVectors->getDim();
}

inline Matrix::operator Vector* ( ) const
{
    return m_pVectors;
}
