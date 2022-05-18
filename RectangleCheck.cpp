bool CView::RectangleCheck(long startX, long startY, long endX, long endY)
{
	long bigX = max(startX, endX);
	long smallX = min(startX, endX);

	long bigY = max(startY, endY);
	long smallY = min(startY, endY);

	if ( ((HitCoord.x <= bigX + 30) && (HitCoord.x >= smallX - 30 )) && ((HitCoord.y <= bigY + 30 ) && (HitCoord.y >= smallY - 30 )) )	return true;
	else return false;
}
