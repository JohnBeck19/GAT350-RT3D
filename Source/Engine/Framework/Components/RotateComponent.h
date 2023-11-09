#pragma once
#include "Component.h"
#include "Renderer/Program.h"

namespace nc
{
	class RotateComponent : public Component
	{
	public:
		CLASS_DECLARATION(RotateComponent)

		void Update(float dt) override;
		void ProcessGui() override;

	private:
		glm::vec3 euler{ 0 };
	};
}
