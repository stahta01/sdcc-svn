/*-------------------------------------------------------------------------

  SDCCralloc.h - header file register allocation

                Written By -  Philipp Krause . pkk@spth.de (2012)
      M6809 conversion By  -  Tim Stahlhut . stahta01@gmail.com (2020)

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
   
   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!  
-------------------------------------------------------------------------*/

#ifndef SDCCRALLOC_H
#define SDCCRALLOC_H 1

#include "common.h"

#include "reg_index.h"

enum
{
  REG_PTR = 1,
  REG_GPR = 2,
  REG_CND = 4,
};

/* definition for the registers */
typedef struct reg_info
{
  short type;                   /* can have value 
                                   REG_GPR, REG_PTR or REG_CND */
  short rIdx;                   /* index into register table */
  char *name;                   /* name */
} reg_info;

extern reg_info m6809_regs[];

void m6809_assignRegisters (ebbIndex *);

void m6809SpillThis (symbol *sym, bool force_spill);
iCode *m6809_ralloc2_cc(ebbIndex *ebbi);

void m6809RegFix (eBBlock ** ebbs, int count);
#endif

