#include <stdlib.h>
#include <stdio.h>

void swap( int* x, int* y )
{
    asm( "xor %%ebx, %%eax;" : : "a"(*x), "b"(*y) );
    asm( "xor %eax, %ebx;" );
    asm( "xor %%ebx, %%eax;" : "=a"(*x), "=b"(*y) );
}

int main( int argc, const char** argv )
{
    int x, y;
   
    if ( argc < 3 ) { 
        printf( "x=" );
        scanf( "%d", &x );
        printf( "y=" );
        scanf( "%d", &y );
    } else {
        x = atoi( argv[1] );
        y = atoi( argv[2] );
    }

    printf( "x=%d. y=%d\n", x, y );
    swap( &x, &y );
    printf( "x=%d. y=%d\n", x, y );
    
    return 0;
}

