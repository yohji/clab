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

#include <stdbool.h>

#ifndef MATH_H_
#define MATH_H_

#define abs(n) ( (n < 0) ? n - (2 * n) : n )
#define max(m, n) ( (m > n) ? m : n )
#define min(m, n) ( (m < n) ? m : n )

void show_limits();
double power( int b, int e );
int htoi_hex( char* s );
int htoi_oct( char* s );
int htoi_bin( char* s );
int moltiplication( int a, int b );
void printb( uint n );

#endif
