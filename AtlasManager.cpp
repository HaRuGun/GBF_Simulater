#include "stdafx.h"
#include "AtlasManager.h"


void AtlasManager::SetAtlas(string AtlasName, string txtLocate, string pngLocate)
{
	ifstream input(txtLocate);
	if (input.fail())
	{
		// Crash:File Open Error
	}

	string data;

	string keyName;
	string keyParts;
	RECT rc;

	while (!input.eof())
	{
		getline(input, data);
		// Data Solving

		string::iterator tempIter = data.begin();
		int first, second;
		int wordCount = 0;

		for (string::iterator iter = data.begin(); iter != data.end(); ++iter)
		{
			if (*iter == '/')
			{
				first = distance(data.begin(), tempIter);
				second = distance(tempIter, iter);
				string subStr = data.substr(first, second);

				if (wordCount == 0)
				{
					keyParts = subStr;
					keyName = AtlasName + keyParts;

					wordCount = 1;
				}
				else if (wordCount == 1)
				{
					rc.left = stof(subStr);
					wordCount = 2;
				}
				else if (wordCount == 2)
				{
					rc.top = stof(subStr);
					wordCount = 3;
				}
				else if (wordCount == 3)
				{
					rc.right = stof(subStr);
					wordCount = 4;
				}
				else if (wordCount == 4)
				{
					rc.bottom = stof(subStr);
					wordCount = 0;
				}

				tempIter = iter + 1;
			}
		}

		IMAGEMANAGER->AddAtlas(keyName, rc);
	}
	IMAGEMANAGER->AddImage(AtlasName, pngLocate.c_str());

	input.close();
	return;
}

void AtlasManager::SetAtlasAnimation(string AtlasName, string AnimName, string txtLocate)
{
	ifstream input(txtLocate);
	if (input.fail())
	{
		// Crash:File Open Error
	}

	vector<animFrame> animFrame;

	// Solving
	
	
	IMAGEMANAGER->AddAtlasAnimation(AtlasName + AnimName, animFrame);
	input.close();
	return;
}

/* Data Example
Atlas
HEAD/0/0/20/20/
BODY/20/0/40/20/
...

Anim
0.1_HEAD/1/1/0/0/0/0_BODY/1/1/0/1/0/0/...
0.2_HEAD/0.9/0.9/0/0/0/0_BODY/1/1/0/1/0/0/...
...
*/