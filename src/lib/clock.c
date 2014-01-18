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
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include "clock.h"


long current_time()
{
	time_t tp;
	time( &tp );
	
	return tp;	
}

double current_time_millis()
{
	char* buffer = malloc( sizeof(char) );
	struct timeb t;
	double time;
    
    ftime( &t );
    sprintf( buffer, "%ld.", (long) t.time );
    sprintf( buffer, "%s%d", buffer, t.millitm );

    time = atof( buffer );
    free( buffer );
    
    return time;
}
