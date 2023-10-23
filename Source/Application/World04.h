#pragma once
#include "Framework/World.h"
#include "Renderer/Renderer.h"
#include "Core/Math/Transform.h"
#include <glm/glm/glm.hpp>
#include <vector>
namespace nc
{
	class World04 : public World
	{
	public:
		bool Initialize() override;
		void Shutdown() override;
		void Update(float dt) override;
		void Draw(Renderer& renderer) override;

	private:
		float m_time;
		float m_speed = 5;

		glm::vec3 m_lightPosition;
		glm::vec3 m_lightColor = glm::vec3(1, 1, 1);
		glm::vec3 m_ambientLight;

		Transform m_transform;
		
		res_t<Model> m_model;
		res_t<VertexBuffer> m_vertexBuffer;
		res_t<Program> m_program;
		res_t<Material> m_material;
		res_t<Texture> m_texture;

	};
}