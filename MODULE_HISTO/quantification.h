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
 * @version     1.0.0 - 2019-01-09
 *
 * @bug
 */


/**
 * @file quantification.h
 */

#ifndef __QUANTIFICATION_H
#define __QUANTIFICATION_H

#include "../MODULE_IMAGE/image.h"
#include "./histogram.h"


/**
 * @param tabToSort est un tableau d'entiers contenant toutes les couleurs de l'image ainsi que leur fréquence
 * @param n est l'entier définissant la longueur du tableau d'entiers
 * @param max est le nombre maximal de valeurs que l'on veut voir triées (en pratique c'est 4K valeurs de retour). Il est compris entre 0 et n
 * @return On renvoie un tableau trié de longueur 4K (triplet pour la couleur et un nombre pour le nombre d'occurences
 */
int* tri(int* tabToSort, long n, long max);

    
/**
 * @param h est un histogramme precédemment calculé
 * @param tab est un tableau d'entiers représentant les K couleurs les plus fréquentes
 * @param K est l'entier définissant le nombre de couleurs par lequel on souhaite quantifier l'image 
 */
void quantification(histo h, int* tab, long K);


/**
 * @param input est la structure image d'entrée, dont on doit modifier pour la sous-échantilloner
 * @param output est la structure image de sortie, donc non initialisée 
 * @param tab est le tableau d'entier donnant les couleurs avec lesquelles ré-échantilloner l'image
 * @param K est le nombre de couleurs avec lesquelles ré-échantilloner l'image
 */
void mapping(image input, image output, int* tab, long K);

#endif
