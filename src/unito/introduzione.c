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

double sum( void );
int fact( int );
void pp( void );
void try_change_value( int );
void change_value( int* );
char* read( void );

int main( void )
{
	// Invocazione delle funzioni
	printf( "Somma: %1.4f\n", sum() );
	printf( "\n" );
	
	printf( "Fattoriale: %d\n", fact( 12 ) );
	printf( "\n" );
	
	pp();
	printf( "\n" );
	
	int n = 12;
	try_change_value( n );
	printf( "Value: %d\n", n );
	change_value( &n );
	printf( "Reference: %d\n", n );
	printf( "\n" );
	
	char* str = read();
	printf( "Scan: %s\n", str );
	free( str );
	
	return 0;
}

// Somma di due floating point
double sum( void ) 
{
	double x = 1.2;
	double y = 2.3;
	
	return x + y;
}

// Fattoriale di n
int fact( int n )
{
	if ( n <= 1 )
		return 1;
		
	return n * fact( n - 1 );
}

// Puntatore al puntatore
void pp( void )
{
	int n = 12;
	int* p = &n;
	int** pp = &p;

	printf( "Puntatori: %d %p %p\n", n, p, pp );
}

// Passaggio per value
void try_change_value( int n )
{
	n = 21;
}

// Passaggio per reference
void change_value( int *n )
{
	*n = 21;
}

// Lettura da tastiera
char* read( void )
{
	char* buffer = malloc( sizeof(char) );
	scanf( "%s", buffer );
	
	return buffer;
}
