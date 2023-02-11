#pragma once
#include <iostream>
#include <memory.h>
using namespace std;

#define VERROR 0x00
#define INDEX_OUT_OF_RANGE 0x01
#define ALLOCATION_ERROR 0x02
#define INCOMATIBLE_SIZES 0x04

typedef unsigned short int USSHORT;
class VecException
{
public:
    VecException( USSHORT errCode );
    const char* getReason();
private:
    USSHORT m_ErrCode;
};

inline VecException::VecException( USSHORT errCode = VERROR )
{
    m_ErrCode = errCode;
}

inline const char* VecException::getReason()
{
    switch( m_ErrCode )
    {
    //case VERROR:                return "ERROR: Vector error!\n";
    case INDEX_OUT_OF_RANGE:    return "ERROR: Index out of range!\n";
    case ALLOCATION_ERROR:      return "ERROR: Allocation error!\n";
    case INCOMATIBLE_SIZES:     return "ERROR: Incompatible sizes!\n";
    default:                    return "Vector error!\n";
    }
}

class Vector
{
public:
    Vector( int nDim = 2, int nElem = 0 );
    Vector( const Vector& v );
    virtual ~Vector();
    Vector& operator=( const Vector& v );

    int getDim() const;
    operator int* () const;

    // unary minus
    friend const Vector operator-( const Vector& v );

    // addition
    friend const Vector operator+( const Vector& v1, const Vector& v2 );
    friend const Vector operator+( const Vector& v, int x );
    friend const Vector operator+( int x, const Vector& v );
    Vector& operator +=( const Vector& v );
    Vector& operator +=( int x );

    // substraction
    friend const Vector operator-( const Vector& v1, const Vector& v2 );
    friend const Vector operator-( const Vector& v, int x );
    Vector& operator -=( const Vector& v );
    Vector& operator -=( int x );

    // multiplication
    friend const Vector operator*( const Vector& v, int x );
    friend const Vector operator*( int x, const Vector& v );
    Vector& operator *=( int x );

    // scalar multiplication
    friend int operator*( const Vector& v1, const Vector& v2 );

    // comparison
    friend bool operator==( const Vector& v1, const Vector& v2 ); 
    friend bool operator!=( const Vector& v1, const Vector& v2 );

    // indexation
    int& operator[]( int x );               // v[1] = 2;
    const int& operator[]( int x ) const;   // int x = v[3];

    // io
    friend ostream& operator<<( ostream& out, const Vector& v );
    friend istream& operator>>( istream& out, Vector& v );

private:
    int* m_pCoord;
    int m_nDim; 
    void createVector( int nDim );
    void copyVec( const Vector& v );
};

inline int Vector::getDim() const
{
    return m_nDim;
}
inline Vector::operator int*( ) const
{
    return m_pCoord;
}

inline void Vector::createVector( int nDim )
{
    if( nDim < 2 ) nDim = 2;
    m_nDim = nDim;
    m_pCoord = new( nothrow ) int[nDim];
    if( !m_pCoord ) throw ( ALLOCATION_ERROR );
}

inline void Vector::copyVec( const Vector& v )
{
    memcpy( m_pCoord, (int*)v, sizeof( int ) * v.getDim() );
}

// indexation
inline int& Vector::operator[]( int ix )             
{
    if( ix >= 0 && ix < getDim() ) return m_pCoord[ix];
    throw( INDEX_OUT_OF_RANGE );
}
inline const int& Vector::operator[]( int ix ) const 
{
    if( ix >= 0 && ix < getDim() ) return m_pCoord[ix];
    throw( INDEX_OUT_OF_RANGE );
}