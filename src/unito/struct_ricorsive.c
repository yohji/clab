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

typedef struct node {
	int value;
	struct node *prev;
	struct node *next;
} Node;

void populate( void );
Node* new( int );
Node* append( int, Node* );
Node* find( int, Node* );
void format_number( Node* );
void delete( int, Node* );

int main( int argc, char **argv ) 
{
	// Invocazione delle funzioni
	printf( "Popolamento nodi\n" );
	populate();
	printf( "\n" );
	
	printf( "Creazione nodo\n" );
	Node *header = new( 12 );
	printf( "\n" );
	
	printf( "Appendi nodo\n" );
	Node *n = append( 11, header );
	n = append( 21, n );
	append( 22, n );
	printf( "\n" );
	
	printf( "Cerca nodo\n" );
	n = find( 21, header );
	if ( n != NULL )
		printf( "Node trovato per valore 21\n" );
	printf( "\n" );
	
	printf( "Stampa nodi\n" );
	format_number( header );
	printf( "\n" );
	
	printf( "Delete nodo\n" );
	delete( 21, header );
	n = find( 21, header );
	if ( n == NULL )
		printf( "Nodo cancellato per valore 21\n" );
	printf( "\n" );
}

// Popolamento lista nodi
void populate( void )
{
	Node n1, n2, n3;
	
	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	
	n1.prev = NULL;
	n1.next = &n2;
	n2.prev = &n1;
	n2.next = &n3;
	n3.prev = &n2;
	n3.next = NULL;
}

// Creazione nodo
Node* new( int v )
{
	Node *n = (Node*) malloc( sizeof(Node) );
	if ( n == NULL )
		exit( 1 );
		
	(*n).value = v;
	(*n).prev = NULL;
	(*n).next = NULL;
	
	return n;
}

// Appendi nodo
Node* append( int v, Node* header )
{
	Node *n = new( v );
	(*n).prev = header;
	(*header).next = n;
	
	return n;
}

// Cerca nodo per valore
Node* find( int v, Node *header )
{
	Node *n = header;
	while ( n != NULL ) {
		if ( (*n).value == v )
			return n;
			
		n = (*n).next;
	}
	
	return n;
}

// Stampa catena nodi
void format_number( Node* header )
{
	Node *n = header;
	
	int i = 0;
	while ( n != NULL ) {
		printf( "%d=%d\n", ++i, (*n).value );
		n = (*n).next;
	}
}

// Cancella nodo per valore
void delete( int v, Node *header )
{
	Node *n = header;
	n = find( v, header );
	
	if ( (*n).next != NULL )
  		(*(*n).next).prev = (*n).prev;
	if ( (*n).prev != NULL )
		(*(*n).prev).next = (*n).next;
		
	free( n );
}
