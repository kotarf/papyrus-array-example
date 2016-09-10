#include "ArrayExample.h"

#define DEGREES 180 / PI

namespace MyPluginNamespace {
	/* application logic */
	UInt32 someFunction(SomeData d, MoreData a) {
		return 1;
	}

	/* SKSE wrapper */
	UInt32 SKSEWrapper(StaticFunctionTag *base, VMArray<float> d, VMArray<float> a) {
		gLog.SetLogLevel(IDebugLog::kLevel_Message);

		// SomeData
		float scale;
		float scaleMe;
		float width;

		// MoreData
		float facing;
		float headingAngle;
		float ax;

		d.Get(&scale, 0);
		d.Get(&scaleMe, 1);
		d.Get(&width, 2);

		a.Get(&facing, 0);
		a.Get(&headingAngle, 1);
		a.Get(&ax, 2);

		SomeData someDataStruct(scale, scaleMe, width);
		MoreData moreDataStruct(facing, headingAngle, ax);

		return someFunction(someDataStruct, moreDataStruct);
	}

	bool RegisterFuncs(VMClassRegistry* registry) {
		registry->RegisterFunction(new NativeFunction2 <StaticFunctionTag, UInt32, VMArray<float>, VMArray<float>>("SKSEWrapper", "SKSEWrapper", MyPluginNamespace::SKSEWrapper, registry));
		return true;
	}
}
