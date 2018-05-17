//a way to construct random map, however,the rooms may bump into each other and I dont't want to continue in this way because of my laziness
srand(time(0));
 	int len1 = rand()%20+25;//room1 2 len = 25-45
 	int len2 = rand()%20+25;
 	int len3 = rand()%20+25;
 	int len4 = rand()%15+20;//room4 len = 20-35
 	int wid1 = rand()%10+10;
 	int wid2 = rand()%10+10;
 	int wid3 = rand()%10+10;
 	int wid4 = rand()%10+10;//room width = 10-20
 	int Lroad1 = rand()%4+4;
 	int Lroad2 = rand()%4+4;
 	int Lroad3 = rand()%4+4;//road length = 20~100
 	int K1 = rand()%7+2;
 	int K2 = rand()%13+2;
 	int K3 = rand()%13+2;//some random position for roads
 	int K4 = rand()%(len1 + Lroad1 - len4);//a range that room 3 may move towards 4, promising that the two room would not collapse
 	for(int i = 0; i < size; i++){
 		for(int j = 0; j < size; j++){
 			if((i >= 0)&&(i <= wid1 +1)&&(j >= 0)&&(j <= len1+1)){
 				if((i == 0)||(i == wid1+1)||(j == 0)||(j == len1+1)){
 					arr[i][j] = 1;
 					if((j == len1 +1)&&(i == K1))
 						arr[i][j] = 2;
 					if((j==K3)&&(i ==wid1+1))
 						arr[i][j] = 2;
 				}
 				else
 					arr[i][j] = 2;
 			}//in room 1
 			else if((i >= 0)&&(i <= wid2 +1)&&(j >= len1+2+Lroad1)&&(j <= len1+1+Lroad1+len2)){
 				if((i == 0)||(i == wid2 + 1)||(j == len1+2+Lroad1)||(j == len1+1+Lroad1+len2)){
 					arr[i][j] = 1;
 					if((j == len1+1+Lroad1)&&(i == K1))
 						arr[i][j] = 2;
 					if((j == len1+2+Lroad1+K2)&&(i == wid2+2+Lroad2))
 						arr[i][j] = 2;
 				}
 				else
 					arr[i][j] = 2;
 			}//room 2;
 			else if((i >= wid1+2+Lroad3)&&(i <= wid1+1+Lroad3+wid4)&&(j >= 0)&&(j <= len4+1)){
 				if((i == wid1+2+Lroad3)||(i == wid1+1+Lroad3+wid4)||(j == 0)||(j == len4 +1)){
 					arr[i][j] = 1;
 					if((i == wid1+2+Lroad3)&&(j == K3))
 						arr[i][j] = 2;
 				}
 				else
 					arr[i][j] = 2;
 			}//room 4;
 			else if((i >= wid2+2+Lroad2)&&(i <= wid2+1+Lroad2+wid3)&&(j >= len1+2+Lroad1+K2-K4)&&(j <= len1+1+Lroad1+K2-K4+len3)){
 				if((i == wid2+2+Lroad2)||(i == wid2+1+Lroad2+wid3)||(j == len1+2+Lroad1+K2-K4)||(j == len1+1+Lroad1+K2-K4+len3)){
 					arr[i][j] = 1;
 					if((i == wid2+2+Lroad2)&&(j == len1+1+Lroad1))
 						arr[i][j] = 2;
 				}
 				else
 					arr[i][j] = 2;
 			}//room 3
 			else if((i == K1) &&(j >= len1+2) &&(j <= len1+1+Lroad1))
 				arr[i][j] = 3;//road1
 			else if((j == K3)&&(i >= wid1+2)&&(i <= wid1+1+Lroad3))
 				arr[i][j] = 3;//road3
 			else if((j == len1+2+Lroad1+K2)&&(i >= wid2+2)&&(i <= wid2+1+Lroad2))
 				arr[i][j] = 3;//road2
 			else
 				arr[i][j] = 0;
 			view[i][j] = 0;
 		}
 	}