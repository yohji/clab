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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

#include "../lib/list.h"
#include "../lib/sort.h"
#include "../lib/random.h"
#include "../lib/math.h"
#include "../lib/time.h"
#include "../lib/temp.h"
#include "../lib/text.h"
#include "../lib/stack.h"
#include "../lib/list.h"

static long timer;

void test_list(void);
void test_sort(void);
void test_random(void);
void test_math(void);
void test_temp_conv();
void test_writer();
void test_point_stack();

int main(int argc, char** argv)
{
	printf( "Test List:\n" );
	test_list();
	
	printf( "\nTest Sort:\n" );
	test_sort();
	
	printf( "\nTest Random:\n" );
	test_random();
	
	printf( "\nTest Math:\n" );
	test_math();
	
	printf( "\nTest Temp Conv:\n" );
	test_temp_conv();
	
	printf( "\nTest Writer:\n" );
	test_writer();
	
	printf( "\nTest Point Stack:\n" );
	test_point_stack();
	
	return 0;
}

void test_list(void)
{
	List *l = malloc( sizeof(List) );	
	list_add( l, "Marco" );
	list_add( l, "Jenny" );
	list_add( l, "Carol" );
	list_add( l, "Stephany" );
	list_add( l, "Priscilla" );
	list_add( l, "Denny" );

	printf( "Size: %d\n", (*l).size );
	printf( "Get(3): %s\n", (char*) list_get(l, 3) );
	printf( "Contains(Stephany): %d\n", list_contains(l, "Stephany") );
	// printf( "String: %s\n", list_tostring(l) );

}

void test_sort(void)
{
	const int size = 10;
	double *list = malloc( sizeof(double) );
	int i = 0;
	for ( ; i < size ; i++ )
		list[i] = random();

	print( list );
	printf( "\n" );

	selection_sort( list, size );
	print( list );
}

void test_random(void)
{
	const int size = 53;
	char buffer [size];
	int ib = 0;

	int i = 65;
	for ( ; i < 91 ; i++ )
		buffer[ib++] = (char) i;
	for ( i = 97 ; i < 123 ; i++ )
		buffer[ib++] = (char) i;
	buffer[ib] = '\0';

	printf( "Buffer: %s\n", buffer );

	char key [20];
	for ( i = 0 ; i < 20 ; i++ ) {
		if ( i % 5 == 0 && i != 0 )
			key[i] = '-';
		else
			key[i] = buffer[next_range(size)];
	}
	key[i] = '\0';
	
	printf( "Key: %s\n", key );
}

void test_math(void)
{
	struct timeb time;
	ftime( &time );

	long t = time.millitm;
	int c = moltiplication( 123123, 123123 );
	ftime( &time );
	printf( "%d in %d\n", c, (time.millitm - t) );

	ftime( &time );
	t = time.millitm;
	c = 123123 * 123123;
	printf( "%d in %d", c, (time.millitm - t) );
	
	show_limits();
	
	int b = 12;
	int e = 2;
	printf("power %d^%d: %g\n", b, e, power(b, e) );
	
	char* n_bin = "1010011";
	printf("%s\t(bin -> int)\t%d\n", n_bin, htoi_bin( n_bin ) );
	char* n_oct= "0012";
	printf("%s\t(oct -> int)\t%d\n", n_oct, htoi_oct( n_oct ) );
	char* n_hex = "0xFF";
	printf("%s\t(hex -> int)\t%d\n", n_hex, htoi_hex( n_hex ) );
}

void test_temp_conv()
{
	float temp;
	printf( "Temperature: " );
	scanf( "%f", &temp );
	
	printf( "%.3f\tF=>C\t%.3f\n", temp, to_celsius(temp) );
	printf( "%.3f\tC=>F\t%.3f\n", temp, to_fahrenheit(temp) );
}

void test_writer()
{
	int i;
	char** split = strspt( "123|asd|456|zxc", '|' );
	for ( i = 0; *(split + i) != NULL; i++ )
		printf( "{%s}\n", *(split + i) );
	
	int read;
	i = 0;
	char* string = malloc( sizeof(char) );

	while ( (read = getchar()) != EOF ) {
		string[i++] = read;
		if ( read == '\n' )
			printf( ": " );
		else if ( read == '.' ) {
			string[i] = '\0';
			break;
		}
	}
	
	text_info( string );
	text_reverse( string );
	printf( "End at index %d\n", strindex(string, '.') );
	text_reverse( string );
}

void test_point_stack()
{
	Point p1 = { 1.32e3, -1.42e2 };
	stack_push( &p1 );
	Point p2 = { -1.78e3, -1.23e2 };
	stack_push( &p2 );
	stack_print();
	
	Point* pop = stack_pop();
	printf( "Pop: %s\n", point_to_string( pop ) );
	stack_print();
	
	Point p3 = point_from_string( "[1.54e4|-1.94e7]" );
	stack_push( &p3 );
	pop = stack_pop();
	printf( "Pop: %s\n", point_to_string( pop ) );
	stack_print();
	
	stack_clear();
	stack_print();
}
