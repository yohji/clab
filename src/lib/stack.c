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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"


static Point* stack;
static int length;

void stack_push( Point* p )
{
	if ( stack == NULL )
		stack = malloc( sizeof(Point) );
	
	*(stack + length++) = *p;	
}

Point* stack_pop()
{
	if ( length == 0 )
		perror( "No such push committed" );

	return &( *(stack + --length) );
}

char* point_to_string( Point* p )
{
	char* string = malloc( sizeof(char) );
	sprintf( string, "[%e|%e]", p->x, p->y );
	
	return string;
}

Point point_from_string( char* p )
{
	Point point;
	char* buffer = malloc( sizeof(char) );
	int i, buffer_i;
	
	for ( i = 0, ++p; *(p + i) != '|'; i++ )
		*(buffer + i) = *(p + i);
	
	point.x = atof( buffer );
	memset( buffer, 0, sizeof(char) );
	
	for ( buffer_i = 0 ,++i; *(p + i) != ']'; i++ )
		*(buffer + buffer_i) = *(p + i);
	point.y = atof( buffer );
	
	return point;
}

void stack_print()
{
	int i;
	printf( "Stack {\n" );
	
	for ( i = 0 ; i < length ; i++ ) {
		Point p = *(stack + i);
		printf( "\t%s\n", point_to_string( &p ) );
	}
	
	printf( "}\n" );
}

void stack_clear()
{
	length = 0;
}
