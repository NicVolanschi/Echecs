/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include <vector>
#include "Piece.h"
#include "Echiquier.h"

/**
 * Declaration d'une classe mod�lisant un joueur de jeu d'echec.
 */
class Joueur 
{
    bool m_white;
    std::vector<Piece *> m_pieces;
protected:
    Joueur();
    ~Joueur();
    void init(bool white);
 public:
    void placer(Echiquier & e);
    void affiche();
    virtual int foo() = 0;
    bool supprimerPiece(Piece *p);
};

class JoueurBlanc : public Joueur
{
public: 
    JoueurBlanc();
    int foo() { return 1; }
};

class JoueurNoir : public Joueur
{
public: 
    JoueurNoir();
    int foo() { return 2; }    
};

#endif // !defined Joueur_h
