#include "stdafx.h"
#include "AtlasManager.h"


void AtlasManager::SetAtlas(string atlasName, string txtLocate, string pngLocate)
{
	ifstream input(txtLocate);
	if (input.fail())
	{
		// Crash:File Open Error
	}

	string data;

	while (!input.eof())
	{
		string destName;
		RECT destRc;

		getline(input, data);

		destName = atlasName + StringToken(data, '/');
		destRc.left		= stof(StringToken(data, ','));
		destRc.top		= stof(StringToken(data, ','));
		destRc.right	= stof(StringToken(data, ','));
		destRc.bottom	= stof(StringToken(data, ','));

		IMAGEMANAGER->AddAtlas(destName, destRc);
	}

	IMAGEMANAGER->AddImage(atlasName, pngLocate.c_str());

	input.close();
	return;
}


void AtlasManager::SetAtlasAnimation(string atlasName, string key, string txtLocate)
{
	ifstream input(txtLocate);
	if (input.fail())
	{
		// Crash:File Open Error
	}

	string data;

	atlasAnimation destAnim;
	destAnim.dCurrentTime = 0;
	destAnim.frameCount = 0;

	while (!input.eof())
	{
		getline(input, data);

		animFrame destFrame;
		destFrame.fTime = stof(StringToken(data, '_'));

		while (data[0] == '@')
		{
			animKey destKey;
			destKey.sParts = StringToken(data, '/');
			destKey.mat.width = stof(StringToken(data, ','));
			destKey.mat.height = stof(StringToken(data, ','));
			destKey.mat.x = stof(StringToken(data, ','));
			destKey.mat.y = stof(StringToken(data, ','));
			destKey.mat.velocity = stof(StringToken(data, ','));
			destKey.mat.direction = stof(StringToken(data, ','));

			destFrame.vectorKey.push_back(destKey);
		}

		destAnim.vectorFrame.push_back(destFrame);
	}

	IMAGEMANAGER->AddAtlasAnimation(atlasName + key, destAnim);

	input.close();
	return;
}

/* Data Example
HEAD/0,0,20,20,
BODY/20,0,40,20,

Anim
0.1_HEAD/1,1,0,0,0,0,BODY/1,1,0,1,0,0,@
0.2_HEAD/0.9/0.9/0/0/0/0_BODY/1/1/0/1/0/0/...@
*/