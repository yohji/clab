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

#define NUM_THREADS 5

void* printHello( void* );

int main( int argc, char** argv )
{
	pthread_t threads[NUM_THREADS];
	int rc, t;
	for ( t = 0; t < NUM_THREADS ; t++ ) {
		printf( "In main: creating thread %d\n", t );
		rc = pthread_create( &threads[t], NULL, printHello, (void *) t );
		if ( rc ) {
			printf( "ERROR; return code from pthread_create() is %d\n", rc );
			exit( -1 );
		}
	}
	pthread_exit( NULL);

	return 0;
}

void* printHello( void* threadid )
{
	int tid;
	tid = (int) threadid;
	printf( "Hello World! It's me, thread #%d!\n", tid );
	pthread_exit( NULL);
}
