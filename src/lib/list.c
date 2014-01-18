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
#include <string.h>

#include "list.h"

Entry* scroll( List * l, int index )
{
	Entry * cursor = (*l).header;
	int i = 0;
	while ( (*cursor).next != NULL ) {
		if ( i++ == index )
			break;

		cursor = (*cursor).next;
	}

	if ( (*cursor).next == NULL )
		cursor = NULL;

	return cursor;
}

bool list_add( List * l, void * element )
{
	bool add = false;
	if ( l != NULL ) {
		Entry * cursor = (*l).header;
		if ( cursor == NULL ) {
			cursor = malloc( sizeof(Entry) );
			(*cursor).e = element;
			(*l).header = cursor;

		} else {
			while ( (*cursor).next != NULL )
				cursor = (*cursor).next;

			Entry * new = malloc( sizeof(Entry) );
			(*new).e = element;
			(*new).prev = cursor;
			(*new).next = NULL;
			(*cursor).next = new;
		}

		add = true;
		(*l).size += 1;
	}

	return add;
}

bool list_add_all( List * l, void ** elements )
{
	bool add = false;
	int i = 0;
	for ( ; *(elements + i) != NULL ; i++ ) {
		add = list_add( l, *(elements + i) );
		if ( !add )
			break;
	}

	return add;
}

void list_clear( List * l )
{
	if ( l != NULL ) {
		(*l).header = NULL;
		(*l).size = 0;
	}
}

bool list_contains( List * l, void * element )
{
	bool contains = false;
	if ( l != NULL ) {
		Entry * cursor = (*l).header;
		while ( cursor != NULL ) {
			if ( (*cursor).e == element ) {
				contains = true;
				break;
			}

			cursor = (*cursor).next;
		}
	}

	return contains;
}

bool list_contains_all( List * l, void ** elements )
{
	bool contains = false;
	int i = 0;
	for ( ; *(elements + i) != NULL ; i++ ) {
		contains = list_contains( l, *(elements + i) );
		if ( !contains )
			break;
	}

	return contains;
}

void* list_get( List * l, int index )
{
	void * get = NULL;
	if ( l != NULL ) {
		Entry * e = scroll( l, index );
		if ( e != NULL )
			get = (*e).e;
	}

	return get;
}

bool list_set( List * l, int index, void * element )
{
	bool set = false;
	if ( l != NULL ) {
		Entry * e = scroll( l, index );
		if ( e != NULL ) {
			(*e).e = element;
			set = true;
		}
	}

	return set;
}

void** list_toarray( List * l )
{
	void ** array = NULL;
	if ( l != NULL ) {
		array[(*l).size];
		int i = 0;
		for ( ; i < (*l).size ; i++ )
			array[i] = list_get( l, i );
	}

	return array;
}

char* list_tostring( List * l )
{
	char * string = malloc( sizeof(char) );
	strcat( string, "[" );

	if ( l != NULL ) {
		Entry * cursor = (*l).header;
		while ( cursor != NULL ) {
			strcat( string, (*cursor).e );
			if ( (*cursor).next != NULL )
				strcat( string, ", " );

			cursor = (*cursor).next;
		}
	}

	strcat( string, "]" );
	return string;
}
