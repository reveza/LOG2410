///////////////////////////////////////////////////////////
//  Objet3DPart.cpp
//  Implementation of the Class Objet3DPart
//  Created on:      12-mars-2018 10:42:05
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DPart.h"

Objet3DPart::Objet3DPart(){

}

Objet3DPart::Objet3DPart(const Triangle & t)
	: m_triangles(1, t)
{
}

Objet3DPart::Objet3DPart(const Objet3DPart & mdd)
	: m_triangles(mdd.m_triangles)
{
}

Objet3DPart::~Objet3DPart(){

}

Objet3DPart * Objet3DPart::cloner(void) const
{
	// Construire et retourner un nouvel objet identique a this
	// A COMPLETER
	Objet3DPart* tmp = new Objet3DPart(*this);
	return tmp;
}

// Conteneur vide d'enfant pour simplifier l'�criture des methodes
// qui retournent des iterateurs
static Objet3DContainer empty_container;

// Les objets component ne gerent pas d'enfants, les methodes retournent
// des iterateurs sur le conteneur vide
Objet3DIterator Objet3DPart::begin()
{
	// Constuire et retourner un iterateur au debut du conteneur vide des objets enfants
	// A COMPLETER
	return ...;
}

Objet3DIterator Objet3DPart::end()
{
	// Constuire et retourner un iterateur apres la fin du conteneur vide des objets enfants
	// A COMPLETER
	return ...;
}

Objet3DIterator_const Objet3DPart::cbegin() const
{
	// Constuire et retourner un iterateur constant au debut du conteneur vide des objets enfants
	// A COMPLETER
	return ...;
}

Objet3DIterator_const Objet3DPart::cend() const
{
	// Constuire et retourner un iterateur constant apres la fin du conteneur vide des objets enfants
	// A COMPLETER
	return ...;
}

void Objet3DPart::addChild(const AbsObjet3D &)
{
	// Echoue silencieusement
}

Objet3DIterator_const Objet3DPart::removeChild(Objet3DIterator_const)
{
	// Echoue silencieusement
	// Constuire et retourner un iterateur constant apres la fin du conteneur vide des objets enfants
	// A COMPLETER
	return ...;
}

TriangleIterator Objet3DPart::triangle_begin()
{
	// Constuire et retourner un iterateur au debut du contenant des triangle
	// L'iterateur de fin doit egalement etre fourni pour construire l'iterateur sur les triangles
	// A COMPLETER
	return ...;
}

TriangleIterator Objet3DPart::triangle_end()
{
	// Constuire et retourner un iterateur apres la fin du contenant de triangle
	// L'iterateur de fin doit etre fourni 2 fois pour construire l'iterateur sur les triangles
	// A COMPLETER
	return ...;
}

TriangleIterator_const Objet3DPart::triangle_cbegin() const
{
	// Constuire et retourner un iterateur constant au debut du contenant des triangle
	// L'iterateur de fin doit egalement etre fourni pour construire l'iterateur sur les triangles
	// A COMPLETER
	return ...;
}

TriangleIterator_const Objet3DPart::triangle_cend() const
{
	// Constuire et retourner un iterateur constant apres la fin du contenant de triangle
	// L'iterateur de fin doit etre fourni 2 fois pour construire l'iterateur sur les triangles
	// A COMPLETER
	return ...;
}

void Objet3DPart::addTriangle(const Triangle & t)
{
	// Ajoute un nouveau triangle dans le conteneur des triangles
	// A COMPLETER
}

TriangleIterator_const Objet3DPart::removeTriangle(TriangleIterator_const iter)
{
	// Effacer le triangle pointe par l'iterateur dans le vecteur des triangles
	// retourner l'iterateur resultant de l'operation d'effacement
	// A COMPLETER
	return ...;
}
