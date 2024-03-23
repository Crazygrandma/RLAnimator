#include "pch.h"
#include "RLAnimator.h"


BAKKESMOD_PLUGIN(RLAnimator, "Export animation", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void RLAnimator::onLoad()
{
	_globalCvarManager = cvarManager;
	LOG("Plugin loaded!");
	cvarManager->registerCvar("animator_cam_distance", "200.0", "Distance to move the camera away");

	cvarManager->registerCvar("animator_enabled", "0", "Enable the animator", true, true, 0, true, 1)
		.addOnValueChanged([this](std::string cvarName, CVarWrapper newCvar) {
		bool animatorEnabled = newCvar.getBoolValue();
			});

	cvarManager->registerNotifier("CameraDistance", [this](std::vector<std::string> params){setCamDistance();}, "", PERMISSION_ALL);
	// !! Enable debug logging by setting DEBUG_LOG = true in logging.h !!
	//DEBUGLOG("RLAnimator debug mode enabled");

	// LOG and DEBUGLOG use fmt format strings https://fmt.dev/latest/index.html
	//DEBUGLOG("1 = {}, 2 = {}, pi = {}, false != {}", "one", 2, 3.14, true);

	/*cvarManager->registerNotifier("my_aweseome_notifier", [&](std::vector<std::string> args) {
		LOG("TEsting POOOOOOOOOOOOOOOOOOOOOOOOG");
	}, "", 0);*/

	//auto cvar2 = cvarManager->registerCvar("template_cvar2", "0", "just a example of a cvar with more settings", true, true, -10, true, 10 );

	//cvar2.addOnValueChanged(std::bind(&RLAnimator::YourPluginMethod, this, _1, _2));

	// enabled decleared in the header
	//enabled = std::make_shared<bool>(false);
	//cvarManager->registerCvar("TEMPLATE_Enabled", "0", "Enable the TEMPLATE plugin", true, true, 0, true, 1).bindTo(enabled);

	//cvarManager->registerCvar("CVAR", "DEFAULTVALUE", "DESCRIPTION", true, true, MINVAL, true, MAXVAL);//.bindTo(CVARVARIABLE);
	//gameWrapper->HookEvent("FUNCTIONNAME", std::bind(&TEMPLATE::FUNCTION, this));
	//gameWrapper->HookEventWithCallerPost<ActorWrapper>("FUNCTIONNAME", std::bind(&RLAnimator::FUNCTION, this, _1, _2, _3));
	//gameWrapper->RegisterDrawable(bind(&TEMPLATE::Render, this, std::placeholders::_1));


	//gameWrapper->HookEvent("Function TAGame.Ball_TA.Explode", [this](std::string eventName) {
	//	LOG("Your hook got called and the ball went POOF");
	//});
	// You could also use std::bind here
	//gameWrapper->HookEvent("Function TAGame.Ball_TA.Explode", std::bind(&RLAnimator::YourPluginMethod, this);
}



void RLAnimator::setCamDistance() {
	CVarWrapper animator_cam_distanceCVar = cvarManager->getCvar("animator_cam_distance");
	if (!animator_cam_distanceCVar) { return; }
	float distance = animator_cam_distanceCVar.getFloatValue();
}