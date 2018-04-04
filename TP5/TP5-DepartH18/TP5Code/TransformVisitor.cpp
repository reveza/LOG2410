#include "TransformVisitor.h"
#include "TransformStack.h"
#include "Objet3DTransform.h"
#include "Objet3DComposite.h"

void TransformVisitor::visit(Objet3DComposite & obj)
{
	// Si le composite a des enfants faire
	//    - Pousser la transformation sur la pile des transformations
	//    - Iterer sur les enfants et visiter chaque enfant
	//    - Eliminer la transformation poussee sur la pile
}

void TransformVisitor::visit(Objet3DTransform & obj)
{
	// Combiner la transformation contenue dans l'objet � la transformation courante
}
