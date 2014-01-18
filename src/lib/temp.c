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

#include "temp.h"


double to_celsius( double temp_f )
{
	if ( temp_f < ABSOLUTE_ZERO_F ) {
		perror("Temperature under absolute zero");
		return 0;
	}
	
	return (5.0 / 9) * (temp_f - 32);
}

double to_fahrenheit( double temp_c )
{
	if ( temp_c < ABSOLUTE_ZERO_C ) {
		perror("Temperature under absolute zero");
		return 0;
	}
	
	return ( (9.0 / 5) * temp_c ) + 32;
}
