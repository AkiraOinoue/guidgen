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