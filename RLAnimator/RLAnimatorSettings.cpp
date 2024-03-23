#include "pch.h"
#include "RLAnimator.h"

void RLAnimator::RenderSettings() {
	ImGui::TextUnformatted("A really cool plugin");

	if (ImGui::Button("CamDistance")) {
		gameWrapper->Execute([this](GameWrapper* gw) {
			cvarManager->executeCommand("CameraDistance");
		});
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Set the Camera distance");
	}

	CVarWrapper enableCvar = cvarManager->getCvar("animator_enabled");
	if (!enableCvar) { return; }
	bool enabled = enableCvar.getBoolValue();
	if (ImGui::Checkbox("Enable Plugin", &enabled)) {
		enableCvar.setValue(enabled);
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Toggle Animator Plugin");
	}

	CVarWrapper distanceCvar = cvarManager->getCvar("animator_cam_distance");
	if (!distanceCvar) { return; }
	float distance = distanceCvar.getFloatValue();
	if (ImGui::SliderFloat("Distance", &distance, 0.0, 500.0)) {
		distanceCvar.setValue(distance);
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverText = "distance is " + std::to_string(distance);
		ImGui::SetTooltip(hoverText.c_str());
	}


}