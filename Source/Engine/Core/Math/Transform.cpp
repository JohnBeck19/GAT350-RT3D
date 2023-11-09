#include "Transform.h"
#include "Renderer/Gui.h"
namespace nc
{
	void Transform::ProcessGui()
	{
		ImGui::DragFloat3("Position", &position[0],0.1f);
		if (ImGui::DragFloat3("Rotation", &euler[0]))
		{
			rotation = EulerToQuaternion(euler);
		}
		ImGui::DragFloat3("Scale", &scale[0],0.1f);
	}

	void Transform::Read(const json_t& value)
	{
		READ_DATA(value, position);
		READ_DATA(value, scale);
		READ_NAME_DATA(value,"rotation", euler);
		rotation = EulerToQuaternion(euler);
	}
}
