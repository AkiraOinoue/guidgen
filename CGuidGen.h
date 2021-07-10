#pragma once
#include <rpc.h>
#pragma comment( lib, "Rpcrt4.lib" )
// GUID¶¬ƒNƒ‰ƒX
class CGuidGen
{
public:
	// V‚µ‚¢GUID•¶š—ñ‚ğ•Ô‚·
	std::string NewGuid(void);
	// ¶‚ÌGUID‚ğæ“¾
	GUID RawGuid(void);
private:
	/*
	GUID‚ğ•¶š—ñ‚É•ÏŠ·‚·‚é
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
	// ¶‚ÌGUID
	GUID m_guid;
};
