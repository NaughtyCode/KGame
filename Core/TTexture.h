#ifndef TTEXTURE_H
#define TTEXTURE_H

#if _MSC_VER > 1000
# pragma once
#endif

class TD3DDevice;

class TTexture
{
public:
    TTexture();
    virtual ~TTexture(void);
    int CreateTexture(const TCHAR* TextureFileName);
    int CreateSampler();
    void PostTexture();
    void Release();
    
private:
    ID3D11SamplerState*       Sampler;
    ID3D11ShaderResourceView* TextureView;
};

#endif
