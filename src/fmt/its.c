/*
 * Schism Tracker - a cross-platform Impulse Tracker clone
 * copyright (c) 2003-2004 chisel <someguy@here.is> <http://here.is/someguy/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "headers.h"

#include "title.h"

/* --------------------------------------------------------------------- */

bool fmt_its_read_info(const byte * data, size_t length, file_info * fi);
bool fmt_its_read_info(const byte * data, size_t length, file_info * fi)
{
	if (!(length > 80 && memcmp(data, "IMPS", 4) == 0))
		return false;

	fi->description = strdup("Impulse Tracker Sample");
	fi->extension = strdup("its");
	fi->title = calloc(26, sizeof(char));
	memcpy(fi->title, data + 20, 25);
	fi->title[25] = 0;
	fi->type = TYPE_SAMPLE;
	return true;
}
