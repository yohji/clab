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

int
socket_connect( char *host, in_port_t port )
{
	struct hostent *hp;
	struct sockaddr_in addr;
	int on = 1, sock;

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

	if ( connect( sock, (struct sockaddr *) &addr, sizeof(struct sockaddr_in) ) == -1 ) {
		perror( "connect" );
		exit( 1 );
	}

	return sock;
}

#define BUFFER_SIZE 1024

int main( int argc, char** argv )
{
	int sock;
	char buffer[BUFFER_SIZE];

	if ( argc < 3 ) {
		fprintf( stderr, "Usage: %s <hostname> <port>\n", argv[0] );
		exit( 1 );
	}

	sock = socket_connect( argv[1], atoi( argv[2] ) );
	write( sock, "GET /\r\n", strlen( "GET /\r\n" ) );
	bzero( buffer, BUFFER_SIZE);

	while ( read( sock, buffer, BUFFER_SIZE - 1 ) != 0 ) {
		fprintf( stderr, "%s", buffer );
		bzero( buffer, BUFFER_SIZE);
	}

	shutdown( sock, SHUT_RDWR);
	close( sock );

	return 0;
}
