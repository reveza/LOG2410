#include "OutputVisitor.h"
#include "Objet3DPart.h"
#include "Objet3DComposite.h"
#include "Objet3DTransform.h"

void OutputVisitor::visit(Objet3DPart & obj)
{
	// Imprimer tous les triangles contenus dans l'objet
	// Chaque triangle est imprime selon le format
	// "T#: (x, y, z) | (x, y, z) | (x, y, z)"
	// ou: # est le numero du triangle a partir de 0
	//     (x, y, z) sont les coordonnees d'un sommet
	int i = 0;

	for (auto it = obj.triangle_cbegin(); it != obj.triangle_cend(); it++, i++)
	{
		m_stream << m_indent << "T" << i;
		m_stream << ":";
		m_stream << it->s1();
		m_stream << " | ";
		m_stream << it->s2();
		m_stream << " | ";
		m_stream << it->s3() << std::endl;
	}


}

void OutputVisitor::visit(Objet3DComposite & obj)
{
	// Imprimer tous les enfants de l'objet
	// Si le composite a des enfants faire:
	//    - incrementer le niveau d'indentation de 3 espaces
	//    - invoquer le visiteur sur chaque enfant
	//    - decrementer le niveau d'indentation
	m_indent += "   ";
	m_stream << m_indent << "COMPOSITE:" << std::endl;
	for (Objet3DIterator it = obj.begin(); it != obj.end(); it++)
	{
		it->accueillir(*this);
	}
	m_indent = m_indent.substr(0, m_indent.length() - 3);
}

void OutputVisitor::visit(Objet3DTransform & obj)
{
	// Imprimer les attributs de la transformation selon le format:
	// "TRANSFO [dx, dy, dz]"
	// ou : dx, dy et dz sont les composantes de la transformation
	m_stream << m_indent << "TRANSFO [";
	m_stream << obj.dx();
	m_stream << ", ";
	m_stream << obj.dy();
	m_stream << ", ";
	m_stream << obj.dz();
	m_stream << "]" << std::endl;
}
