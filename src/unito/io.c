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

void format_number( void );
void format_string( void );
void file_write( void );
void file_read( void );
void file_binary( void );
void file_seek( void );

int main( int argc, char **argv ) 
{
	// Invocazione delle funzioni
	printf( "Formattazione numeri\n" );
	format_number();
	printf( "\n" );
	
	printf( "Formattazione stringe\n" );
	format_string();
	printf( "\n" );
	
	printf( "Scrivi su file\n" );
	file_write();
	printf( "\n" );
	
	printf( "Leggi da file\n" );
	file_read();
	printf( "\n" );
	
	printf( "Leggi e scrivi bytes\n" );
	file_binary();
	printf( "\n" );
	
	printf( "File seek\n" );
	file_seek();
	printf( "\n" );
}

// Formattazione numeri
void format_number( void )
{
	double n = 123.123;
	
	printf( "d %d\n", n );
	printf( "i %i\n", n );
	printf( "f %f\n", n );
	printf( "e %e\n", n );
	printf( "g %g\n", n );
	printf( "o %o\n", n );
	printf( "x %x\n", n );
	printf( "p %p\n", n );
	
	printf( ".7 %.7f\n", n );
	printf( ".2 %.2f\n", n );
}

// Formattazione stringe
void format_string( void )
{
	char *str = "MarcoMerli";
	
	printf( "%s\n", str );
	printf( "<%20s>\n", str );
	printf( "%.5s\n", str );
}

// Scrivi su file
void file_write( void ) 
{
	FILE *f = fopen( "tmp", "w" );
	if ( f == NULL ) {
		printf( "IO error\n" );
		exit( 1 );
	}

	fprintf( f, "MarcoMerli\n" );
	fclose( f );
}

// Leggi da file
void file_read( void ) 
{
	FILE *f = fopen( "tmp", "r" );
	if ( f == NULL ) {
		printf( "IO error\n" );
		exit( 1 );
	}

	while ( !feof( f ) ) {
		char *buffer = malloc( sizeof(char) );
		fscanf( f, "%s", buffer );
		printf( "%s\n", buffer );
		free( buffer );
	}
	
	fclose( f );
}

// Scrivi e leggi bytes su/da file
void file_binary( void )
{
	double x = 1.3, xx;
	long int y = 100, yy;
	FILE *f = fopen( "tmp", "wb+" );
	if ( f == NULL ) {
		printf( "IO error\n" );
		exit( 1 );
	}
	
	fwrite( &x, sizeof(double), 1, f );
	fwrite( &y, sizeof(long int), 1, f );
	
	rewind( f );
	fread( &xx, sizeof(double), 1, f );
	fread( &yy, sizeof(long int), 1, f );
	printf( "xx: %f, yy: %ld\n", xx, yy );
	
	fclose( f );
}

// Seek su file
void file_seek( void )
{
	FILE *f;
	int i;
	if ( (f=fopen("tmp","wb+")) == NULL ) {
		printf( "IO error\n" );
		exit(0);
	}

	for ( i=1 ; i <= 10 ; i++ )
		fwrite( &i, sizeof(int), 1, f );
	
	fseek( f, 3 * sizeof(int), SEEK_SET );
	fread( &i, sizeof(int), 1, f );
	printf( "%d ", i );
	     
	fseek( f, 4 * sizeof(int), SEEK_CUR );
	fread( &i, sizeof(int), 1, f );
	printf( "%d ", i );
	
	fseek( f, -4 * sizeof(int), SEEK_END );
	fread( &i, sizeof(int), 1, f );
	printf( "%d\n", i );
}
