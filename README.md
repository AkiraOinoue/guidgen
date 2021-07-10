# CGuidGen
## GUID生成クラス</br>
クラス定義ファイルは、CGuidGen.h,CGuidGen.cpp</br>
## 開発ツール
Microsoft Visual Studio Community 2019
コンパイラ：C++17
動作確認OS：Windows 10
## CGuidGen.h
## CGuidGen.cpp
## 以下は使用サンプルコードです。</br>
```c++
// guidgen.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include "CGuidGen.h"
#include "guidgen.h"
int main()
{
	CGuidGen guid;
	std::map<std::string, _T_GUID> mm;
	// GUIDをキーにMAPへ登録
	for (int ii = 0; ii < 5; ii++)
	{
		std::string guids = guid.NewGuid();
		mm[guids].idx = ii;
		mm[guids].gvar = guid.RawGuid();
	}
	// MAP内容表示
	for (const auto& var : mm)
	{
		// キーと値を表示
		std::cout << var.first << "," << var.second.idx << std::endl;
	}
	// MAPの部分削除キーをベクターに登録
	std::vector<std::string> v_erase;
	for (const auto& var : mm)
	{
		if (var.second.idx == 2 || var.second.idx == 4)
		{
			// 削除キーをプール
			v_erase.push_back(var.first);
		}
	}
	// 該当キーを削除
	for (const auto& key : v_erase)
	{
		mm.erase(key);
	}
	// MAP内容表示
	std::cout << "deleted:" << std::endl;
	for (const auto& var : mm)
	{
		// キーと値を表示
		std::cout << var.first << "," << var.second.idx << std::endl;
		// 生GUID表示
		DispRawGuid(var.second.gvar);
		std::cout << std::endl;
	}
}
// 生GUID表示
void DispRawGuid(const GUID var)
{
	char savedflg = std::cout.fill('0');
	std::cout << std::setw(8);
	std::cout << std::hex << var.Data1;
	std::cout << " ";
	std::cout << std::setw(4);
	std::cout << std::hex << var.Data2;
	std::cout << " ";
	std::cout << std::setw(4);
	std::cout << std::hex << var.Data3;;
	std::cout << " ";

	for (const auto& guidval : var.Data4)
	{
		std::cout << std::setw(2);
		std::cout << std::hex << ((BYTE)guidval & 0xFF);
		std::cout << " ";
	}
	std::cout << std::endl;
	std::cout.fill(savedflg);
}
```
