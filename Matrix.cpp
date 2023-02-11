#include "Matrix.h"

Matrix::Matrix( int nRow, int nCol, int nElem )
{
    try
    {
        createMatrix( nRow, nCol, nElem );
    }
    catch( VecException e )
    {
        e.getReason();
    }
}

Matrix::Matrix( const Matrix& m )
{
    m_nRow = 0;
    m_pVectors = nullptr;
    *this = m;
}

Matrix::~Matrix()
{
    delete[] m_pVectors;
}

Matrix& Matrix::operator=( const Matrix& m )
{
    if( GetRowNo() != m.GetRowNo() )
    {
        delete[] m_pVectors;
        try
        {
            createMatrix( m.GetRowNo(), m.GetColNo() );
        }
        catch( VecException e )
        {
            cout << e.getReason();
            return *this;
        }
    }
    copyMatrix( m );
    return *this;
}

const Vector operator*( const Matrix& m, const Vector& v )
{
    if( m.GetColNo() != v.getDim() ) throw VecException( INCOMATIBLE_SIZES );
    Vector res = Vector( m.GetRowNo() );
    for( int x = 0; x < m.GetRowNo(); x++ )
        res[x] = m[x] * v;
    return res;
}

const Matrix operator*( const Matrix& m1, const Matrix& m2 )
{
    if( m1.GetColNo() != m2.GetRowNo() ) throw VecException( INCOMATIBLE_SIZES );
    Matrix res = Matrix( m1.GetRowNo(), m2.GetColNo() );
    Matrix m2_T = m2.transposition();
    for( int x = 0; x < res.GetRowNo(); x++ )
        for( int y = 0; y < res.GetColNo(); y++ )
            res[x][y] = m1[x] * m2_T[y];
    return res;
}

bool operator==( const Matrix& m1, const Matrix& m2 )
{
    if( m1.GetRowNo() != m2.GetRowNo() || m1.GetColNo() != m2.GetColNo() ) return false;
    for( int i = 0; i < m1.GetRowNo(); i++ )
        for( int j = 0; j < m1.GetColNo(); j++ )
            if( m1[i][j] != m2[i][j] ) return false;
    return true;
}

bool operator!=( const Matrix& m1, const Matrix& m2 )
{
    return !( m1 == m2 );
}

ostream& operator<<( ostream& out, const Matrix& m )
{
    out << "\n{ ";
    for( int i = 0; i < m.GetRowNo(); i++ )
        out << m.m_pVectors[i] << ( ( i < m.GetRowNo() - 1 ) ? "\n  " : " }" );
    return out;
}

istream& operator>>( istream& in, Matrix& m )
{
    for( int i = 0; i < m.GetRowNo(); i++ )
        for( int j = 0; j < m.GetColNo(); j++ )
            in >> m[i][j];
    return in;
}

const Matrix Matrix::transposition() const
{
    Matrix res( GetColNo(), GetRowNo() );
    for( int i = 0; i < res.GetRowNo(); i++ )
        for( int j = 0; j < res.GetColNo(); j++ )
            res[i][j] = ( *this )[j][i];
    return res;
}
