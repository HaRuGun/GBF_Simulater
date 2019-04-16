#pragma once

#define SAFE_DELETE(p)			{ if(p) delete p;		p = nullptr; }
#define SAFE_DELETE_ARRAY(p)	{ if(p) delete[] p;		p = nullptr; }
#define SAFE_RELEASE(p)			{ if(p) p->Release();	p = nullptr; }

#define PI 3.1416
inline double radian(double degree)
{
	return degree * PI / 180;
}

using namespace std;
string StringToken(string& data, const char token);

template<class T>
T Lerp(T p1, T p2, float d)
{
	return p1 + (p2 - p1) * d;
}