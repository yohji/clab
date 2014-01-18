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
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main( void )
{
	pid_t pid;
	int rv;

	switch ( pid = fork() ) {
		case -1:
			perror( "fork" ); /* something went wrong */
			exit( 1 ); /* parent exits */

		case 0:
			printf( " CHILD: This is the child process!\n" );
			printf( " CHILD: My PID is %d\n", getpid() );
			printf( " CHILD: My parent's PID is %d\n", getppid() );
			printf( " CHILD: Enter my exit status (make it small): " );
			scanf( " %d", &rv );
			printf( " CHILD: I'm outta here!\n" );
			exit( rv );

		default:
			printf( "PARENT: This is the parent process!\n" );
			printf( "PARENT: My PID is %d\n", getpid() );
			printf( "PARENT: My child's PID is %d\n", pid );
			printf( "PARENT: I'm now waiting for my child to exit()...\n" );
			wait( &rv );
			printf( "PARENT: My child's exit status is: %d\n", WEXITSTATUS( rv ) );
			printf( "PARENT: I'm outta here!\n" );
	}
}
