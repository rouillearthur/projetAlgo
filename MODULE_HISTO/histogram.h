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

#ifndef __HISTOGRAM_H
#define __HISTOGRAM_H

#include "../MODULE_IMAGE/objet.h"
#include "../MODULE_IMAGE/classe.h"
#include "../MODULE_IMAGE/point.h"
#include "../MODULE_IMAGE/move_type.h"
#include "../MODULE_IMAGE/image.h"

typedef struct cell * cell;
struct cell
{
  unsigned char B;
  int           freq;
  cell          next;
};

typedef struct cell ***histo;

typedef struct histo_iter * histo_iter;
struct histo_iter
{
	int R,G;
	cell current;
};
typedef enum {false,true} boolean;

/**
 * Alloue dynamiquement une cellule en initialisant les champs B et next. Le champ freq est initialisé à 1.
 * @param B Intensité du bleu compris entre 0 et 255 d'un pixel donné
 * @param next Cellule suivante
 * @return Retourne la cellule contenant B de fréquence 1 et le pointeur vers la cellule suivante
 */
cell create_cell(int B, cell next);


/**
 * Ajoute une cellule contenant B avec la fréquence 1 si B n'est pas présent dans la liste head. 
 * Incrémente la fréquence de la cellule contenant B si celle ci existe. 
 * @param head Pointeur sur la liste chainée
 * @param B Intensité du bleu compris entre 0 et 255 d'un pixel donné
 * @return Retourne la liste head modifiée
 */
cell insert_cell(cell head, int B);


/**
 * Supprime toute les cellules d'une liste en libérant la mémoire.
 * @param list Pointeur sur la liste chainée
 * @return Retourne une liste vide.
 */
cell delete_list(cell list);


/**
 * Alloue dynamiquement un tableau de taille 256x256 dont chaque entrée est initialisée au pointeur NULL.
 * @return Histogramme initialisé
 */
histo create_histo(void);


/**
 * Initialise un histogramme à partir d'une image.
 * @param histo histogramme
 * @param img image
 */
void init_histo(histo hist, image img);


/**
 * Parcours l'ensemble des cellules du tableau histo et efface toutes les listes allouées. Elle supprime également le tableau histo.
 * @param hist histogramme
 */
void delete_histo(histo hist);

/**
 * @param h histogramme 
 * @param R composante rouge
 * @param G composante verte
 * @param B composante bleue
 * @return Renvoie le nombre de pixels de couleur (R;G;B) dans l'image associée à histo.
 */
int give_freq_histo(histo h, int R, int G, int B);

/**
 * Alloue une structure de type histo iter.
 * @return Itérateur
 */
histo_iter create_histo_iter();

/**
 * Positionne l'itérateur à la position qu'il avait à sa création
 * @param histo Itérateur
 */
void start_histo_iter(histo_iter *histo);

/**
 * @param histo Itérateur
 * @return VRAI s'il existe une prochaine liste histo[R][G] ou si on n'est pas en fin de liste selon le sens de lecture haut->droite et haut->bas. FAUX sinon. 
 */
boolean next_histo_iter(histo_iter histo);

/**
 * @param histo Itérateur 
 * @param pixel tableau de 3 entiers contenant la composante RGB du pixel
 */
void give_color_histo_iter(histo_iter histo, int* pixel);

/**
 * @param histo Itérateur
 * @return Renvoie la fréquence de la couleur courante de l'itérateur.
 */
int give_freq_histo_iter(histo_iter histo);

/**
 * @param histo Itérateur
 */
void delete_histo_iter(histo_iter histo);

#endif