#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>
#include <raylib.h>

namespace Canolu {
	class ResourceManager {
	private:
		std::vector<const char*> loadedTexturePaths{};
		std::vector<const char*> loadedModelPaths{};
		std::vector<const char*> loadedSoundPaths{};
		std::vector<const char*> loadedMusicPaths{};
		std::vector<Texture2D> loadedTextures{};
		std::vector<Model> loadedModels{};
		std::vector<Sound> loadedSounds{};
		std::vector<Music> loadedMusics{};

		void deleteAssetFromArrays(int index, const char* assetType);
	public:
		Texture2D loadTexture(const char* filePath);
		Model loadModel(const char* filePath);
		Sound loadSound(const char* filePath);
		Music loadMusic(const char* filePath);
		void unloadAsset(const char* filePath, const char* assetType);
		void unloadAllAssets();
	};
}

#endif
