#include <iostream>
#include <raylib.h>
#include "ResourceManager.h"

namespace Canolu {
	void ResourceManager::deleteAssetFromArrays(int index, const char* assetType) {
		if (assetType == "Texture") {
			loadedTexturePaths[index] = loadedTexturePaths.back();
			loadedTexturePaths.pop_back();
			loadedTextures[index] = loadedTextures.back();
			loadedTextures.pop_back();
		}
		if (assetType == "Model") {
			loadedModelPaths[index] = loadedModelPaths.back();
			loadedModelPaths.pop_back();
			loadedModels[index] = loadedModels.back();
			loadedModels.pop_back();
		}
		if (assetType == "Sound") {
			loadedSoundPaths[index] = loadedSoundPaths.back();
			loadedSoundPaths.pop_back();
			loadedSounds[index] = loadedSounds.back();
			loadedSounds.pop_back();
		}
		if (assetType == "Music") {
			loadedMusicPaths[index] = loadedMusicPaths.back();
			loadedMusicPaths.pop_back();
			loadedMusics[index] = loadedMusics.back();
			loadedMusics.pop_back();
		}
	}

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

	Model ResourceManager::loadModel(const char* filePath) {
		Model model{};
		for (int i = 0; i < loadedModelPaths.size(); i++) {
			if (loadedModelPaths[i] == filePath) {
				model = loadedModels[i];
				return model;
			}
		}
		loadedModelPaths.push_back(filePath);
		model = LoadModel(filePath);
		loadedModels.push_back(model);
		return model;
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

	void ResourceManager::unloadAsset(const char* filePath, const char* assetType) {
		if (assetType == "Texture") {
			int index = 0;
			for (int i = 0; i < loadedTexturePaths.size(); i++) {
				if (loadedTexturePaths[i] == filePath) {
					index = i;
					break;
				}
				else if (i == loadedTexturePaths.size() - 1) {
					std::cout << "ERROR: Texture not found for unloading\n";
					return;
				}
			}
			UnloadTexture(loadedTextures[index]);
			deleteAssetFromArrays(index, assetType);
		}
		if (assetType == "Model") {
			int index = 0;
			for (int i = 0; i < loadedModelPaths.size(); i++) {
				if (loadedModelPaths[i] == filePath) {
					index = i;
					break;
				}
				else if (i == loadedModelPaths.size() - 1) {
					std::cout << "ERROR: Model not found for unloading\n";
					return;
				}
			}
			UnloadModel(loadedModels[index]);
			deleteAssetFromArrays(index, assetType);
		}
		if (assetType == "Sound") {
			int index = 0;
			for (int i = 0; i < loadedSoundPaths.size(); i++) {
				if (loadedSoundPaths[i] == filePath) {
					index = i;
					break;
				}
				else if (i == loadedSoundPaths.size() - 1) {
					std::cout << "ERROR: Sound not found for unloading\n";
					return;
				}
			}
			UnloadSound(loadedSounds[index]);
			deleteAssetFromArrays(index, assetType);
		}
		if (assetType == "Music") {
			int index = 0;
			for (int i = 0; i < loadedMusicPaths.size(); i++) {
				if (loadedMusicPaths[i] == filePath) {
					index = i;
					break;
				}
				else if (i == loadedMusicPaths.size() - 1) {
					std::cout << "ERROR: Music not found for unloading\n";
					return;
				}
			}
			UnloadMusicStream(loadedMusics[index]);
			deleteAssetFromArrays(index, assetType);
		}
	}

	void ResourceManager::unloadAllAssets() {
		// Unload textures
		for (int i = 0; i < loadedTextures.size(); i++) {
			UnloadTexture(loadedTextures[i]);
			deleteAssetFromArrays(i, "Texture");
		}
		// Unload models
		for (int i = 0; i < loadedModels.size(); i++) {
			UnloadModel(loadedModels[i]);
			deleteAssetFromArrays(i, "Model");
		}
		// Unload sounds
		for (int i = 0; i < loadedSounds.size(); i++) {
			UnloadSound(loadedSounds[i]);
			deleteAssetFromArrays(i, "Sound");
		}
		// Unload musics
		for (int i = 0; i < loadedMusics.size(); i++) {
			UnloadMusicStream(loadedMusics[i]);
			deleteAssetFromArrays(i, "Music");
		}
	}
}
