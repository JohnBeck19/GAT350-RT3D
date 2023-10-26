#include "Transform.h"
#include "Renderer/Gui.h"
namespace nc
{
	void Transform::ProcessGui()
	{
		ImGui::DragFloat3("Position", &position[0]);
		ImGui::DragFloat3("Rotation", &rotation[0]);
		ImGui::DragFloat3("Scale", &scale[0]);
	}

	void Transform::Read(const json_t& value)
	{
		//READ_DATA(value, position);
		//READ_DATA(value, rotation);
		//READ_DATA(value, scale);
	}
}
