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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	size_t size;
	char buffer [BUFSIZ];

	if ( (fd = open( "/dev/fd0", O_RDWR )) == 0 ) {
		perror( "Open error: " );
		exit(-1);
	}
	
	if ( (size = write( fd, "Marco", 5 )) == -1 ) {
		perror( "Write error: " );
		exit(-1);
	}

	lseek( fd, 0, SEEK_SET );
	if ( (size = read( fd, buffer, BUFSIZ )) == -1 ) {
		perror( "Read error: " );
		exit(-1);
	}

	printf( "%s\nSize: %d\n", buffer, size );
	close( fd );

	return 0;
}
