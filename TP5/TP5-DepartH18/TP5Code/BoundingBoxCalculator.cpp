#include <limits>

#include "BoundingBoxCalculator.h"
#include "Objet3DPart.h"

BoundingBoxCalculator::BoundingBoxCalculator(void)
{
	// initialiser les bornes minimum aux plus grandes valeurs possibles
	// le float maximum est: std::numeric_limits<float>::max();
	m_boite[0] = std::numeric_limits<float>::max();  // xmin
	m_boite[2] = std::numeric_limits<float>::max();  // ymin
	m_boite[4] = std::numeric_limits<float>::max();  // zmin
	// initialiser les bornes maximum aux plus petites valeurs possibles
	// le float minimum est: std::numeric_limits<float>::min();
	m_boite[1] = std::numeric_limits<float>::min();  // xmax
	m_boite[3] = std::numeric_limits<float>::min();  // ymax
	m_boite[5] = std::numeric_limits<float>::min();  // zmax
}

void BoundingBoxCalculator::visit(Objet3DPart & obj)
{
	// Iterer sur tous les triangles contenus dans l'objet et faire:
	//    - Comparer les coordonnees des sommets des triangles aux bornes actuelle de la boite
	//    - Si une coordonnee est plus petite qu'une coordonnee min, faire:
	//         - stoker la nouvelle coordonnee min
	//    - Si une coordonnee est plus grande qu'une coordonnee max, faire:
	//         - stoker la nouvelle coordonnee max
	for (auto it = obj.triangle_cbegin(); it != obj.triangle_cend(); it++)
	{
		auto sommets = it->sommets();
		for (int i = 0; i < 3; i++)
		{
			auto coords = sommets[i].coords();
			if (coords[0] < m_boite[0])
				m_boite[0] = coords[0];
			else if (coords[0] > m_boite[1])
				m_boite[1] = coords[0];
			if (coords[1] < m_boite[2])
				m_boite[2] = coords[1];
			else if (coords[1] > m_boite[3])
				m_boite[3] = coords[1];
			if (coords[2] < m_boite[4])
				m_boite[4] = coords[2];
			else if (coords[2] > m_boite[5])
				m_boite[5] = coords[2];
		}
	}
}