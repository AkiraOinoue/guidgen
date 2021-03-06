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
