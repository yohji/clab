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

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

 #define BUFFER_SIZE 1024
 
void append( char*, char* );

int main(int argc, char** argv)
{
	/*
	pid_t fork_pid = fork();
        time_t timeval = time( NULL );
        timeval = time( NULL );
        printf( "%.24s\n", ctime(&timeval) );

        printf( "pid: %d\n", getpid() );
	for (;;);
		
	printf( "\nEnd\n" );
	*/
	
	char *home = "/home/yohji/.geix";
	const char *path = "/portage.data";
	char dest[100] = {0};

	strcat( dest, home );
	strcat( dest, path );
	printf( "%s\n", dest );

	char* buffer = malloc( sizeof(char) );
	char* output = malloc( sizeof(char) );
	
	FILE* stream = popen( "cat /tmp/nohup.out", "r" );
	if ( stream != NULL ) {
		while ( fgets( buffer, sizeof(buffer), stream ) )
			strcat( output, buffer );
	}

	printf( "%s", output );
	free( buffer );	
	free( output );

	return 0;
}

void append( char *source, char *content )
{
	int offset = strlen( source );
	int i = 0;
	for ( ; *content != '\0' ; i++, offset++ )
		*(source + offset + i) = *(content + i);
}
