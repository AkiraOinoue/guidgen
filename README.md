# CGuidGen
## GUID生成クラス</br>
クラス定義ファイルは、CGuidGen.h,CGuidGen.cpp</br>
## 開発ツール
Microsoft Visual Studio Community 2019</br>
コンパイラ：C++17</br>
動作確認OS：Windows 10</br>
## CGuidGen.h</br>
```c++
#pragma once
#include <rpc.h>
#pragma comment( lib, "Rpcrt4.lib" )
// GUID生成クラス
class CGuidGen
{
public:
	// 新しいGUID文字列を返す
	std::string NewGuid(void);
	// 生のGUIDを取得
	GUID RawGuid(void);
private:
	/*
	GUIDを文字列に変換する
	*/
	std::string GuidToString(
		GUID* pGuid
	);
	/*
	typedef struct _GUID {
		unsigned long  Data1;
		unsigned short Data2;
		unsigned short Data3;
		unsigned char  Data4[ 8 ];
	} GUID;
	*/
	// 生のGUID
	GUID m_guid;
};
```
## CGuidGen.cpp</br>
```c++
#include <string>
#include "CGuidGen.h"
/*
    GUIDを文字列に変換する
*/
std::string CGuidGen::GuidToString(
    GUID* pGuid
)
{
    std::string oGuidString;
    RPC_CSTR aString;

    // GUIDを文字列へ変換する
    if (RPC_S_OK == ::UuidToString(pGuid, &aString)) {

        // GUIDを結果にセット
        oGuidString = (CHAR*)aString;

        // GUID文字列の破棄
        ::RpcStringFree(&aString);
    }

    // GUIDを返す
    return(oGuidString);
}
// 新しいGUID文字列を返す
std::string CGuidGen::NewGuid(void)
{
    this->m_guid = GUID_NULL;
    std::string retS = "";

    // GUIDの生成
    if (S_OK == ::CoCreateGuid(&this->m_guid))
    {
        // GUIDを文字列へ変換
        retS = this->GuidToString(&this->m_guid);
    }
    return retS;
}
// 生のGUIDを取得
GUID CGuidGen::RawGuid(void)
{
    return this->m_guid;
}
```
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
