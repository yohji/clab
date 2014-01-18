/*
 *	Copyright (c) 2009 Marco Merli <yohji@marcomerli.net>
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
#include "text.h"


void text_info( char* text )
{
	int c, i, state = OUT; 
	int ch_n = 0, ln_n = 0, ws_n = 0, wd_n = 0;

	for ( i = 0 ; ( c = *(text + i) ) != 0 ; i++ ) {
		ch_n++;
		if ( c == '\n' )
			ln_n++;
		else if ( c == ' ' )
			ws_n++;
			
		if ( c == ' ' || c == '\t' || c == '\n' )
			state = OUT;
		else if ( state == OUT ) {
			state = IN;
			wd_n++;
		}
	}
	
	printf( "%s\n", text );
	printf( "\n%d characters\n", --ch_n );
	printf( "%d words\n", wd_n );
	printf( "%d lines\n", ln_n );
	printf( "%d whitespaces\n", ws_n );
}

void format_space( char* text )
{
	int c, i, last = -1;
	for ( i = 0 ; ( c = *(text + i) ) != 0 ; i++ ) {
		if ( c == ' ' && last == ' ' )
			continue;
		
		putchar( c );
		last = c;
	}
}

void text_reverse( char* text )
{
	int l, i;
	for ( l = 0 ; *(text + l) != 0 ; l++ );
	for ( i = l ; i >= 0 ; i-- )
		putchar( *(text + i) );
}

int strindex( char* s, char c )
{
	int i;
	for ( i = 0 ; *(s + i) != 0 ; i++ ) {
		if ( s[i] == c )
			break;
	}
	
	return i;
}

char** strspt( char* s, int c )
{
	char** list = malloc( sizeof(char) );
	char* buffer = malloc( sizeof(char) );
	int buffer_i = 0, list_i = 0;
	int i, read;
	
	for ( i = 0; (read = *(s + i)) !=  '\0'; i++ ) {
		if ( read == c ) {
			list[list_i++] = buffer;
			memset( buffer, 0, buffer_i * sizeof(char) );
			buffer_i = 0;
		} else
			*(buffer + buffer_i++) = read;
	}
	list[list_i] = buffer;
	
	return list;
}
