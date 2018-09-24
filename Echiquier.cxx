/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include "Piece.h"

using namespace std;

/**
 * Constructeur par d�faut.
 * Initialise � vide l'echiquier.
 */
Echiquier::Echiquier()
{
	for (int i = 0; i < 64; i++)
		m_cases[i] = nullptr;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* 
Echiquier::getPiece( int x, int y )
{
	return m_cases[indexCase(x, y)];
}

  
/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool 
Echiquier::placer( Piece* p )
{
	if (p == nullptr || getPiece(p->x(), p->y()) != nullptr ||
		!caseValide(p->x(), p->y())) {
		return false;
		}
	m_cases[indexCase(p->x(), p->y())] = p;
	return true;
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y. 
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool 
Echiquier::deplacer( Piece* p, int x, int y )
{
	if (p == nullptr || m_cases[indexCase(x, y)] != nullptr ||
		!caseValide(x, y) || m_cases[indexCase(p->x(), p->y())] != p) {
		return false;
	}
	m_cases[indexCase(p->x(), p->y())] = nullptr;
	p->move(x, y);
	m_cases[indexCase(x, y)] = p;
	return true;
}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* 
Echiquier::enleverPiece( int x, int y )
{

	Piece *p = getPiece(x, y);
	if (p == nullptr)
		return nullptr;
	m_cases[indexCase(x, y)] = nullptr;
	return p;
}


/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void
Echiquier::affiche()
{
  cout << endl << "  ABCDEFGH" << endl;
  for ( int y = 8; y >= 1; --y )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; ++x )
	{
	  char c;
	  Piece* p = getPiece( x, y );
	  if ( p == 0 ) 
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
	  else
	    c = p->name();
	  cout << c;
	}
      cout << " " << y << endl;
    }
  cout << "  ABCDEFGH" << endl;
}

  

