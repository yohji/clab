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
#include <string.h>

struct libro {
   char titolo[100];
   char autore[50];
   char casa_ed[100];
   int anno, pagine;
   double prezzo;
};

struct point {
	double x;
	double y;
};

struct triangolo {
	struct point a, b, c;
};

union point_u {
	double x;
	double y;
};

struct bits {
	unsigned x;
	unsigned y;
};

typedef enum {
	FALSE, TRUE
} boolean;

void write_struct( void );
void read_struct( struct libro *l );
void build_triangolo( void );
struct point somma( struct point*, struct point* );
boolean compare( struct point*, struct point* );

int main( int argc, char **argv ) 
{
	// Invocazione delle funzioni
	write_struct();
	printf( "\n" );
	
	build_triangolo();
	printf( "\n" );
	
	struct point x = { 1.2, 2.1 };
	struct point y = { 2.1, 1.2 };
	struct point s = somma( &x, &y );
	printf( "Somma: %f %f\n", s.x, s.y );
	printf( "\n" );
	
	printf( "Compare: %d\n", compare( &x, &y ) );
	printf( "\n" );
	
	printf( "Dimensione struct: %d byte\n", sizeof(struct point) );
	printf( "Dimensione union: %d byte\n", sizeof(union point_u) );
}

// Popolamento di una struct
void write_struct( void )
{
	struct libro biografy = {
		"Biografy", 
		"Marco Merli",
		"Home",
		2008, 123,
		6.9
	};
	
	strcpy( biografy.titolo, "My biografy" );
	strcpy( biografy.casa_ed, "Home edition" );
	biografy.pagine = 321;
	
	read_struct( &biografy );
}
	
// Lettura di una struct
void read_struct( struct libro *l ) 
{
	printf( "Titolo: %s\n", (*l).titolo );
	printf( "Autore: %s\n", (*l).autore );
	printf( "Casa editrice: %s\n", (*l).casa_ed );
	printf( "Anno: %d\n", (*l).anno );
	printf( "Pagine: %d\n", (*l).pagine );
	printf( "Prezzo: %f\n", (*l).prezzo );
	printf( "Dimensione: %d byte\n", sizeof(struct libro) );
}

// Lettura di un triangolo
void build_triangolo( void )
{
	struct triangolo tr = {
		{ 1.2, -2.7 },
		{ 4.5, -5.7 },
		{ 8.3, -6.9 }
	};
	
	printf( "Triangolo:\n" );
	printf( "a: %f %f\n", tr.a.x, tr.a.y );
	printf( "b: %f %f\n", tr.b.x, tr.b.y );
	printf( "c: %f %f\n", tr.c.x, tr.c.y );
}

// Somma due punti
struct point somma( struct point *x, struct point *y )
{
	struct point somma;
  	somma.x = (*x).x + (*y).x;
  	somma.y = (*x).y + (*y).y;
  	
  	return somma;
}

// Confronta due struct
boolean compare( struct point *x, struct point *y )
{
	if ( ((*x).x == (*y).x) && ((*x).y == (*y).y) )
		return TRUE;
	
	return FALSE;
}
