/* 
A* -------------------------------------------------------------------
B* This file contains source code for the PyMOL computer program
C* copyright 1998-2000 by Warren Lyford Delano of DeLano Scientific. 
D* -------------------------------------------------------------------
E* It is unlawful to modify or remove this copyright notice.
F* -------------------------------------------------------------------
G* Please see the accompanying LICENSE file for further information. 
H* -------------------------------------------------------------------
I* Additional authors of this source file include:
-* 
-* 
-*
Z* -------------------------------------------------------------------
*/
#ifndef _H_Export
#define _H_Export

/* routines for packing pymol data into forms useful for other
 * python or C modules */

/* this is the base class for all these object
 * which provides for a deallocation method */

typedef struct Export {
  void (*fFree)(struct Export *ex);
} Export;

/*--------------------------------------------------------------------- */
typedef char ExportAtomType[5];

typedef struct { 
  Export export;
  float *point;
  float *normal;
  float *area;
  int *type;
  int *flag;
  int nPoint;
} ExportDotsObj;

void ExportDeleteMDebug(struct Export *ex); /* for mmalloc/mfree blocks */

void *ExportMMGet(char *name,int state);
int ExportMMUpdate(char *name,int state,void *mmdat);
void ExportMMFree(void *mmdat);

ExportDotsObj *ExportDots(char *sele,int coordSet);

/*--------------------------------------------------------------------- */

#endif



