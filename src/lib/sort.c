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
#include "sort.h"

void selection_sort( double *list, const int size )
{
	int i = 0;
	for ( ; i < size ; i++ ) {
		double min = list[i];
		int iMin = i;

		int ii = i + 1;
		for ( ; ii < size ; ii++ ) {
			if ( list[ii] < min ) {
				min = list[ii];
				iMin = ii;
			}
		}

		if ( iMin != i ) {
			double tmp = list[i];
			list[i] = list[iMin];
			list[iMin] = tmp;
		}
	}
}

void merge_sort( double *list, const int size )
{
	double *sort = malloc( sizeof(double) );
	if ( size <= 1 )
		sort[0] = list[0];
	else {
		const int size_first = size / 2;
		const int size_second = size - size_first;
		double first[size_first];
		double second[size_second];
		int i = 0;

		for ( ; i < size_first ; i++ )
			first[i] = list[i];
		i = 0;
		for ( ; i < size_second ; i++ )
			second[i] = list[size_first + i];

		merge_sort( first, size_first );
		merge_sort( second, size_second );
		list = merge( first, second, size_first, size_second );
	}
}

double* merge( double *a, double *b, const int la, const int lb )
{
	double *merge = malloc( sizeof(double) );
	const int size = la + lb;
	int i = 0;
	int ia = 0;
	int ib = 0;

	for ( ; i < size ; i++ ) {
		if ( ia == la )
			merge[i] = b[ib++];
		else {
			if ( ib == lb )
				merge[i] = a[ia++];
			else {
				if ( a[ia] > b[ib] )
					merge[i] = b[ib++];
				else
					merge[i] = a[ia++];
			}
		}
	}

	return merge;
}

int len( double *list )
{
	int i = 0;
	for ( ; list[i] != 0 ; i++ )
		;

	return i + 1;
}

void print( double *list )
{
	int i = 0;
	for ( ; list[i] != 0 ; i++ )
		printf( "%g\n", list[i] );
}

