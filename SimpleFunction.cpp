#include "stdafx.h"
#include "SimpleFunction.h"


string StringToken(string& data, const char token)
{
	size_t i = 0;
	while ((data.size() != i) && (data[i++] != token));
	
	string result = data.substr(0, i - 1);
	data.erase(0, i);
	
	return result;
}
