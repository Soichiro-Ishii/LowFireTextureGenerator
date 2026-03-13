#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// このプログラムは Minecraft の火（炎）テクスチャを読み込み、
// 各フレームの縦サイズを指定した高さに切り詰めた新しい画像を出力します。
// コマンドライン引数で入力パスと出力後の高さを与えるか、対話的に入力します。
int main(int argc, char* argv[]) {
    // 入力パラメータ
    // `path` : 読み込むテクスチャファイルへのパス
    std::string path = "";
    // `afterH` : 処理後の各フレームの高さ（ピクセル）
    size_t afterH = 0;
	if (argc < 3) {
		std::cout << "Enter the path to the fire texture you want to modify:";
		std::getline(std::cin, path);
		std::cout << "Enter the desired height of the fire after processing:";
		std::cin >> afterH;
	}
	else {	
		path = argv[1];
		std::string tmp = argv[2];
		afterH = std::stoull(tmp);
    }
    // --- 画像読み込み ---
    // stbi_load の最後の引数 4 は出力を RGBA (4 チャネル) に揃える指定です。
    int w, h, c;
    auto inFire = stbi_load(path.c_str(), &w, &h, &c, 4);

    // 各フレームは幅 w x 高さ w の正方形で縦にフレームが並んでいる前提です。
    // afterH より大きい部分（切り落とすピクセル数）を求める。
    size_t numDeleteH = w - afterH;

    // 指定後の高さが元のフレーム高さを超える場合はエラー
    if (afterH > w) {
        std::cout << "The specified height cannot be greater than the original frame height.\n";
        system("pause");
        return -1;
    }

    // 画像が読み込めたか確認
    if (inFire == nullptr) {
        std::cout << "Failed to load the texture.\n";
        system("pause");
        return -1;
    }

    // 高さ h が幅 w の整数倍であること（フレーム数が整数であること）を確認
    if (h % w != 0) {
        std::cout << "Invalid image dimensions (height must be a multiple of width).\n";
        system("pause");
        return -1;
    }
    int numFireFrames = h / w; // フレーム数

    // 出力バッファを確保（RGBA の 4 チャネル）
    std::vector<unsigned char> outFire;
    outFire.resize(w * h * 4, 0);

    // --- フレームごとの切り詰め処理 ---
    // copySizePerFire : 各フレームからコピーするバイト数 (afterH 行分)
    // deleteSizePerFire : 各フレーム先頭に挿入するオフセット（切り落とすぶんの空白）
    // sizePerFire : 元フレームのバイト数 (w*w*4)
    size_t copySizePerFire = afterH * w * 4;
    size_t deleteSizePerFire = numDeleteH * w * 4;
    size_t sizePerFire = w * w * 4;

    // 各フレームをループして、元画像の先頭から afterH 行分だけを取り出し
    // 出力バッファの対応するフレーム位置にコピーする。
    for (int i = 0; i < numFireFrames; i++) {
        size_t nowFireHead = sizePerFire * i; // 元画像内のフレーム開始位置
        memcpy(&outFire[nowFireHead + deleteSizePerFire],
            &inFire[nowFireHead],
            copySizePerFire);
    }
    std::cout << "Processing completed.\n";

    // --- 出力ファイル名の生成と書き出し ---
    // outFileName は元ファイル名の前に乱数を付けて重複を避ける簡易的な方法です。
    std::string outFileName = "out_";
    srand(time(NULL));
    outFileName += std::to_string(rand());
    outFileName += '_';
    outFileName += path;

    // stbi_write_png の第4引数はチャネル数 (c) ですが、バッファは RGBA(4) を使っているため
    // 実際のチャネル数は 4 を指定するのが安全です。最後の引数は 1 行あたりのバイト数 (stride)
    stbi_write_png(outFileName.c_str(), w, h, 4, outFire.data(), w * 4);

    // 読み込み用バッファの解放
    stbi_image_free(inFire);
}