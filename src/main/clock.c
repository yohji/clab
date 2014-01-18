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


void format_time( time_t* time )
{
    char* tb = malloc( sizeof(char) );
    char* ct = ctime( time );
    
    int i, tb_i = 0;
    for ( i = 11; i < 19; i++ )
        tb[tb_i++] = ct[i];
    tb[tb_i] = '\0';

    printf( "%s", tb );
    free( tb );
}

int main()
{
    time_t t;
    char* ct;
   
    time( &t );
    format_time( &t );

    for ( ; ; time(&t) ) {
        printf( "\b\b\b\b\b\b\b\b" );
        format_time( &t );
    }

    return 0;
}

