#include "pch.h"
#include "RLAnimator.h"

void RLAnimator::RenderSettings() {
	ImGui::TextUnformatted("Move your car");

    CVarWrapper enableCvar = cvarManager->getCvar("animator_enabled");
    if (!enableCvar) { return; }
    if (ImGui::Button("Enable")) {
        enableCvar.setValue(true);
    }
    ImGui::SameLine();
    if (ImGui::Button("Disable")) {
        enableCvar.setValue(false);
    }

}