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

void code( int* elements, int deep, FILE* swap );

int main( int argc, char** argv )
{
	int elements[10];

	int i = 48;
	const int size = 58;
	for ( ; i < size; i++ )
		elements[i - 1] = i;

	FILE* swap = fopen( "/tmp/codes.list", "w+" );
	code( elements, 4, swap );
	fclose( swap );

	return 0;
}

void code( int* elements, int deep, FILE* swap )
{
	char buffer[deep + 1];

	int i = 0;
	for ( ; i < deep; i++ )
		buffer[i] = elements[i];
	buffer[++i] = '\0';

	fwrite( buffer, sizeof( buffer ), 1, swap );
	memset( buffer, 0, 0 );
}
