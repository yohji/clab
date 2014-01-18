/*
 *	Copyright (c) 2009 Marco Merli <yohji@marcomerli.net>
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

#include <limits.h>
#include <float.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "math.h"

void show_limits()
{
	printf( "Type limits:\n" );
	printf( "\tchar max: %d\n", CHAR_MAX );
	printf( "\tunsigned char max: %d\n", UCHAR_MAX );
	printf( "\tshort max: %d\n", SHRT_MAX );
	printf( "\tunsigned short max: %d\n", USHRT_MAX );
	printf( "\tint max: %d\n", INT_MAX );
	printf( "\tunsigned int max: %g\n", (double) UINT_MAX );
	printf( "\tlong max: %li\n", LONG_MAX );
	printf( "\tunsigned long max: %g\n", (double) ULONG_MAX );
	printf( "\tfloat max: %g\n", FLT_MAX );
	printf( "\tfloat exp max: %d\n", FLT_MAX_EXP );
	printf( "\tdouble max: %g\n", DBL_MAX );
	printf( "\tdouble exp max: %d\n", DBL_MAX_EXP );
}

double power( int b, int e )
{
	double r = 1;
	int i;
	
	for ( i = 0 ; i < e ; i++ )
		r *= b;
		
	return r;  
}

static int htoi( char* s, int b )
{
	if ( b == 8 ) {
		if (*s++ != '0' )
			perror( "String is not a octal numer" );
	} else if ( b == 16 ) {
		if (*s++ != '0' || (*s != 'x' && *s != 'X') )
			perror( "String is not a hexdecimal numer" );
		s++;
	}
	
	int n, r  = 0;
	int i , j;
	
	for ( i = 0, j = strlen( s ) - 1 ; s[i] != '\0' ; i++, j-- ) {
		if ( s[i] == 'A' || s[i] == 'a' )
			n = 10;
		else if ( s[i] == 'B' || s[i] == 'b' )
			n = 11;
		else if ( s[i] == 'C' || s[i] == 'c' )
			n = 12;
		else if ( s[i] == 'D' || s[i] == 'd' )
			n = 13;
		else if ( s[i] == 'E' || s[i] == 'e' )
			n = 14;
		else if ( s[i] == 'F' || s[i] == 'f' )
			n = 15;
		else
			n = s[i] - '0';
	
		r += n * power(b, j);
	}
		
	return r;
}

int htoi_bin( char* s )
{
	return htoi( s, 2 );
}

int htoi_oct( char* s )
{
	return htoi( s, 8 );
}

int htoi_hex( char* s )
{
	return htoi( s, 16 );
}


void printb( uint n )
{
	int i, b, c;

	b = sizeof(n);
	for ( i = (b * 8) - 1; i >= 0 ; i-- ) {
		c = (1 << i);

		if ( n & c )
			printf( "1" );
		else
			printf( "0" );
	}

	printf( "\n" );
}

int moltiplication( int a, int b )
{
	printb( a );
	printb( b );

	int c = 0;
	while ( b != 0 ) {
		if ( (b & 1) != 0 )
			c += a;
		a = a << 1;
		printb( a );
		b = b >> 1;
		printb( b );
	}

	printb( c );
	return c;
}
