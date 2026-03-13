#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
	//入力
	std::string path = "";
	int fireSizeH = 0;
	std::cout << "変更を加える火のテクスチャのパスを入力して下さい:";
	std::getline(std::cin, path);
	std::cout << "火単体の解像度を入力してください:";
	std::cin >> fireSizeH;
	//読み込み
	int w, h, c;
	auto befFire = stbi_load(path.c_str(), &w, &h, &c, 4);
	if (befFire == nullptr) {
		std::cout << "テクスチャを読み込めませんでした\n";
		system("pause>0");
		return -1;
	}
	stbi_image_free(befFire);
}