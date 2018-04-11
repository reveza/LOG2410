#include "TransformStack.h"
#include "Objet3DTransform.h"

// Instancier le vecteur de stockage des transformations
std::vector<std::unique_ptr<Objet3DTransform>> TransformStack::m_transforms;

Objet3DTransform & TransformStack::getCurrent(void)
{
	// Si la pile de transformation est vide faire
	//    - Pousser une transformation vide sur la pile
	// Retourner la derniere transformation de la pile
	if (m_transforms.empty())
		m_transforms.push_back(std::make_unique<Objet3DTransform>());

	return *m_transforms.back().get();
}

void TransformStack::pushCurrent(void)
{
	// Si la pile de transformation n'est pas vide faire
	//    - Pousser la dernière transformation sur la pile
	// Sinon faire
	//    - Pousser une transformation vide sur la pile
	Objet3DTransform current = getCurrent();

	if (m_transforms.size() > 1)
		m_transforms.push_back(std::make_unique<Objet3DTransform>(current));
}

void TransformStack::push(const Objet3DTransform & t)
{
	// Pousser la transformation recue en parametre sur la pile
	m_transforms.push_back(std::make_unique<Objet3DTransform>(t));
}

void TransformStack::pop(void)
{
	// Si la pile n'est pas vide faire
	//    - Retirer la derniere transformation de sur la pile
	if (!m_transforms.empty())
		m_transforms.pop_back();
}