#include <raylib.h>
#include "ResourceManager.h"

namespace Canolu {
	Texture2D ResourceManager::loadTexture(const char* filePath) {
		Texture2D texture{};

		for (int i = 0; i < loadedTexturePaths.size(); i++) {
			if (loadedTexturePaths[i] == filePath) {
				texture = loadedTextures[i];
				return texture;
			}
		}

		loadedTexturePaths.push_back(filePath);
		texture = LoadTexture(filePath);
		loadedTextures.push_back(texture);
		return texture;
	}

	Sound ResourceManager::loadSound(const char* filePath) {
		Sound sound{};

		for (int i = 0; i < loadedSoundPaths.size(); i++) {
			if (loadedSoundPaths[i] == filePath) {
				sound = loadedSounds[i];
				return sound;
			}
		}

		loadedSoundPaths.push_back(filePath);
		sound = LoadSoundFromWave(LoadWave(filePath));
		loadedSounds.push_back(sound);
		return sound;
	}

	Music ResourceManager::loadMusic(const char* filePath) {
		Music music{};

		for (int i = 0; i < loadedMusicPaths.size(); i++) {
			if (loadedSoundPaths[i] == filePath) {
				music = loadedMusics[i];
				return music;
			}
		}

		loadedMusicPaths.push_back(filePath);
		music = LoadMusicStream(filePath);
		loadedMusics.push_back(music);
		return music;
	}

	void ResourceManager::unloadAllAssets() {
		// Unload textures
		for (int i = 0; i < loadedTextures.size(); i++) {
			Texture2D texture = loadedTextures[i];
			UnloadTexture(texture);
		}
		// Unload sounds
		for (int i = 0; i < loadedSounds.size(); i++) {
			Sound sound = loadedSounds[i];
			UnloadSound(sound);
		}
		// Unload musics
		for (int i = 0; i < loadedMusics.size(); i++) {
			Music music = loadedMusics[i];
			UnloadMusicStream(music);
		}
	}
}
