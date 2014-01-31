/*
 *	Copyright (c) 2014 Marco Merli <yohji@marcomerli.net>
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software Foundation,
 *	Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ONE_GB ((long) 2 << 29)
#define TWO_GB ((long) 2 << 30)
#define FOUR_GB ((long) 2 << 31)
#define EIGHT_GB ((long) 2 << 32)


int main( int argc, char** argv )
{
	size_t mem_size = TWO_GB;
	printf( "Malloc %zu bytes.\n", mem_size );
	
	char * mem_area = malloc( mem_size );
	if ( ! mem_area ) {
		printf( "Malloc failed.\n" );
		return 1;
	}
	
	size_t i;
	for ( i = 0; i < mem_size; i++ )
		*(mem_area + i) = '+';
  
	free( mem_area );
  
	return 0;
}
