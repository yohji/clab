/*
 *	Copyright (c) 2008 Marco Merli <yohji@marcomerli.net>
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 * 	This program is distributed in the hope that it will be useful,
 * 	but WITHOUT ANY WARRANTY; without even the implied warranty of
 * 	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * 	GNU General Public License for more details.
 *
 * 	You should have received a copy of the GNU General Public License
 * 	along with this program; if not, write to the Free Software Foundation,
 * 	Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdio.h>
#include <stdlib.h>

void unari( void );
void conversioni( void );
void aritmetica( void );
void swap( int*, int* );
int strlength( char* );
void alloc_dyna( void );
void pointer_to_pointer( void );
void matrix_dyna( void );

int main( int argc, char **argv ) 
{
	// Stampa degli argomenti
	int i = 0;
	printf( "Argomenti\n" );
	for ( ; *(argv + i) != NULL ; i++ )
		printf( "%s\n", *(argv + i) );
	printf( "\n" );
	
	// Invocazione delle funzioni
	unari();
	printf( "\n" );
	
	printf( "Conversioni\n" );
	conversioni();
	printf( "\n" );
	
	printf( "Aritmetica\n" );
	aritmetica();
	printf( "\n" );
	
	printf( "Swap\n" );
	int x = 1, y = 2;
	swap( &x, &y );
	printf( "\n" );
	
	printf( "Lughezza stringa\n" );
	char *str = "MarcoMerli";
	printf( "%d\n", strlength( str ) );
	printf( "\n" );
	
	printf( "Allocazione dinamica\n" );
	alloc_dyna();
	printf( "\n" );
	
	printf( "Puntatore al puntatore\n" );
	pointer_to_pointer();
	printf( "\n" );
	
	printf( "Matrice dinamica\n" );
	matrix_dyna();
	printf( "\n" );
}

// Operazioni con gli unari
void unari( void )
{
	int n = 12;
	int *pn = &n;
	printf( "Unari: %d\n", *pn + 8 );
}

// Conversioni dei puntatori
void conversioni( void )
{
	double x = 6.9, *px;
	int *y;
	
	px = &x;
	y = (int*) &x;
	
	printf( "%e\n", x );
	printf( "%p\t%p\n", px, y );
	printf( "%d\t%p\n", *y, y );
}

// Aritmetica dei puntatori
void aritmetica( void )
{
	double vector[4] = {1.1, 2.2, 3.3, 4.4};
	double *p;
	int i;

	p = &vector[0];
	for ( i = 0 ; i < 4 ; i++, p++ )
		printf( "%e\n", *p );
}

// Swappare due interi
void swap( int *x, int *y )
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
	
	printf( "%d %d\n", *x, *y );
}

// Calcola la lunghezza di una stringa
int strlength( char *str )
{
	int i = 0;
	for ( ; *str != '\0' ; str++, i++ );
	
	return i; 
}

// Allocazione dinamica
void alloc_dyna( void )
{
	int n = 0, *pn, i;
	pn = (int*) malloc( n * sizeof(int) );
	if ( pn == NULL ) {
		printf( "Not enough memory!\n" );
		exit( 1 );
	}

	for ( i = 0 ; i < 3 ; i++ ) {
    	printf( "%d numero: ", i + 1 );
    	scanf( "%d", pn + i );
  	}
  	
  	free( pn );
}

// Puntatori a puntatori
void pointer_to_pointer( void )
{
	int n = 12;
	int *pn, **ppn, ***pppn;
	
	pn = &n;
	ppn = &pn;
	pppn = &ppn;
	
	printf( "%d %d %d\n", *pn, **ppn, ***pppn );
	printf( "%p %p %p\n", pn, ppn, pppn );
}

void matrix_dyna( void )
{
	int x, y, lx = 3, ly = 3;
	int **matrix;
	
	matrix = (int**) malloc( lx * sizeof(int) );
	for ( x = 0 ; x < lx ; x++ )
		matrix[x] = (int*) malloc( ly * sizeof(int) );
		
	printf( "Size: %d byte\n", sizeof(matrix) );
		
	for ( x = 0 ; x < lx ; x++ )
		free( matrix[x] );
	free( matrix );
}
