#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>

namespace Canolu {
	class ResourceManager {
	private:
		std::vector<const char*> loadedTexturePaths{};
		std::vector<const char*> loadedSoundPaths{};
		std::vector<const char*> loadedMusicPaths{};
		std::vector<Texture2D> loadedTextures{};
		std::vector<Sound> loadedSounds{};
		std::vector<Music> loadedMusics{};
	public:
		Texture2D loadTexture(const char* filePath);
		Sound loadSound(const char* filePath);
		Music loadMusic(const char* filePath);
		void unloadAllAssets();
	};
}

#endif
