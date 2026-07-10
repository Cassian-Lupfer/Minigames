#include <raylib.h>
#include "ResourceManager.h"

namespace Canolu {
	Texture2D ResourceManager::loadTexture(const char* filePath) {
		for (int i = 0; i < loadedTexturePaths.size(); i++) {
			if (loadedTexturePaths[i] == filePath) {
				Texture2D texture = loadedTextures[i];
				return texture;
			}
			else {
				loadedTexturePaths.push_back(filePath);

				Texture2D texture = LoadTexture(filePath);
				loadedTextures.push_back(texture);
				return texture;
			}
		}
	}

	void ResourceManager::unloadAssets() {

	}
}
