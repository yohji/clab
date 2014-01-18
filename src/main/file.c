/*
 *	Copyright (c) 2007 Marco Merli <yohji@marcomerli.net>
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
#include <malloc.h>
#include <string.h>
#include <ctype.h>

typedef enum { 
	TRUE = 1,
	FALSE = 0
} bool;

/*
 * I/O stream mode:	
 	"a"	 w	 append
	"a+" rw	 append
	"r"	 r	 reading
	"r+" rw	 reading
	"w"	 w	 no append
	"w+" rw	 no append
*/

void initRW();
void initRead();

int main( int argc, char** argv )
{
	initRW();
	initRead();
}

void
initRead()
{
	FILE* file = fopen( "/tmp/complex.text", "r" );
	char* content = malloc( sizeof( char ) );
	
	do {
		fscanf( file, "%s", content );	
	} while ( feof( file ) );
	
	int index = 0;
	for ( index = 0 ; *(content + index) != 0 ; index++ )
		printf( "%c",*(content + index) );

	printf( "\n\n" );
}

void
initRW()
{
	FILE* file;
	char* content = malloc( sizeof( char ) );
	
	file = fopen( "/tmp/hello.text", "w" );
	
	fputs( "y", file );
	fputs( "o", file );
	fputs( "h", file );
	fputs( "j", file );
	fputs( "i", file );
	fprintf( file, "marco" );
	fputs( "m", file );
	fputs( "e", file );
	fputs( "r", file );
	fputs( "l", file );
	fputs( "i", file );
	
	fclose( file );
	
	file = fopen( "/tmp/hello.text", "r" );
	
	printf( "%c", getc( file ) );
	printf( "%c", getc( file ) );
	printf( "%c", getc( file ) );
	printf( "%c", getc( file ) );
	printf( "%c \n", getc( file ) );

	fscanf( file, "%s", content );
	
	int index = 0;
	for ( index = 0 ; *(content + index) != 0 ; index++ )
		printf( "%c",*(content + index) );
	
	printf( "\n\n" );
		
	fclose( file );
}
