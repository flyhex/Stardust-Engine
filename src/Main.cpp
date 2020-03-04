#include <Platform/Platform.h>

#if CURRENT_PLATFORM == PLATFORM_PSP

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspmath.h>

PSP_MODULE_INFO("Stardust", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU | THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-1024);

#endif


#include <Utilities/Timer.h>
#include <Utilities/Logger.h>
#include <Utilities/Input.h>

using namespace Stardust;

int main() {

	Platform::initPlatform();

	Utilities::g_Logger->log("Hello World!");
	Utilities::updateInputs();

	while (!Utilities::KeyPressed(PSP_CTRL_START)) {
		Utilities::updateInputs();
	}

	Platform::exitPlatform();

	return 0;
}