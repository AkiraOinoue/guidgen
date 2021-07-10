#pragma once
#include <rpc.h>
#pragma comment( lib, "Rpcrt4.lib" )
// GUID�����N���X
class CGuidGen
{
public:
	// �V����GUID�������Ԃ�
	std::string NewGuid(void);
	// ����GUID���擾
	GUID RawGuid(void);
private:
	/*
	GUID�𕶎���ɕϊ�����
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
	// ����GUID
	GUID m_guid;
};
