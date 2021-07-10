#include <string>
#include "CGuidGen.h"
/*
    GUID�𕶎���ɕϊ�����
*/
std::string CGuidGen::GuidToString(
    GUID* pGuid
)
{
    std::string oGuidString;
    RPC_CSTR aString;

    // GUID�𕶎���֕ϊ�����
    if (RPC_S_OK == ::UuidToString(pGuid, &aString)) {

        // GUID�����ʂɃZ�b�g
        oGuidString = (CHAR*)aString;

        // GUID������̔j��
        ::RpcStringFree(&aString);
    }

    // GUID��Ԃ�
    return(oGuidString);
}
// �V����GUID�������Ԃ�
std::string CGuidGen::NewGuid(void)
{
    this->m_guid = GUID_NULL;
    std::string retS = "";

    // GUID�̐���
    if (S_OK == ::CoCreateGuid(&this->m_guid))
    {
        // GUID�𕶎���֕ϊ�
        retS = this->GuidToString(&this->m_guid);
    }
    return retS;
}
// ����GUID���擾
GUID CGuidGen::RawGuid(void)
{
    return this->m_guid;
}