#include "stdafx.h"
#include "LayoutDefinitions.h"

static D3D11_INPUT_ELEMENT_DESC PositionLayout[] = {
	{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

D3D11_INPUT_ELEMENT_DESC PositionTexLayout[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

static D3D11_INPUT_ELEMENT_DESC* LayoutArray[]={
	PositionLayout,
	PositionTexLayout,
};

static UINT LayoutArraySize[]={
	ARRAYSIZE(PositionLayout),
	ARRAYSIZE(PositionTexLayout),
};

D3D11_INPUT_ELEMENT_DESC* GetLayoutArray(INPUTELEMENTDESCTYPE type)
{
	UINT index=(UINT)type;
	assert(index<ARRAYSIZE(LayoutArray));
	return LayoutArray[index];
}

UINT GetLayoutArraySize(INPUTELEMENTDESCTYPE type)
{
	UINT index=(UINT)type;
	assert(index<ARRAYSIZE(LayoutArraySize));
	return LayoutArraySize[index];
}



