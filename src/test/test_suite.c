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

void all_list_test( CU_pSuite );
void all_random_test( CU_pSuite );

int main( void )
{
	CU_pSuite suite = CU_add_suite( "clab-test-suite", NULL, NULL );
	all_list_test( suite );
	all_random_test( suite );

	CU_run_suite( suite );
	return 0;
}

void all_list_test( CU_pSuite suite )
{
        /*
	CU_add_test( suite, "test_list_add", test_list_add() );
	CU_add_test( suite, "testListAddAll", testListAddAll() );
	CU_add_test( suite, "testListClear", testListClear() );
	CU_add_test( suite, "testListContains", testListContains() );
	CU_add_test( suite, "testListContainsAll", testListContainsAll() );
	CU_add_test( suite, "testListGet", testListGet() );
	CU_add_test( suite, "testListIndexOf", testListIndexOf() );
	CU_add_test( suite, "testListLastIndexOf", testListLastIndexOf() );
	CU_add_test( suite, "testListRemove", testListRemove() );
	CU_add_test( suite, "testListRemoveAll", testListRemoveAll() );
	CU_add_test( suite, "testListSet", testListSet() );
	CU_add_test( suite, "testListSubList", testListSubList() );
	CU_add_test( suite, "testListToArray", testListToArray() );
	CU_add_test( suite, "testListToString", testListToString() );
	*/
}

void all_random_test( CU_pSuite suite )
{
        /*
	CU_add_test( suite, "test_random_next", test_random_next() );
	CU_add_test( suite, "test_random_next_range", test_random_next_range() );
         */
}