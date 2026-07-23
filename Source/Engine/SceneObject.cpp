#pragma once

#include "SceneObject.h"
#include "Engine.h"

void bad::SceneObject::Draw() const
{
	Engine::Get().GetRenderer().DrawModel(m_model, m_transform);
}
