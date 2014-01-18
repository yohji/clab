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

#include <CUnit/CUnit.h>
#include "../lib/list.h"

void test_list_add( void )
{
	List * l = malloc( sizeof(List) );	
	list_add( l, "Marco" );
	list_add( l, "Jenny" );
	list_add( l, "Carol" );
	list_add( l, "Stephany" );
	list_add( l, "Priscilla" );
	list_add( l, "Denny" );
	
	CU_ASSERT( 0 != (*l).size );
	CU_ASSERT( strcmp( "Carol", (char*) list_get(l, 3) ) );
	CU_ASSERT( list_contains(l, "Stephany") );
	CU_ASSERT( list_tostring(l) != NULL );
}

void test_list_add_all( void ) {}
void test_list_clear( void ) {}
void test_list_contains( void ) {}
void test_list_contains_all( void ) {}
void test_list_get( void ) {}
void test_list_index_of( void ) {}
void test_list_remove( void ) {}
void test_list_remove_all( void ) {}
void test_list_set( void ) {}
void test_list_sublist( void ) {}
void test_list_toarray( void ) {}
void test_list_tostring( void ) {}
