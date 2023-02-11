#include "Vector.h"

int mult( int* p1, int* p2, int size );

Vector::Vector( int nDim, int nElem )
{
    try
    {
        createVector( nDim );
        for( int i = 0; i < getDim(); i++ )
            m_pCoord[i] = nElem;
    }
    catch( VecException e )
    {
        e.getReason();
    }
}

Vector::Vector( const Vector& v )
{
    m_nDim = 0;
    m_pCoord = nullptr;
    *this = v;
}

Vector::~Vector()
{
    delete[] m_pCoord;
}

Vector& Vector::operator=( const Vector& v )
{
    if( getDim() != v.getDim() )
    {
        delete[] m_pCoord;
        try
        {
            createVector( v.getDim() );
        }
        catch( VecException e )
        {
            cout << e.getReason();
            return *this;
        }
    }
    copyVec( v );
    return *this;
}

// unary minus
const Vector operator-( const Vector& v )
{
    Vector res( v );
    for( int i = 0; i < v.getDim(); i++ )
        res.m_pCoord[i] = -res.m_pCoord[i];
    return res;
}

// addition
const Vector operator+( const Vector& v1, const Vector& v2 )
{
    Vector res( v1 );
    return res += v2;
}
const Vector operator+( const Vector& v, int x )
{
    Vector res( v );
    return res += x;
}
const Vector operator+( int x, const Vector& v )
{
    return v + x;
}
Vector& Vector::operator +=( const Vector& v )
{
    if( getDim() != v.getDim() ) throw( INCOMATIBLE_SIZES );
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] += v.m_pCoord[i];
    return *this;
}
Vector& Vector::operator +=( int x )
{
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] += x;
    return *this;
}

// substraction
const Vector operator-( const Vector& v1, const Vector& v2 )
{
    return v1 + ( -v2 );

}
const Vector operator-( const Vector& v, int x )
{
    return v + ( -x );
}
Vector& Vector::operator -=( const Vector& v )
{
    return *this += -v;
}
Vector& Vector::operator -=( int x )
{
    return *this += -x;
}

// multiplication
const Vector operator*( const Vector& v, int x )
{
    Vector res( v );
    return res *= x;
}
const Vector operator*( int x, const Vector& v )
{
    return v * x;
}
Vector& Vector::operator *=( int x )
{
    for( int i = 0; i < getDim(); i++ )
        m_pCoord[i] *= x;
    return *this;
}

// scalar multiplication
int operator*( const Vector& v1, const Vector& v2 )
{
    return mult( (int*)v1, (int*)v2, v1.getDim() );
}

// comparison
bool operator==( const Vector& v1, const Vector& v2 )
{
    if( v1.getDim() != v2.getDim() ) return false;
    for( int i = 0; i < v1.getDim(); i++ )
        if( v1[i] != v2[i] ) return false;
    return true;
}
bool operator!=( const Vector& v1, const Vector& v2 )
{
    return !( v1 == v2 );
}

// io
ostream& operator<<( ostream& out, const Vector& v ) 
{
    out << '[';
    for( int i = 0; i < v.getDim(); i++ )
        out << v.m_pCoord[i] << ( ( i < v.getDim() - 1 ) ? ',' : ']' );
    return out;
}
istream& operator>>( istream& in, Vector& v )
{
    for( int i = 0; i < v.getDim(); i++ )
        in >> v.m_pCoord[i];
    return in;
}

int mult( int* p1, int* p2, int size )
{
    int res = 0;
    for( int i = 0; i < size; i++ )
        res += *p1++ * *p2++;
    return res;
}