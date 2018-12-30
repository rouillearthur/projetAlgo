/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
/**
 * @author Arthur ROUILLÉ <arouille@ecole.ensicaen.fr>
 * @author Bastien HUBERT <bhubert@ecole.ensicaen.fr>
 * @version     1.0.0 - 2018-12-28
 *
 * @bug
 */
/**
 * @file histogram.h
 */

typedef struct cell * cell;
struct cell
{
  unsigned char B;
  int           freq;
  cell          next;
};

typedef struct cell *histo;

#ifndef __HISTOGRAM_H
#define __HISTOGRAM_H
#include "../MODULE_IMAGE/image.h"

/**
 * @param  
 * @param 
 * @return 
 */
cell create_cell(int B, cell next);


/**
 * @param  
 * @param 
 * @return 
 */
cell insert_cell(cell head, int B);


/**
 * @param  
 * @param 
 * @return 
 */
cell delete_list(cell list);


/**
 * @return 
 */
histo create_histo(void);


/**
 * @param  
 * @param 
 * @return 
 */
void init_histo(histo hist, image img);


/**
 * @param
 * @return 
 */
void delete_histo(histo hist);

#endif
