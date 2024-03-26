#include "pch.h"
#include "RLAnimator.h"


BAKKESMOD_PLUGIN(RLAnimator, "Export animation", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void RLAnimator::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->registerCvar("animator_enabled", "0", "Enable Animator", true, true, 0, true, 1)
		.addOnValueChanged([this](std::string oldValue, CVarWrapper cvar) {
		cvar.getBoolValue() ? enabled = true : enabled = false;
			});

	cvarManager->registerCvar("carSpeed", "0", "Set the velocity of the car", true);
	if (enabled) {
		applyInput();
	}
}

void RLAnimator::applyInput() {
	CarWrapper car = gameWrapper->GetLocalCar();
	float speed = cvarManager->getCvar("carSpeed").getFloatValue();
}

void RLAnimator::Initialize()
{
	//Hook events
	gameWrapper->HookEvent("Function TAGame.Vehicle_TA.SetVehicleInput", std::bind(&RLAnimator::applyInput, this));
}
