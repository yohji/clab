/*
 *	Copyright (c) 2013 Marco Merli <yohji@marcomerli.net>
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

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct {
	char ch;
	int count;
} chcount;

int main(int argc, char **argv)
{
	if (argc != 2) {
		strerror(EINVAL);
		return 1;
	}
	
	char *file_path = argv[1];
	FILE *file = fopen(file_path, "r");
	chcount **chcount_data = NULL;
	int ch, idx, new_el, size = 0;
	
	while ((ch = fgetc(file)) != EOF) {
		
		new_el = 1;
		for (idx = 0 ; idx < size ; idx++) {
			if (chcount_data[idx]->ch == ch) {
				chcount_data[idx]->count += 1;
				new_el = 0;
			}
		}

		if (new_el) {
			chcount_data = (chcount **) realloc(chcount_data, (size + 1) * sizeof(chcount *));
			chcount_data[size] = (chcount *) malloc(sizeof(chcount));
			chcount_data[size]->ch = ch;
			chcount_data[size]->count = 1;
			size++;
		}
	}
	
	for (idx = 0 ; idx < size ; idx++)
		printf("('%c', %d)\n", chcount_data[idx]->ch, chcount_data[idx]->count);
	
	free(chcount_data);
	fclose(file);
	
	return 0;
}
