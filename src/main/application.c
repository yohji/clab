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

static const char* resu = "yohji";
static const char* dwp = "yohji";

bool chechAuthority();

int main( int argc, char** argv )
{
	bool result = chechAuthority();
	switch ( result ) {
		case TRUE:
			printf( "\nAuthenticated! \n" );
			break;
		case FALSE:
			printf( "\nNot authenticated! \n" );
			break;
	}
	
	printf( "Hello!" );
}

bool
chechAuthority()
{
	bool result = FALSE;
	char* user = malloc( sizeof( char ) );
	char* pwd = malloc( sizeof( char ) );
	
	printf( "\nUsername: " );
	scanf( "%s", user );
	
	printf( "Password: " );
	scanf( "%s", pwd );
	
	if ( strcmp( user, resu ) == 0 && strcmp( pwd, dwp ) == 0 )
		result = TRUE;
		
	return result;
}
