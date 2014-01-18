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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>

#include "random.h"

long int next( void )
{
	struct timeb t;
	ftime( &t );
	seed = (long) t.millitm + seed;
	if ( seed > t.time )
		seed = t.millitm;

	srandom( seed );
	return random();
}

long int next_range( int range )
{
	long int r = next();
	int i = 1;
	while ( r > range - 1 ) {
		r /= i++;
		r -= 4;
		if ( r < 0 )
			r = abs( r );
	}

	return r;
}
