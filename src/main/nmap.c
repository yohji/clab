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
#include <pthread.h>

#define PORT_SIZE 65536

int** ports[PORT_SIZE];

void* check_port( void* );
int socket_connect( char*, in_port_t );

int main( int argc, char** argv )
{
	if ( argc < 2 ) {
		fprintf( stderr, "Usage: %s <hostname>\n", argv[0] );
		exit( 1 );
	}

	pthread_t thread;
	int rc;

	rc = pthread_create( &thread, NULL, check_port, (void*) argv[1] );
	if ( rc ) {
		printf( "ERROR; pthread_create() is %d\n", rc );
		exit( -1 );
	}

	pthread_exit( NULL );

	return 0;
}

void*
check_port( void* ptr )
{
	char* address = (char*) ptr;
	printf( "Listening ports for address %s:\n", address );

	int cursor = 0;
	int port = 0;
	for ( ; port <= PORT_SIZE ; port++ ) {
		if ( socket_connect( address, port ) != -1 ) {
			ports[cursor] = (void*) port;
			printf( "* %d\n", port );
			cursor++;
		}
	}
}

int socket_connect( char *host, in_port_t port )
{
	struct hostent *hp;
	struct sockaddr_in addr;
	int on = 1, sock, fd;

	if ( (hp = gethostbyname( host )) == NULL ) {
		herror( "gethostbyname" );
		exit( 1 );
	}

	bcopy( hp->h_addr, &addr.sin_addr, hp->h_length );
	addr.sin_port = htons( port );
	addr.sin_family = AF_INET;
	sock = socket( PF_INET, SOCK_STREAM,IPPROTO_TCP);
	setsockopt( sock, IPPROTO_TCP, TCP_NODELAY, (const char *) &on, sizeof(int) );

	if ( sock == -1 ) {
		perror( "setsockopt" );
		exit( 1 );
	}

	fd = connect( sock, (struct sockaddr *) &addr, sizeof(struct sockaddr_in) );

	shutdown( sock, SHUT_RDWR);
	close( sock );

	return fd;
}
