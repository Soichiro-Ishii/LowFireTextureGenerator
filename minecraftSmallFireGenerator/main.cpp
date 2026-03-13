#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
	//入力
	std::string path = "";
	size_t afterH = 0;
	std::cout << "変更を加える火のテクスチャのパスを入力して下さい:";
	std::getline(std::cin, path);
	std::cout << "生成後の火単体の大きさを入力してください:";
	std::cin >> afterH;
	//読み込み
	int w, h, c;
	auto inFire = stbi_load(path.c_str(), &w, &h, &c, 4);
	size_t numDeleteH = w - afterH;
	if (afterH > w) {
		std::cout << "元画像の高さより高くなってどうすんねん。\n";
		system("pause");
		return -1;
	}
	if (inFire == nullptr) {
		std::cout << "テクスチャを読み込めませんでした\n";
		system("pause");
		return -1;
	}
	if (h % w != 0) {
		std::cout << "画像の高さと幅の値が不正です\n";
		system("pause");
		return -1;
	}
	int numFireFrames = h / w;

	std::vector<unsigned char> outFire;
	outFire.resize(w * h * 4, 0);
	//出力
	size_t copySizePerFire = afterH * w * 4;
	size_t deleteSizePerFire = numDeleteH * w * 4;
	size_t sizePerFire = w * w * 4;
	for (int i = 0; i < numFireFrames; i++) {
		size_t nowFireHead = sizePerFire * i;
		memcpy(&outFire[nowFireHead + deleteSizePerFire],
			&inFire[nowFireHead],
			copySizePerFire);
	}
	std::cout << "処理が終了しました。\n";
	std::string outFileName = "out ";
	srand(time(NULL));
	outFileName += std::to_string(rand());
	outFileName += ".png";
	stbi_write_png(outFileName.c_str(), w, h, c, outFire.data(), w * 4);
	stbi_image_free(inFire);
}