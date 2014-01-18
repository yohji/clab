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

#define DIM_X 3
#define DIM_Y 3

void fibonacci( int*, int );
void print_vector( int*, int );
void matrix( void );
void matrix_print( int matrix [DIM_X][DIM_Y] );
void matrix_traspone( int matrix [DIM_X][DIM_Y] );

int main ( void )
{
	// Invocazione delle funzioni
	const int size = 20;
	int series [size];
	fibonacci( series, size );
	printf( "Fibonacci\n");
	print_vector( series, size );
	printf( "\n" );
	
	matrix();
	printf( "\n" );
	
	return 0;
}

// Stampa di un vettore
void print_vector( int *vector, int size )
{
	int i = 0;
	for ( ; i < size ; i++ )
		printf( "%d\n", vector[i] );
}

// Serie di Fibonacci
void fibonacci( int *series, int size )
{
	series[0] = 0;
	series[1] = 1;
	
	int i = 2;
	for ( ; i < size ; i++ )
		series[i] = series[i - 1] + series[i - 2];
}

// Vettore bidimensionale
void matrix( void )
{
	int matrix [DIM_X][DIM_Y]; // = { {1,2,3,4}, {2,4,6,8}, {3,6,9,12} };
	int x, y;
	
	for ( x = 0 ; x < DIM_X ; x++ ) {
		for ( y = 0 ; y < DIM_Y ; y++ )
			matrix[x][y] = (x + 1) * (y + 1);
	}

	printf( "Matrice\n" );	
	matrix_print( matrix );
	printf( "\n" );

	matrix_traspone( matrix );
	matrix_print( matrix );
	printf( "\n" );
}

// Stampa di un vettore bidimensionale
void matrix_print( int matrix [DIM_X][DIM_Y] )
{
	int x, y;
	
	for ( x = 0 ; x < DIM_X ; x++ ) {
		for ( y = 0 ; y < DIM_Y ; y++ )
			printf( "%d ", matrix[x][y] );
		printf( "\n" );
	}
}

// Transposizione di un vettore bidimensionale
void matrix_traspone( int matrix [DIM_X][DIM_Y] )
{
	int x, y, tmp;
	
	for ( x = 0 ; x < DIM_X ; x++ ) {
		for ( y = 0 ; y < DIM_Y ; y++ ) {
			tmp = matrix[x][y];
			matrix[x][y] = matrix[y][x];
			matrix[y][x] = tmp;
		}
	}
}
