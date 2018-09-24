/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Piece.h"

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
  cout << "Piece construite" << endl;
}

Piece::Piece(int x, int y, bool white)
{
  cout << "Piece construite a" << x << y << white << endl;
  init(x, y, white);
}

Piece::~Piece()
{
  cout << "Piece detruite" << endl;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool 
Piece::isBlack() const
{
  return !m_white;
}

void 
Piece::affiche() const
{
  cout << "Piece: x=" << x() << " y=" << y() << " "
       << ( isWhite() ? "blanche" : "noire" ) << endl;
    
}

const Piece &
Piece::plusForte(const Piece & p)
{
  if(p.x() > x() && p.y() > y()) 
    return p;
  else return *this;
}

//Piece* Echiquier::getPiece( int x, int y );

bool Piece::mouvementValide(Echiquier &e, int x, int y)
{
  Piece *p = e.getPiece(x, y);
  if (x == this->x() && y == this->y())
    return false;
  if (p == nullptr) { // case vide
    return true;
  } else { // case pleine
    return p->isWhite() != isWhite(); // capture
  }
}

char Piece::name() 
{
  return isWhite()? 'B' : 'N';
}

// Code des sous-classes de Piece

bool Pion::mouvementValide( Echiquier & e, int x, int y )
{
  return Piece::mouvementValide(e, x, y);
}

char Pion::name()
{
  return isWhite()? 'P': 'p';
}

char Tour::name()
{
  return isWhite()? 'T': 't';
}

bool Tour::mouvementValide( Echiquier & e, int x, int y )
{
  if (!Piece::mouvementValide(e, x, y) ||
      (x != this->x() && y != this->y()))
      return false;
    if (x == this->x()) {
      for (int i = this->y() + 1; i < y; i++) {
        if (e.getPiece(x, i) != nullptr)
          return false;
      }
      return true;
    } else { // y == this->y()
      for (int i = this->x() + 1; i < x; i++) {
        if (e.getPiece(i, y) != nullptr)
          return false;
      }
      return true;
    }
}

char Cavalier::name()
{
  return isWhite()? 'C': 'c';
}

bool Cavalier::mouvementValide( Echiquier & e, int x, int y )
{
  return Piece::mouvementValide(e, x, y);
}

char Fou::name()
{
  return isWhite()? 'F': 'f';
}

bool Fou::mouvementValide( Echiquier & e, int x, int y )
{
  return Piece::mouvementValide(e, x, y);
}

char Reine::name()
{
  return isWhite()? 'D': 'd';
}

bool Reine::mouvementValide( Echiquier & e, int x, int y )
{
  return Piece::mouvementValide(e, x, y);
}

char Roi::name()
{
  return isWhite()? 'R': 'r';
}

bool Roi::mouvementValide( Echiquier & e, int x, int y )
{
  return Piece::mouvementValide(e, x, y);
}
