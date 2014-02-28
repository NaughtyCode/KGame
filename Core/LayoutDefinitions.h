#pragma once

typedef struct VERTEX_POSITION{
	FLOAT x,y,z;
}VERTEX_POSITION;

typedef struct VERTEX_POSITIONTEX
{
	FLOAT x,y,z;
	FLOAT u,v;
}VERTEX_POSITIONTEX;

typedef enum INPUTELEMENTDESCTYPE
{
	LAYOUTTYPE_POSITION = 0,
	LAYOUTTYPE_POSITIONTEX0,
	LAYOUTTYPE_POSITIONTEX0TEX1,
	LAYOUTTYPE_POSITIONNORMAL,
	LAYOUTTYPE_POSITIONNORMALTEX0,
	LAYOUTTYPE_POSITIONNORMALTEX0TEX1,
}INPUTELEMENTDESCTYPE;

D3D11_INPUT_ELEMENT_DESC* GetInputElementDesc(INPUTELEMENTDESCTYPE type); 

UINT GetInputElementDescSize(INPUTELEMENTDESCTYPE type); 

