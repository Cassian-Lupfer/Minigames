#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>

namespace Canolu {
	class ResourceManager {
	private:
		std::vector<const char*> loadedTexturePaths{};
		std::vector<Texture2D> loadedTextures{};
	public:
		Texture2D loadTexture(const char* filePath);
		void unloadAssets();
	};
}

#endif
