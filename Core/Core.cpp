#include "stdafx.h"

class TD3D11Render;
class TCamera;
class TDevice;

TResource*    GResource                 = 0;
TD3D11Render* GRender                   = 0;
TCamera*      GCamera                   = 0;
TDevice*      GDevice                   = 0;
DWORD         GGPUFrameTime             = 0;
char*         ASCIIResourceDirectory    = "..\\Resource\\";
wchar_t*      WCHARResourceDirectory    = L"..\\Resource\\";

void CreateRender(HWND hWnd)
{
	int rt;
	assert(!GCamera);
	GCamera = new TCamera(hWnd);
	assert(GCamera);
	
	assert(!GDevice);
	GDevice = new TDevice(hWnd);
	assert(GDevice);
	rt=GDevice->CreateDevice();
	assert(rt);
	
	assert(!GRender);
	GRender = new TD3D11Render();
	GRender->CreateRender(hWnd);
	assert(GRender);
}

void DestroyRender()
{
	SAFE_RELEASEDELETE(GCamera);
	SAFE_RELEASEDELETE(GDevice);
	SAFE_RELEASEDELETE(GRender);
}

void GetResourceDirASCII(std::string& FileName)
{
	std::string root(ASCIIResourceDirectory);
	FileName=root+FileName;
}

void GetResourceDirWCHAR(std::wstring& FileName)
{
	std::wstring root(WCHARResourceDirectory);
	FileName=root+FileName;
}

void GDrawFrame()
{
	GStartFrame();
	if(!GResource)
	{
		GResource = new TResource();
		GResource->CreateResource();
	}
	GResource->PostResource();
	
	GEndFrame();
}

void GStartFrame()
{
	GRender->StartFrame();
}

void GEndFrame()
{
	GRender->EndFrame();
}




BOOL CheckConstantBufferSize(UINT Size)
{
	if(Size <= D3D11_REQ_CONSTANT_BUFFER_ELEMENT_COUNT && (Size % CONSTANTBUFFERMETASIZE) == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


UINT AlignToBlock(UINT Size,UINT Align)
{
	assert(Align>0);
	
	UINT NewSize;
	UINT Remain=Size%Align;
	if(Remain==0)
	{
		NewSize = Remain*Align;
	}else
	{
		NewSize = (Remain+1)*Align;
	}
	return NewSize;
}


std::string GetErrorString(HRESULT error)
{
	std::string ErrorString;
#define D3D11ERR(x) case x: ErrorString = (#x); break;
	switch (error)
	{
		D3D11ERR( S_OK )
		D3D11ERR( S_FALSE )
		D3D11ERR( E_NOTIMPL )
		D3D11ERR( E_OUTOFMEMORY )
		D3D11ERR( E_INVALIDARG )
		D3D11ERR( E_FAIL )
		D3D11ERR( D3DERR_INVALIDCALL )
		D3D11ERR( D3D11_ERROR_FILE_NOT_FOUND )
		D3D11ERR( D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS )
		D3D11ERR( D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS )
		D3D11ERR( D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD )
	}
#undef D3D11ERR
	return ErrorString;
}

void VerifyResult(HRESULT error,const char* Code,const char* Filename,UINT Line)
{
	if(FAILED(error))
	{
		std::string ErrorString = GetErrorString(error);
		std::printf("%s failed \n at %s:%u \n with error %s",Code,Filename,Line,ErrorString.c_str());
	}
}






