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

#include <stdbool.h>

#include "list.h"

#ifndef MAP_H_
#define MAP_H_

typedef struct _Map_Entry {
	int key;
	int in_use;
	void * data;
	// any_t data;
} Map_Entry;

typedef struct _Map {
	int table_size;
	int size;
	Map_Entry* data;
	short lock;
	// semaphore_t lock;
} Map;

bool map_add( Map*, long, void* );
void map_clear( Map* );
bool map_contains_key( Map*, long );
bool map_contains_value( Map*, void* );
void* map_get( Map*, long );
List* map_keys( Map* );
bool map_isempty( Map* );
bool map_remove( Map*, long );
bool map_put( Map*, long, void* );
char* map_tostring( Map* );
List* map_values( Map* );

#endif
