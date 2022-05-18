BOOL CView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if(!IsLoaded) return false;	

	::EnterCriticalSection(&CSMap);

	unsigned char CurLv = DAL->GetLevel();		// 현재레벨
	unsigned char MaxLv = DAL->Max_Level;		// 최대레벨
	unsigned char MinLv = DAL->Min_Level;		// 최소레벨

	if(!LoadingCheck)
		return false;

	if(DAL->ParcelDataNULL_flag == true)
	{	// 화면에 메시지 상자 표시
		if(AfxMessageBox(_T("영역에 데이터가 없습니다. "), MB_OK) == IDOK)
		{
		}
		DAL->ParcelDataNULL_flag = false;
	}

	if(zDelta > 0)							
	{
		if(ZoomLv <= 253 && ZoomLv >= 252)
		{
			ZoomLv++;
			Disp_class = 1;
			//CurLv = 4;
			Zoom *= ZOOM_IN_RATIO;		
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;		
		}

		else if(ZoomLv <= 251 && ZoomLv >= 250)
		{
			ZoomLv++;
			Disp_class = 0;
			//CurLv = 3;
			Zoom *= ZOOM_IN_RATIO;			
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;	
		}

		else if(ZoomLv <= 249 && ZoomLv >= 248)
		{
			ZoomLv++;
			Disp_class = 0;
			//CurLv = 2;
			Zoom *= ZOOM_IN_RATIO;		
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;	
		}


		else if(ZoomLv <= 7 && ZoomLv >= 5)
		{
			ZoomLv++;
			Disp_class = 2;
			//CurLv = 7;
			Zoom *= ZOOM_IN_RATIO;	
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else if(ZoomLv == 4)
		{
			ZoomLv++;
			Disp_class = 1;
			//CurLv = 7;
			Zoom *= ZOOM_IN_RATIO;	
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else if(ZoomLv <= 3 && ZoomLv >= 1)
		{
			ZoomLv++;
			Disp_class = 1;
			//CurLv = 6;
			Zoom *= ZOOM_IN_RATIO;
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else if(ZoomLv == 0 || ZoomLv == 255 || ZoomLv == 254 )
		{
			ZoomLv++;
			Disp_class = 1;
			//CurLv = 5;
			Zoom *= ZOOM_IN_RATIO;
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else
		{
			//CurLv = MaxLv;
			return CView::OnMouseWheel(nFlags, zDelta, pt);
		}	
	}

	else
	{
		if(ZoomLv <= 255 && ZoomLv >= 254)
		{
			ZoomLv--;
			Disp_class = 1;
			//CurLv = 4;
			Zoom *= ZOOM_OUT_RATIO;	
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else if(ZoomLv <= 253 && ZoomLv >= 252)
		{
			ZoomLv--;
			Disp_class = 0;
			//CurLv = 3;
			Zoom *= ZOOM_OUT_RATIO;	
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else if(ZoomLv <= 251 && ZoomLv > 248)
		{
			ZoomLv--;
			Disp_class = 0;
			//CurLv = 2;
			Zoom *= ZOOM_OUT_RATIO;		
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;	
		}

		else if(ZoomLv <= 8 && ZoomLv >= 7)
		{
			ZoomLv--;
			Disp_class = 2;
			//CurLv = 7;
			Zoom *= ZOOM_OUT_RATIO;	
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;
		}

		else if(ZoomLv == 6)
		{
			ZoomLv--;
			Disp_class = 1;
			//CurLv = 7;
			Zoom *= ZOOM_OUT_RATIO;
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;		
		}

		else if(ZoomLv <= 5 && ZoomLv >= 3)
		{
			ZoomLv--;
			Disp_class = 1;
			//CurLv = 6;
			Zoom *= ZOOM_OUT_RATIO;	
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;	
		}

		else if(ZoomLv <= 2 && ZoomLv >= 0)
		{
			ZoomLv--;
			Disp_class = 1;
			//CurLv = 5;
			Zoom *= ZOOM_OUT_RATIO;		
			DAL->SetLevel(CurLv);
			EraseMap();
			Invalidate(FALSE);
			LoadingCheck = true;		
		}

		else
		{
			//CurLv = MinLv;
			return CView::OnMouseWheel(nFlags, zDelta, pt);
		}
	}

	::LeaveCriticalSection(&CSMap);

	return CView::OnMouseWheel(nFlags, zDelta, pt);

}
