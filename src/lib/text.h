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

#ifndef TEXT_H_
#define TEXT_H_

#define IN 1
#define OUT 0

enum escapes {
	BELL = '\a',
	BACKSPACE = '\b',
	TAB = '\t',
	NEWLINE = '\n',
	VTAB = '\v',
	RETURN = '\r'
};

void text_info( char* text );
void format_space( char* text );
void text_reverse( char* text );
int strindex( char* s, char c );
char** strspt( char* s, int c );
bool isUpCharacter( int c );
bool isLowCharacter( int c );
bool isCharacter( int c );
void toLower( char* string );
void toUpper( char* string );


#endif /*TEXT_H_*/
