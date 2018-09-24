/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include "Echiquier.h"
//class Echiquier;

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece 
{
private:
  int m_x;
  int m_y;
  bool m_white;
  
public:
  Piece();
  Piece(int x, int y, bool white);
  ~Piece();
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  const Piece & plusForte(const Piece & p);
  virtual bool mouvementValide(Echiquier &e, int x, int y);
  virtual char name();
}; 

class Pion : public Piece 
{
public:
  Pion(int x, int y, bool white);
  //~Pion() {}
  bool mouvementValide( Echiquier & e, int x, int y );
  char name();
};

#endif // !defined Piece_h
