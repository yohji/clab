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

#ifndef LIST_H_
#define LIST_H_

typedef struct {
	void *e;
	struct Entry *prev;
	struct Entry *next;
} Entry;

typedef struct {
	Entry *header;
	int size;
} List;

bool list_add( List*, void* );
bool list_add_all( List*, void** );
void list_clear( List* );
bool list_contains( List*, void* );
bool list_contains_all( List*, void** );
void* list_get( List*, int );
int list_index_of( List*, void* );
int list_last_index_of( List*, void* );
bool list_remove( List*, void* );
bool list_remove_all( List*, void** );
bool list_set( List*, int, void* );
List* list_sublist( List*, int, int );
void** list_toarray( List* );
char* list_tostring( List* );

#endif
