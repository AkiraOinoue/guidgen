#pragma once
#include <rpc.h>
typedef struct
{
	GUID gvar;
	int idx;
}_T_GUID;
// ��GUID�\��
void DispRawGuid(const GUID var);