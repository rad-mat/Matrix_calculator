#include "Vector.h"
#include "Matrix.h"

int main()
{
    Vector v1;
    cout << "Wektor 1 (z parametrow domyslnych): " << v1 << endl;
    Vector v2( 2, 1 );
    cout << "Wektor 2 (z parametrow podanych): " << v2 << endl;
    Vector v3( v1 );
    cout << "Wektor 3 (na wzor v1): " << v3 << endl;
    v3 = v2;
    cout << "Wektor 3 (przypisanie v2): " << v3 << endl;
    cout << "v3 == v2: " << boolalpha << (v3 == v2) << endl;
    cout << "v3 != v2: " << boolalpha << ( v3 != v2 ) << endl;

    cout << "wymiar v3: " << v3.getDim() << endl;
    cout << "operator(int*) np. v3[1]: " << ( (int*)v3 )[1] << endl;

    cout << "-v3: " << -v3 << endl;

    cout << "v3+v2: " << v3 + v2 << endl;
    cout << "v3+2: " << v3 + 2 << endl;
    cout << "3+v2: " << 3 + v3 << endl;
    v3 += v2; cout << "v3+=v2: " << v3 << endl;
    v3 += 2;  cout << "v3+=2: " << v3 << endl;

    cout << "v3-v2: " << v3 - v2 << endl;
    cout << "v3-2: " << v3 - 2 << endl;
    v3 -= v2; cout << "v3-=v2: " << v3 << endl;
    v3 -= 2;  cout << "v3-=2: " << v3 << endl;

    cout << "3*v2: " << 3 * v3 << endl;
    cout << "v3*2: " << v3 * 2 << endl;
    v3 *= 5; cout << "v3*=5: " << v3 << endl;

    cout << "v3*v2: " << v3*v2 << endl;

    Vector v5( 3, 0 );
    cout << "Podaj wspolrzedne trojwymiarowego wektora" << endl;
    cin >> v5;
    cout << "v5: " << v5 << endl;
    cout << "v5[1]: " << v5[1] << endl;
    (v5[1]) *= 5; cout << "v5[1]*=5: " << v5 << endl;
    

    Matrix m1;
    cout << "Macirz 1 (z parametrow domyslnych): " << m1 << endl;
    Matrix m2( 2, 3, 5 );
    cout << "Macierz 2 (z parametrow podanych): " << m2 << endl;
    Matrix m3( m1 );
    cout << "Macierz 3 (na wzor m1): " << m3 << endl;
    cout << "m3 == m2: " << boolalpha << ( m3 == m2 ) << endl;
    cout << "m3 != m2: " << boolalpha << ( m3 != m2 ) << endl;
    m3 = m2;
    cout << "Macierz 3 (przypisanie m2): " << m3 << endl;
    cout << "m3 == m2: " << boolalpha << ( m3 == m2 ) << endl;
    cout << "m3 != m2: " << boolalpha << ( m3 != m2 ) << endl;

    cout << "Liczba kolumn m3: " << m3.GetRowNo() << endl;
    cout << "Liczba wierszy m3: " << m3.GetColNo() << endl; 
    cout << "operator(Vector*) np. m3[1]: " << ( (Vector*)m3 )[1] << endl;
    
    try
    {
        Vector v6( 2, 2 );
        cout << "m3*v6: " << m3 * v6 << endl;
    }
    catch( VecException e )
    {
        e.getReason();
    }
    
    Vector v7( 3, 4 );
    cout << "m3: " << m3 << endl;
    cout << "v7: " << v7 << endl;
    cout << "m3*v7: " << m3 * v7 << endl;
    
    try
    {
        Matrix m4( 3, 2, 4 );
        cout << "m3: " << m3 << endl;
        cout << "m4: " << m4 << endl;
        cout << "m3*m4: " << m3 * m4 << endl;
    }
    catch( VecException e )
    {
        e.getReason();
    }

    Matrix m5( 3, 3 );
    cout << "Podaj wspolrzedne macierzy 3x3" << endl;
    cin >> m5;
    cout << "m5: " << m5 << endl;
    cout << "m5[1]: " << m5[1] << endl;
    ( m5[1] ) *= 5; cout << "m5[1]*=5: " << m5 << endl;

    return 0;
}
