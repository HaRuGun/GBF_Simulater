#pragma once

#define SAFE_DELETE(p)			{ if(p) delete p;		p = nullptr; }
#define SAFE_DELETE_ARRAY(p)	{ if(p) delete[] p;		p = nullptr; }
#define SAFE_RELEASE(p)			{ if(p) p->Release();	p = nullptr; }

#define PI 3.1416
inline double radian(double degree)
{
	return degree * PI / 180;
}