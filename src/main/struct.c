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

struct limits {
	unsigned int min;
	unsigned int max;
	bool overflow;
};

struct linklist {
	char name[25];
	unsigned int age;
	char sex[1];
	struct linklist * next;
};

void initArrays();
void initStruct( struct limits * );
void initFIFO();

int main( int argc, char** argv )
{
	initArrays();
	
	struct limits limits;
	limits.min = 0;
	limits.max = 0;
	limits.overflow = FALSE;
	
	initStruct( & limits );
	
	initFIFO();
}

void
initArrays()
{
	int array[2];
	array[0] = 12;
	array[1] = 21;
	printf( "Array [2]: \n" );
	printf( "\t%d", array[0] );
	printf( "\t%d \n", array[1] );
	
	int matrix[1][2];
	matrix[0][0] = 12;
	matrix[0][1] = 21;
	printf( "Matrix [1][2]: \n" );
	printf( "\t%d", matrix[0][0] );
	printf( "\t%d \n", matrix[0][1] );
	
	int matrix3d[1][2][1];
	matrix3d[0][0][0] = 12;
	matrix3d[0][1][0] = 21;
	printf( "Matrix3d [1][2][1]: \n" );
	printf( "\t%d", matrix3d[0][0][0] );
	printf( "\t%d \n", matrix3d[0][1][0] );
	
	int matrixMultiD[1][1][1][1][1][1][1][1][1][2];
	matrixMultiD[0][0][0][0][0][0][0][0][0][0] = 12;
	matrixMultiD[0][0][0][0][0][0][0][0][0][1] = 21;
	printf( "MatrixMultiD [1][1][1][1][1][1][1][1][1][2]: \n" );
	printf( "\t%d", matrixMultiD[0][0][0][0][0][0][0][0][0][0] );
	printf( "\t%d \n", matrixMultiD[0][0][0][0][0][0][0][0][0][1] );
	
	char Colours[3][6] = { "red", "green", "blue" };
	printf ( "Color [3][6]: \n" );
	printf ( "\t%s \n", Colours[0] );
	printf ( "\t%s \n", Colours[1] );
	printf ( "\t%s \n", Colours[2] );
}

void
initStruct( struct limits * limitsP )
{
	printf( "Structure (struct): \n");
	printf( "\t%d", (*limitsP).min );
	printf( "\t%d \n", limitsP -> max );
	printf( "\n");
	
	struct limits limits = * limitsP;
	limits.min = 12;
	limits.max = 1212;
	limits.overflow = TRUE;
	
	printf( "\t%d", limits.min );
	printf( "\t%d", limits.max );
	printf( "\t%d \n", limits.overflow );
	printf( "\n");
	
	struct limits array[] = 
	{
		{ 21, 2121, 'Y' },
		{ 12, 2121, 'Y' },
		{ 21, 1212, 'N' },
		{ 12, 1212, 'N' },
		{ -1, -1, 'x' }
	};
	
	int index;
	for ( index = 0 ; array[index].overflow != 'x' ; index++ )
		printf( "\t%d\t%d\t%c \n", array[index].min, array[index].max, array[index].overflow );
}

void
initFIFO()
{
	char* sexs[] = { "M", "F", "M", "" };
	int ages[] = { 23, 21, 34, 0 };
	char* names[] = { "Mark", "Alisha", "Jack", "" };	
	
	struct linklist * list = malloc( sizeof( struct linklist ) );
	struct linklist * nextP;
	nextP = list;
	
	int index;
	for ( index = 0 ; ages[index] != 0 ; index++ ) {
		(*nextP).next = (struct linklist *) malloc( sizeof( struct linklist ) );
		nextP = (*nextP).next;
			
		(*nextP).age = ages[index];
		strcpy( (*nextP).name, names[index] );
		strcpy( (*nextP).sex, sexs[index] );
	}
	
	(*nextP).next = NULL;
	nextP = list;
	
	printf( "Structure (FIFO): \n");	
	while ( nextP != NULL ) {
		printf("\t%s", (*nextP).name );
		printf("\t%s", (*nextP).sex );
		printf("\t%d \n", (*nextP).age );

		nextP = (*nextP).next;
	}
}
