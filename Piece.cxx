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
  if (p == nullptr) { // case vide
    return true;
  } else { // case pleine
    return p->isWhite() != isWhite(); // capture
  }
}