#include "skse/PapyrusNativeFunctions.h"

namespace MyPluginNamespace
{
	struct SomeData { /* ... */

		SomeData(float fScale, float fScaleMe, float fWidth)
		{
			scale = fScale;
			scaleMe = fScaleMe;
			width = fWidth;
		}

		float scale;
		float scaleMe;
		float width;
	};
	struct MoreData { /* ... */
		MoreData(float fFacing, float fHeadingAngle, float fAx)
		{
			facing = fFacing;
			headingAngle = fHeadingAngle;
			ax = fAx;
		}

		float facing;
		float headingAngle;
		float ax;
	};

	UInt32 SKSEWrapper(StaticFunctionTag *base, VMArray<float> d, VMArray<float> a);

	UInt32 someFunction(SomeData d, MoreData a);

	bool RegisterFuncs(VMClassRegistry* registry);
}
