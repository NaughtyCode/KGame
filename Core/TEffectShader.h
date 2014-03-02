#pragma once
#include "IShader.h"
#include "TD3DDevice.h"

class IShader;
class TD3DDevice;

class TEffectShader:public IShader
{
public:
	TEffectShader(TD3DDevice* device);
	virtual ~TEffectShader(void);
	int CompileShaderFromFile(const TCHAR* szFileName,LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	int CreateEffectShader(const TCHAR* szFileName);
	virtual void PostEffect();
	virtual LPVOID GetShaderBufferPointer();
	virtual SIZE_T GetShaderBufferSize();
	virtual void Release();

private:
	TD3DDevice*             Device;
	ID3DX11Effect*          Effect;
	ID3DX11EffectTechnique* Technique;
	ID3DBlob*               EffectBuffer;
};

