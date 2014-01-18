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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main( int argc, char** argv )
{
	// Lettura file parametro
	char* path = argv[1];
	if ( path == NULL ) {
		printf( "File not specified\n" );
		exit( 1 );
	}

	// Apertura file
	char buffer[BUFFER_SIZE];
	FILE* file = fopen( path, "r" );

	// Letura data corrente
	char t[20];
	time_t timeval;
	timeval = time( NULL );
	snprintf( t, sizeof(t), "%.24s", ctime( &timeval ) );

	// Lettura file
	if ( file == NULL )
		perror( "Error opening file" );
	else {
		int count = 0;
		while ( feof( file ) == 0 ) {
			fgets( buffer, BUFFER_SIZE , file );
			printf( "%s", buffer );
			count++;
		}
		printf( "\n\nfile: %s (%d lines) - %s\n", path, count, t );
	}

	return 0;
}

