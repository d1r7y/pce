/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:     src/lib/cmd.h                                              *
 * Created:       2003-11-08 by Hampa Hug <hampa@hampa.ch>                   *
 * Last modified: 2003-12-20 by Hampa Hug <hampa@hampa.ch>                   *
 * Copyright:     (C) 2003 by Hampa Hug <hampa@hampa.ch>                     *
 *****************************************************************************/

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/

/* $Id: cmd.h,v 1.3 2003/12/20 11:43:30 hampa Exp $ */


#ifndef PCE_LIB_CMD_H
#define PCE_LIB_CMD_H 1


#define PCE_CMD_MAX 256


typedef struct {
  unsigned i;
  char     str[PCE_CMD_MAX];
} cmd_t;


typedef int (*cmd_match_sym_f) (cmd_t *cmd, unsigned long *ret);


void cmd_get (cmd_t *cmd);
void cmd_set_str (cmd_t *cmd, const char *str);
void cmd_rewind (cmd_t *cmd);
const char *cmd_get_str (cmd_t *cmd);
int cmd_match_space (cmd_t *cmd);
void cmd_error (cmd_t *cmd, const char *str);
int cmd_match_str (cmd_t *cmd, char *str, unsigned max);
int cmd_match_eol (cmd_t *cmd);
int cmd_match_end (cmd_t *cmd);
int cmd_match (cmd_t *cmd, const char *str);
int cmd_match_ulng (cmd_t *cmd, unsigned long *val, unsigned base);
int cmd_match_uint16b (cmd_t *cmd, unsigned short *val, unsigned base);
int cmd_match_uint16 (cmd_t *cmd, unsigned short *val);
int cmd_match_uint32b (cmd_t *cmd, unsigned long *val, unsigned base);
int cmd_match_uint32 (cmd_t *cmd, unsigned long *val);
int cmd_match_uint16_16 (cmd_t *cmd, unsigned short *seg, unsigned short *ofs);
void cmd_init (FILE *inp, FILE *out, cmd_match_sym_f sym);


#endif
