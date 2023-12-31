#pragma once
#include "Framework/World.h"
#include "Renderer/Renderer.h"
#include "Core/Math/Transform.h"
#include <glm/glm/glm.hpp>
#include <vector>

namespace nc
{
	class World06 : public World
	{

	public:
		bool Initialize() override;
		void Shutdown() override;
		void Update(float dt) override;
		void Draw(Renderer& renderer) override;

	private:
		float m_time;
		float m_speed = 5;

		float m_refraction{ 1 };
		glm::vec3 m_ambientLight{0.2f};

	

	};
}