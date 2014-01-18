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
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BACKLOG 10

int main( int argc, const char * argv[] )
{
	const int list_port = 1212;
	int list_fd, conn_fd;
	struct sockaddr_in serv_add;
	char buffer[80];
	time_t timeval;

	//creiamo la socket
	if ( (list_fd = socket( AF_INET, SOCK_STREAM, 0 )) < 0 ) {
		perror( "socket creation error" );
		exit( -1 );
	}

	//la funzione memset azzera la memoria riservata alla struttura serv_add
	memset( (void*) &serv_add, 0, sizeof(serv_add) );

	//inizializziamo la struttura in maniera opportuna
	serv_add.sin_family = AF_INET; //specifica che useremo il protocollo IPv4
	serv_add.sin_port = htons( list_port ); //specifichiamo la porta su cui si mette in ascolto il server
	//usiamo la htons per impostare il valore corretto in network byte order

	serv_add.sin_addr.s_addr = htonl( INADDR_ANY );

	//la funzione setsockopt permette di impostare delle opzioni per la socket che
	//si sta usando.
	//in particolare, questa chiamata alla funzione permette di riutilizzare la porta
	//della socket anche dopo che la connessione è stata chiusa.
	//senza la chiamata a questa funzione, alla chiusura della connessione la porta appena
	//usata non è momentaneamente disponibile, perchè risulta esser ancora allocata a livello kernel
	int yes = 1;
	if ( setsockopt( list_fd, SOL_SOCKET,SO_REUSEADDR, &yes, sizeof(int) ) < 0 ) {
		perror( "setsockopt" );
		exit( -1 );
	}

	//facciamo il binding della socket con la struttura che descrive l'indirizzo
	if ( bind( list_fd, (struct sockaddr*) &serv_add, sizeof(serv_add) ) < 0 ) {
		perror( "bind error" );
		exit( -1 );
	}

	//mettiamo il server in ascolto sulla socket
	if ( listen( list_fd, BACKLOG) < 0 ) {
		perror( "listen error" );
		exit( -1 );

	}

	//all'interno del ciclo while il server accetta le connessioni
	//la funzione 'accept' restituisce la socket su cui il server gestirà la connessione
	//col client
	while ( 1 ) {
		struct sockaddr_in tmp;
		unsigned int addrlen = sizeof(tmp);
		memset( (void*) &tmp, 0, sizeof(tmp) );
		if ( (conn_fd = accept( list_fd, (struct sockaddr*) NULL, NULL)) < 0 ) {
			perror( "accept error" );
			exit( -1 );
		}
		//la funzione getpeername permette di ottenere informazioni sul client
		//la funzione prende come argomenti la socket di connessione,
		//una struttura di tipo sockaddr_in e un puntatore alla dimensione
		//in bytes della struttura
		getpeername( conn_fd, (struct sockaddr*) &tmp, &addrlen );

		//attraverso la funzione inet_ntoa trasformiamo l'indirizzo del client in una stringa in notazione decimale puntata
		printf( "Client IP: %s\nClient port: %d\n", inet_ntoa( tmp.sin_addr ), tmp.sin_port );
		timeval = time( NULL );

		//il server calcola la data corrente e la manda al client attraverso la funzione write
		snprintf( buffer, sizeof(buffer), "%.24s\r\n", ctime( &timeval ) );

		//la funzione write prende come argomenti:
		//1) la socket di connessione
		//2) il buffer contenente le informazioni da trasmettere
		//3) la lunghezza del buffer in bytes

		//il secondo parametro della write è un void*
		if ( write( conn_fd, buffer, strlen( buffer ) ) < 0 ) {
			perror( "write error" );
			exit( -1 );
		}

		//chiudiamo la connessione
		close( conn_fd );
	}

	return 0;
}

