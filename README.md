<h2>よってらっしゃい、みてらっしゃい</h2>

皆さん、まいんくらふとの火のてくすちゃ、
ちーさくしてーとおもいにゃせんかねぇ

これを使えやぁ一発でぇやんす

どんくれぇの高さにするか決めりゃ
その高さにしてくれるじゃありゃーせんかぁ

オメェらのお好きなてくすちゃーで
ろーふぁいやーが作れるじゃありゃーせんかぁ

---
| Before | After |
|------|------|
| ![](before.png) | ![](after.png) |
---

# Low Fire Texture Generator

A simple tool to generate **Low Fire textures for Minecraft**.

Minecraft fire textures are animated textures where each frame is stacked vertically.
This program processes that texture and reduces the visible fire height while preserving the animation frames.

You can use **any fire texture you like** and convert it into a **Low Fire version automatically**.

---

# 日本語説明

このツールは **Minecraftの火テクスチャをLow Fire化するツール** です。

Minecraftの火テクスチャは

* 横幅 = フレームサイズ
* 縦幅 = フレームサイズ × フレーム数

という構造の **縦並びアニメーション** になっています。

このプログラムは

1. 火テクスチャを読み込む
2. 各フレームの上部分を削る
3. 下側に火を寄せる
4. 新しいLow Fireテクスチャを生成する

という処理を行います。

つまり

**好きな火テクスチャをLow Fire化できます。**

---

# English Description

This tool generates **Low Fire textures for Minecraft**.

Minecraft fire textures are **vertically stacked animation frames** where:

* The **width** represents the size of one frame
* The **height** is `frame_size × number_of_frames`

This program:

1. Loads the fire texture
2. Crops the upper part of each frame
3. Shifts the fire downward
4. Outputs a new **Low Fire texture**

As a result, you can create **Low Fire versions of any fire texture pack** automatically.

---

# Usage

```
program.exe <texture_path> <fire_height>
```

Example:

```
program.exe fire_0.png 12
```

This will generate a new texture with each fire frame reduced to the specified height.

If no arguments are provided, the program will ask for input interactively.

---

# Output

The program generates a new file with a name like:

```
out_XXXXX_originalname.png
```

---

# Notes

* The image height must be a multiple of its width (Minecraft fire animation format).
* The specified height must not exceed the original frame height.
* PNG textures are supported.
