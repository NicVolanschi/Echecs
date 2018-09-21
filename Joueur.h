/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"

/**
 * Declaration d'une classe mod�lisant un joueur de jeu d'echec.
 */
class Joueur 
{
    bool m_white;
    Piece m_pieces[16];
 public:
    Joueur(bool white);
    void placer(Echiquier & e);
    void affiche();
};


#endif // !defined Joueur_h
