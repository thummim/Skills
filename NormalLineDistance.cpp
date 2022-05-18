double CView::normalLineDistance(long ptX, long ptY, long x1, long y1, long x2, long y2){

	double b = -1;			// ax + by + c = 0 형식으로 나타낸 것이므로 y = ax + c 에서 변형하면 b = -1
	double c = 0.;			// y절편
    double a = 0.;			// 기울기
	double d;

	// 범위를 벗어나는 경우
	long BigX = max(x1, x2);
	long SmallX = min(x1, x2);

	long BigY = max(y1, y2);
	long SmallY = min(y1, y2);

	// calcCradient 에서 false -> x = a 거나 y = a 인 그래프 경우
	if (!calcGradient(x1, y1, x2, y2, a, b, c)){
		// x = a 그래프에서 y범위 안에 있다면 x 차이값, y범위를 벗어나는 곳에 있다면 최소점 혹은 최대점과 마우스 포인터간의 두 점사이의 거리 리턴
		if ( x1==x2 ){
			
			if (ptY > BigY)
			{
				d = sqrt(pow((double)(ptX-x1), 2)+pow((double)(ptY-BigY), 2));

				return d;
			}
			else if (ptY < SmallY)
			{
				d = sqrt(pow((double)(x1-ptX), 2)+pow((double)(SmallY-ptY), 2));

				return d;
			}
			else
			{
				d = fabs((double)(x1 - ptX));

				return d;
			}
		}
		else
		{
			if (ptX > BigX){
				d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-y1), 2));
				//printf("y=a  ptX > BigX      %f\n", d);
				return d;
			}
			else if (ptX < SmallX)
			{
				d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(y1-ptY), 2));
				return d;
			}
			else
			{
				d = fabs((double)(y1 - ptY));
				return d;
			}
		}
	}
	// 그외에 값
	else{

		// 기울기가 x축에 가깝게 완만한데 x 범위와 y범위를 벗어났다면 두점사이 거리 리턴
		if       (  (a <= 1) && (ptX > BigX) && (ptY > BigY || ptY < SmallY)  ){
			
			d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-BigY), 2));
			//printf("(a < 1) && (ptX > BigX)  %f\n", d);
			return d;
		}

		else if  (  (a >= -1) && (ptX > BigX) && (ptY > BigY || ptY < SmallY)  ){
			
			d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-SmallY), 2));
			//printf("(a > -1) && (ptX > BigX)  %f\n", d);
			return d;
		}

		else if  (  (a <= 1) && (ptX < SmallX) && (ptY > BigY || ptY < SmallY) ){
			
			d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(SmallY-ptY), 2));
			//printf("(a < 1) && (ptX < SmallX)%f\n", d);
			return d;
		}

		else if  (  (a >= -1) && (ptX < SmallX) && (ptY > BigY || ptY < SmallY)  ){
			
			d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(BigY-ptY), 2));
			//printf("(a > -1) && (ptX < SmallX)%f\n", d);
			return d;
		}

		// x와 y 범위를 전부 벗어났을 때
		else if  (  (a <= 1) && (ptY > BigY) && (ptX > BigX || ptX < SmallX)  ){
			
			d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-BigY), 2));
			//printf("(a < 1) && (ptY > BigY)  %f\n", d);
			return d;
		}

		else if  (  (a >= -1) && (ptY > BigY) && (ptX > BigX || ptX < SmallX)  ){
			
			d = sqrt(pow((double)(ptX-SmallX), 2)+pow((double)(ptY-BigY), 2));
			//printf("(a > -1) && (ptY > BigY)  %f\n", d);
			return d;
		}

		else if  (  (a <= 1) && (ptY < SmallY)&& (ptX > BigX || ptX < SmallX)  ){
			
			d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(SmallY-ptY), 2));
			//printf("(a < 1) && (ptY < SmallY)%f\n", d);
			return d;
		}

		else if  (  (a >= -1) && (ptY < SmallY)&& (ptX > BigX || ptX < SmallX) ){
			
			d = sqrt(pow((double)(BigX-ptX), 2)+pow((double)(SmallY-ptY), 2));
			//printf("(a > -1) && (ptY < SmallY)%f\n", d);
			return d;
		}


		// 기울기가 y축에 가깝게 가파르고 x값 혹은 y 값의 범위를 벗어났다면 두점사이 거리 리턴
		else if  (  (a > 1) && (ptY > BigY) && (ptX > BigX || ptX < SmallX)  ){
			
			d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-BigY), 2));
			//printf("(a > 1) && (ptY > BigY)  %f\n", d);
			return d;
		}

		else if  (  (a < -1) && (ptY > BigY) && (ptX > BigX || ptX < SmallX)     ){
			
			d = sqrt(pow((double)(ptX-SmallX), 2)+pow((double)(ptY-BigY), 2));
			//printf("(a < -1) && (ptY > BigY)  %f\n", d);
			return d;
		}

		else if  (  (a > 1) && (ptY < SmallY)&& (ptX > BigX || ptX < SmallX)    ){

			d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(SmallY-ptY), 2));
			//printf("(a > 1) && (ptY < SmallY)%f\n", d);
			return d;
		}

		else if  (  (a < -1) && (ptY < SmallY)&& (ptX > BigX || ptX < SmallX)   ){

			d = sqrt(pow((double)(BigX-ptX), 2)+pow((double)(SmallY-ptY), 2));
			//printf("(a < -1) && (ptY < SmallY)%f\n", d);
			return d;
		}

		// x, y 전부 벗어났을 때
		else if  (  (a > 1) && (ptX > BigX)  && (ptY > BigY || ptY < SmallY)  ){
			
			d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-BigY), 2));
			//printf("(a > 1) && (ptX > BigX)  %f\n", d);
			return d;
		}

		else if  (  (a < -1) && (ptX > BigX) && (ptY > BigY || ptY < SmallY)  ){
			
			d = sqrt(pow((double)(ptX-BigX), 2)+pow((double)(ptY-SmallY), 2));
			//printf("(a < -1) && (ptX > BigX)  %f\n", d);
			return d;
		}

		else if  (  (a > 1) && (ptX < SmallX)&& (ptY > BigY || ptY < SmallY) ){

			d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(SmallY-ptY), 2));
			//printf("(a > 1) && (ptX < SmallX)%f\n", d);
			return d;
		}

		else if  (  (a < -1) && (ptX < SmallX)&& (ptY > BigY || ptY < SmallY) ){

			d = sqrt(pow((double)(SmallX-ptX), 2)+pow((double)(BigY-ptY), 2));
			//printf("(a < -1) && (ptX < SmallX)%f\n", d);
			return d;
		}

		else{
		
			d = fabs(a*ptX + b*ptY + c)/ sqrt(pow(a, 2)+pow(b, 2));
			//printf("fabs                      %f\n", d);
			return d;
		}
	}
}
