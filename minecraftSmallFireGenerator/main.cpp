#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
	//入力
	std::string path = "";	//what
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

//1 > main.cpp
//1 > C:\Users\石井蒼一朗\source\repos\minecraftSmallFireGenerator\minecraftSmallFireGenerator\main.cpp(1, 1) : warning C4819 : ファイルは、現在のコード ページ(932) で表示できない文字を含んでいます。データの損失を防ぐために、ファイルを Unicode 形式で保存してください。
//1 > C:\Users\石井蒼一朗\source\repos\minecraftSmallFireGenerator\minecraftSmallFireGenerator\main.cpp(14, 25) : error C2065 : 'path' : 定義されていない識別子です。
//1 > C:\Users\石井蒼一朗\source\repos\minecraftSmallFireGenerator\minecraftSmallFireGenerator\main.cpp(19, 27) : error C2065 : 'path' : 定義されていない識別子です。
//1 > C:\Users\石井蒼一朗\source\repos\minecraftSmallFireGenerator\minecraftSmallFireGenerator\main.cpp(20, 6) : error C3536 : 'befFire' : 初期化前に使用することはできません