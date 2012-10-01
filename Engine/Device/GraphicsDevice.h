/*
 * GraphicsDevice.h
 * written by konlil
 *
 */

enum GraphicsDeviceType
{
	GD_D3D9 = 1,
};

struct GraphicsDeviceParameters
{
};

class GraphicsDeviceCallbacks
{
public:
	virtual void ReleaseAssets() = 0;
	virtual void ResetAssets() = 0;
};

class GraphicsDevice
{
public:
	virtual void FreeMemory() = 0;
	virtual void Init(const GraphicsDeviceParameters& param, AppWindow &window) = 0;
	
	virtual void StartRender() = 0;
	virtual void FinishRender(AppWindow& window, GraphicsDeviceCallbacks& callbacks) = 0;
};
