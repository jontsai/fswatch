/*
 * Copyright (c) 2015 Enrico M. Crisostomo
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifdef HAVE_CONFIG_H
#  include "libfswatch_config.h"
#endif

#include "cevent.h"
#include <cstring>
#include "libfswatch_mem.h"
#include "../c++/event.hpp"
#include "../c++/libfswatch_exception.hpp"

using namespace std;
using namespace fsw;

FSW_STATUS fsw_get_event_flag_by_name(const char *name, fsw_event_flag *flag)
{
  try
  {
    *flag = event::get_event_flag_by_name(name);

    return FSW_OK;
  }
  catch (const libfsw_exception& ex)
  {
    return FSW_ERR_UNKNOWN_VALUE;
  }
}

char *fsw_get_event_flag_name(const fsw_event_flag flag)
{
  string name = event::get_event_flag_name(flag);
  char *cstr = static_cast<char *>(fsw_alloc(name.size() + 1));

  if (cstr == nullptr) return nullptr;

  strcpy(cstr, name.c_str());

  return cstr;
}
