int CView::CopyCoordToClipboard()
{
	char str_Coord_x[20] = {0,};
	char str_Coord_y[20] = {0,};
	char str[20] = ",";

	itoa(Current_Coord.x, str_Coord_x, 10);	// x좌표
	itoa(Current_Coord.y, str_Coord_y, 10);	// y좌표

	strcat(str, str_Coord_y);
	strcat(str_Coord_x, str);

	const char *ap_string = str_Coord_x;

	int string_length = strlen(ap_string) + 1; // 저장할 문자열의 길이를 구한다. ('\0'까지 포함한 크기)

	// 클립보드로 문자열을 복사하기 위하여 메모리를 할당한다
	// 클립보드에는 핸들을 넣는 형식이라서 HeapAlloc 함수 사용이 불가능하다
	HANDLE h_data = ::GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE, string_length);

	char *p_data = (char *)::GlobalLock(h_data); // 할당된 메모리에 문자열을 복사하기 위해서 사용 가능한 주소를 얻는다
	if (NULL != p_data) 
	{ 
		memcpy(p_data, ap_string, string_length); // 할당된 메모리 영역에 삽입할 문자열을 복사한다
		
		::GlobalUnlock(h_data); // 문자열을 복사하기 위해서 Lock 했던 메모리를 해제한다 

		if (::OpenClipboard(m_hWnd))  //클립보드를 연다
		{ 
			::EmptyClipboard(); //클립보드에 저장된 기존 문자열을 삭제한다 
			::SetClipboardData(CF_TEXT, h_data); // 클립보드로 문자열을 복사한다.
			::CloseClipboard(); //클립보드를 닫는다
		}
	}
	return 0;
}

int CView::PasteCoordFromClipboard()
{
	unsigned int priority_list = CF_TEXT;
	char *p_string = NULL;
	
	if (::GetPriorityClipboardFormat(&priority_list, 1) == CF_TEXT) //클립보드에 저장되있는게 문자열인지 확인
	{
		if (::OpenClipboard(m_hWnd))  //클립보드에 있는 비트맵 정보를 얻기 위해서 클립보드를 연다
		{
			HANDLE h_clipboard_data = ::GetClipboardData(CF_TEXT); //클립보드에서 문자열이 저장된 메모리의 핸들 값을 얻는다
			if (h_clipboard_data != NULL) 
			{
				// 메모리 핸들 값을 이용하여 실제 사용가능한 주소를 얻는다
				char *p_clipboard_data = (char *)::GlobalLock(h_clipboard_data);
				char *str_Coord_y = NULL;
				char *str_Coord_x = strtok_s(p_clipboard_data, ",", &str_Coord_y); // 콤마를 기준으로 각 좌표값을 잘라서 넣어준다.

				long x = atoi(str_Coord_x);
				long y = atoi(str_Coord_y);

				POINT Coord;
			
				Coord.x = x;
				Coord.y = y;

				if(Coord.x != 0 && Coord.y !=0)
				{
					HafpDAL->SetCurCoord(Coord, 1);
					EraseMap();
					Invalidate(FALSE);
				}

				//// 클립보드에 저장된 문자열의 길이를 구한다. ('\0'포함 크기)
				//int string_len = strlen(p_clipboard_data) + 1;
				//// 클립보드에 저장된 문자열을 저장하기 위해 메모리를 할당한다
				//p_string = new char[string_len];
				//// 할당된 메모리에 클리보드 문자열을 복사한다
				//memcpy(p_string, p_clipboard_data, string_len);

				// 문자열을 복사하기 위해서 Lock했던 메모리를 해제한다
				::GlobalUnlock(h_clipboard_data);
			}
			::CloseClipboard( );
		}
	}
	return 0;
}
