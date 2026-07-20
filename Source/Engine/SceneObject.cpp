#pragma once

#include "SceneObject.h"
#include "Engine.h"

void bad::SceneObject::Draw() const
{
	g_engine.GetRenderer().DrawModel(m_model, m_transform);
}
