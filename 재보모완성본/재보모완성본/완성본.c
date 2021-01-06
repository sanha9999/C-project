#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define SIZE_S 4 //기본 보드게임의 세로
#define SIZE_E 6 //기본 보드게임의 가로
int ro, b = 0, board[SIZE_S][SIZE_E], play = 0, ex = 0, aha = 0;
void roll() { //주사위 굴리기 함수
	ro = 0;

	ro = rand() % 6 + 1;
	printf("주사위를 굴린 값은 %d입니다.\n", ro);
}

void goingf() { //1번째 턴에서 판에서 주사위 값을 토대로 이동하는 변수
	if (play == 1) { //내 차례의 시작
		aha = 0; //주사위 값을 토대로 이동하는 거리를 담는 변수
		while (aha != ro)
			aha++; //거리++
		board[0][aha] = '1'; //말 배치
		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++) {
				printf("%c", board[i][j]); //판 출력
			}
			printf("\n");
		}
		printf("계속하려면 엔터를 치십시오..\n");
		getchar(b);
		system("cls");
	}
	if (play == 2) { //상대 차례의 시작
		board[0][0] = 'S'; //시작 부분을 시작이라고 표시
		aha = 0;
		while (aha != ro)
			aha++;
		if (board[0][aha] == '1') { //만약 중복이라면
			board[0][aha] = '3'; //3으로 표시
			ex = 1; //중복이라는 것을 알림
		}
		else //그렇지 않으면
			board[0][aha] = '2'; //말 배치

		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++)
				printf("%c", board[i][j]); //판 출력
			printf("\n");
		}
	}
}
void going1() { //판에서 주사위 값을 토대로 이동하는 변수 
	int ah = 0; //주사위 값을 토대로 이동하는 거리를 담는 변수
	for (int i = 0; i < SIZE_S; i++) {
		for (int j = 0; j < SIZE_E; j++) {
			if (play == 1) { //내 차례일때
				if (ex == 1) { //중복상태일 때
					if (board[i][j] == '3') { //3이라는 말이 있는곳을 찾아서
						board[i][j] = '2'; //상대 말로 바꾼 후에
						while (ah != ro) {
							ah++; //거리 증가
							j++; //가로 수 증가
							if (j > SIZE_E) { //만약 가로 수가 6을 넘어섰다면
								j = 1; //가로 수를 1로 만들고
								i++; //세로 수 증가
							}
						}
						if (board[i][j] == '2') { //만약 중복이라면
							board[i][j] = '3'; //3으로 표시
							ex = 1; //중복이라는 것을 알림
						}
						else { //그렇지 않으면
							board[i][j] = '1'; //말 배치
							ex = 0; //중복상태 없음
						}
						break;
					}
				}
				else if (board[i][j] == '1') { //중복상태가 아니라면 1이라는 말이 있는 곳을 찾아서
					board[i][j] = '0'; //0으로 표시
					while (ah != ro) {
						ah++;
						j++;
						if (j > SIZE_E) {
							j = 1;
							i++;
						}
					}
					if (board[i][j] == '2') {
						board[i][j] = '3';
						ex = 1;
					}
					else
						board[i][j] = '1';
					break;
				}
			}
			else if (play == 2) { //상대 차례라면
				if (ex == 1) {
					if (board[i][j] == '3') {
						board[i][j] = '1';
						while (ah != ro) {
							ah++;
							j++;
							if (j > SIZE_E) {
								j = 1;
								i++;
							}
						}
						if (board[i][j] == '1') {
							board[i][j] = '3';
							ex = 1;
						}
						else {
							board[i][j] = '2';
							ex = 0;
						}
						break;
					}
				}
				else if (board[i][j] == '2') { //중복상태가 아니라면 상대 말이 있는곳을 찾아서
					board[i][j] = '0';
					while (ah != ro) {
						ah++;
						j++;
						if (j > SIZE_E) {
							j = 1;
							i++;
						}
					}
					if (board[i][j] == '1') {
						board[i][j] = '3';
						ex = 1;
					}
					else
						board[i][j] = '2';
					break;
				}
			}
		}
	}
	for (int i = 0; i < SIZE_S; i++) {
		for (int j = 0; j < SIZE_E; j++) {
			printf("%c", board[i][j]); //판 출력
		}
		printf("\n");
	}
	printf("계속하려면 엔터를 치십시오..\n");
	getchar(b);
	system("cls");
}
void print() {
	printf("\n\n\n\n\n\n\n\n");
	printf("                                              <0-0>\n");
	printf("                                     |||||||||||||||||||||\n");
	printf("                                       666 |||||||||||99999\n");
	printf("                                        666|||||||||||999999\n");
	printf("                                        666||||||||||||99                                        \n");
	printf("----------------------------------------666|||||  |||||99-------------------------------------------------\n\n\n\n");//프리토의 모습
}
void print_1() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                    0||||||      <0-0>\n");
	printf("                                        |||||||||||||||||||||||||\n");
	printf("                                              ||||||||||||    |||\n");
	printf("                                              ||||||||||||    |||||0\n");
	printf("                                           ||||||||   ||||\n");
	printf("                                           |||         |||\n");
	printf("                                          ||||         |||||\n");//구애의 춤 1
}
void print_2() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                <0-0>        ||||||0\n");
	printf("                                        ||||||||||||||||||||||||\n");
	printf("                                        |||    |||||||||||\n");
	printf("                                      0||||   |||||||||||\n");
	printf("                                               ||||  |||||||\n");
	printf("                                                |||      ||||||\n");
	printf("                                             |||||          |||||\n");//구애의 춤2
}
int game(int);
int start_1(int);
int start_2(int);
int start_3(int);
void kb(int, int*, int*);//왠지 모르겠지만 함수를 이쪽에다가 바로쓰면 오류나서 정의함
void sayong();
int start(int(*)[10], int);
int cmt(int(*)[10], int);
void fire(int(*)[10], int(*)[10]);
void fire_c(int(*)[10], int(*)[10], int(*)[10]);
int main() {
	char as = 0;
	srand((unsigned int)time(NULL));//랜덤 초기화
	int a;
	int turn = 1, fturn = 0, fro = 0, sro = 0;//기본 보드게임 변수
	int pan[10][10] = { 0 };//사용자의 판
	int pan_c[10][10] = { 0 };//컴퓨터의 판
	int(*ptr)[10];//배열값을 함수에서도 바꾸어주기위한 배열 포인터
	int(*ptr2)[10];
	ptr = pan;//연결
	ptr2 = pan_c;
	int menu;
	int end = 0;
	int i = 1, i_c = 1;//함수의 길이를 조절하기 위한 변수
	printf("-----<재밌는 보드게임 모음>-----\n");//메뉴
	printf("1. 기본 보드게임\n");
	printf("2. <배틀쉽> 보드게임\n");
	printf("3. 폴로와 프리토\n");
	printf("무엇을 하고 싶으신가요? >> ");
	scanf_s("%d", &a);
	switch (a) {
	case 1://기본 보드게임
		system("cls");
		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++) {
				board[i][j] = '0'; //판 생성
			}
		}
		board[SIZE_S - 1][SIZE_E - 1] = 'F'; //도착지점 지정
		board[0][0] = '3'; //시작지점 지정
		printf("턴 수를 정하세요.");//난이도 정하기
		scanf_s("%d", &fturn);
		getchar(b);
		//rock(); //순서 정하기
		printf("보드게임\n");
		printf("당신은 1로 표시, 상대는 2로 표시됩니다.\n3으로 표시된 곳은 당신과 상대 모두 있는곳입니다. 현재는 시작지점이 3으로 표시됩니다.\n\n");
		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++) {
				printf("%c", board[i][j]); //판 출력
			}
			printf("\n");
		}
		printf("엔터를 치시면 시작합니다.\n");
		getchar(b);
		system("cls");
		while (1) { //종료조건 만족때까지 무한반복
			printf("%d번째 턴", turn);
			printf("\n당신의 차례입니다.\n");
			play = 1; //차례를 당신(1)으로 저장

			printf("주사위를 굴리겠습니다.\n");
			roll(); //주사위 굴리는 함수 호출
			fro = fro + ro; //나의 현재 주사위 값을 저장

			if (turn == 1) { //만약 첫번째 턴이면
				goingf(); //첫번째 턴 함수 호출
			}
			else //그렇지 않으면
				going1(); //그 외의 턴 함수 호출

			printf("상대 차례입니다.\n");
			play = 2; //차례를 상대(2)로 저장
			roll();
			sro = sro + ro; //상대의 현재 주사위 값을 저장
			if (turn == 1) {
				goingf();
			}
			else
				going1();

			printf("%d번째 턴이 끝났습니다.\n", turn);
			printf("엔터를 치시면 다음 턴을 시작합니다.\n");
			getchar(b);
			system("cls");
			turn++; //턴이 끝나면 턴 증가

			if (turn == fturn + 1) { //턴이 끝났다면
				if (fro > sro) { //만약 내가 상대보다 멀리 갔다면
					printf("YOU WIN"); //나의 승리로 종료
					break;
				}
				else if (fro == sro) { //만약 나와 상대가 간 값이 동일하다면
					printf("무승부"); //무승부로 종료
					break;
				}
				else if (fro < sro) { //만약 상대가 나보다 멀리 갔다면
					printf("YOU LOSE"); //상대의 승리로 종료
					break;
				}
			}

			if (fro > SIZE_S * SIZE_E) { //만약 나의 주사위 값이 도착했다면
				printf("YOU WIN"); //나의 승리로 종료
				break;
			}
			else if (sro > SIZE_S * SIZE_E) { //만약 상대의 주사위 값이 도착했다면
				printf("YOU LOSE"); //상대의 승리로 종료
				break;
			}
			else if (fro > SIZE_S * SIZE_E && sro > SIZE_S * SIZE_E) {//만약 나와 상대 둘다의 주사위 값이 도착했다면
				printf("무승부"); //무승부로 종료
				break;
			}
		}
		break;
	case 2://배틀쉽
		system("cls");
		printf("----메뉴----\n");//메뉴
		printf("1.게임 실행\n");
		printf("2.게임 설명\n");
		printf("3.종료\n");
		printf("입력>> ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
		back:
			while (i != 7) {//사용자가 함선을 배치하는 과정
				system("cls");
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						printf("%d ", pan[i][j]);
					}
					printf("\n");
				}//판 출력
				i = start(ptr, i);
			}
			system("cls");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					printf("%d ", pan[i][j]);
				}
				printf("\n");
			}//판 출력

			while (i_c != 7) {

				system("cls");

				i_c = cmt(ptr2, i_c);//컴퓨터 랜덤

			}

			fire(ptr2, pan);
			end = 1;
			break;
		case 2:
			system("cls");
			sayong();
			goto back;
		case 3:
			printf("\n\n---종료---");
			end = 1;
			break;
		default:
			printf("\n\n잘못된 입력");
			end = 1;
			break;
		}
	case 3://폴로와 프리토
		system("cls");
		print();
		printf("\n\n안녕? 나는 현상금 사냥꾼 프리토라고해.\n");
		printf("형 폴로와 함께 엄청난 명성을 떨치고있지!\n");
		printf("어때, 너도 나와 함께 하겠어? >> (Y or N)\n");
		scanf_s("%*c%c", &as);
		system("cls");
		if (as == 'Y') {
			int dan = 1;
			while (dan <= 8) {
				dan = game(dan);//++dan을 리턴 받으며 난이도가 올라감
			}
			system("cls");
			print();
			printf("\n\n이번 게임을 잘 클리어했군?\n");
			printf("자 여기 너의 몫으로 상급 사냥꾼의 주머니와 경험치를 줄게!\n ");
			printf("다음에 또 보자고!\n");//승리했을때
		}

		else {
			system("cls");
			printf("뭐야.. 너도 나를 무시하는 거야!?!");//게임을 안한다고 했을때
			exit(1);
		}
		break;
	default:
		printf("잘못된 선택....");
		break;
	}
	return 0;
}
int game(int d) {//난이도 조정
	switch (d) {
	case 1:
	case 2:
		d = start_1(d);//1~2단계
		system("cls");
		return d;
	case 3:
	case 4:
		d = start_2(d);//3~4단계
		system("cls");
		return d;
	case 5:
	case 6:
	case 7:
	case 8:
		d = start_3(d);//5~8단계
		system("cls");
		return d;
	}
}
int start_1(int d) {
	int arr[4];
	int ans[4] = { 0 };//검사하는 배열
	int z = 4;
	int i = 0;
	int key;
	for (int i = 0; i < 4; i++) {//화살표 게임 랜덤설정
		arr[i] = rand() % 4;
	}
	printf("\t\t\t구애의 춤 :  \t");
	for (int i = 0; i < 4; i++) {
		if (arr[i] == 0) {
			printf("→\t");
			ans[i] = 77;
		}
		else if (arr[i] == 1) {
			printf("←\t");
			ans[i] = 75;
		}
		else if (arr[i] == 2) {
			printf("↑\t");
			ans[i] = 72;
		}
		else if (arr[i] == 3) {
			printf("↓\t");
			ans[i] = 80;
		}
	}
	kb(z, arr, ans);
	return ++d;

}
int start_2(int d) {
	int arr[6];
	int ans[6] = { 0 };//검사하는 배열
	int z = 6;
	int i = 0;
	int key;
	for (int i = 0; i < 6; i++) {//화살표 게임 랜덤설정
		arr[i] = rand() % 4;
	}
	printf("\t\t\t구애의 춤 :  \t");
	for (int i = 0; i < 6; i++) {
		if (arr[i] == 0) {
			printf("→\t");
			ans[i] = 77;
		}
		else if (arr[i] == 1) {
			printf("←\t");
			ans[i] = 75;
		}
		else if (arr[i] == 2) {
			printf("↑\t");
			ans[i] = 72;
		}
		else if (arr[i] == 3) {
			printf("↓\t");
			ans[i] = 80;
		}
	}

	kb(z, arr, ans);
	return ++d;

}
int start_3(int d) {
	int arr[8];
	int ans[8] = { 0 };//검사하는 배열
	int z = 8;
	int i = 0;
	int key;
	for (int i = 0; i < 8; i++) {//화살표 게임 랜덤설정
		arr[i] = rand() % 4;
	}
	printf("\t\t\t구애의 춤 :  \t");
	for (int i = 0; i < 8; i++) {//랜덤하게 받은 값을 출력하고 검사하는 배열에 갑을 입력
		if (arr[i] == 0) {
			printf("→\t");
			ans[i] = 77;
		}
		else if (arr[i] == 1) {
			printf("←\t");
			ans[i] = 75;
		}
		else if (arr[i] == 2) {
			printf("↑\t");
			ans[i] = 72;
		}
		else if (arr[i] == 3) {
			printf("↓\t");
			ans[i] = 80;
		}
	}
	kb(z, arr, ans);//키보드 입력함수 호출
	return ++d;//난이도를 더하여 리턴

}
void kb(int d, int* arr, int* ans) {
	int key;
	int i = 0;
	int ch = 0;
	while (i < d) {

		if (_kbhit()) {//키 입력
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();//개행문자 없애기

				if (ans[i] == key) {
					i++;

					system("cls");
					printf("\t\t\t구애의 춤 : \t");

					for (int u = i; u <= d; u++) {//화살표 입력을 하고 맞출 때마다 맞은 것이 지워지고 출력
						if (arr[u] == 0) {
							printf("→\t");

						}
						else if (arr[u] == 1) {
							printf("←\t");

						}
						else if (arr[u] == 2) {
							printf("↑\t");

						}
						else if (arr[u] == 3) {
							printf("↓\t");

						}
					}
					if (ch == 0) {
						print_1();
						ch = 1;
					}
					else {
						print_2();
						ch = 0;
					}

					continue;

				}
				else {
					system("cls");//키를 잘못입력했을때 게임 오버
					printf("에휴...춤을 그렇게 밖에 못추니?\n");
					printf("그런 구애의 춤으로 암탉들을 속일 순 없지...\n");

					exit(1);


				}
			}
		}
	}
}
void sayong() {//게임 설명
	printf("1. 좌표를 입력하여 우리 함대를 출전시키세요!\n");
	printf("2. 이후 좌표를 입력하여 적함대를 격침시키세요!\n");
	printf("3. 격추된 함대는 1로 표시되고, 없으면 0로 표시됨\n");
	Sleep(3000);
	system("cls");
}
int start(int(*pan)[10], int i) {//게임 실행

	int x = 0, y = 0, end = 1;

	int key;//키보드 인식
	end = 1;
	char ip;//자리를 정함
	while (end != 0) {
		printf("좌표를 입력하세요!! >> ");
		scanf_s("%d, %d", &x, &y);
		x -= 1;
		y -= 1;
		for (int z = 0; z < i; z++) {
			if (y + z >= 10) {
				printf("다시 선택해 주세요\n");//넘는 선택을 하면 다시 선택
				system("cls");
				return i;
			}
			if (pan[x][y + z] != 0) {
				printf("다시 선택해 주세요\n");//겹치는 선택을 하면 다시 선택
				system("cls");
				return i;

			}
			pan[x][y + z] = i;
		}
		end = 0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d ", pan[i][j]);
			}
			printf("\n");
		}//판 출력

	}
	return ++i;
}
int cmt(int(*ptr2)[10], int i) {
	int x, y;//컴퓨터의 랜덤 좌표
	int end = 0;
	while (end != 1) {
		x = rand() % 10;
		y = rand() % 4;
		ptr2[x][y] = i;
		if (i == 1) {
			return ++i;
		}
		for (int j = 0; j <= i; j++) {
			if (ptr2[x][y + j] != 0) {
				ptr2[x][y] = 0;
				continue;//겹치면 다시 선택
			}
			else {
				for (int j = 0; j <= i; j++) {
					ptr2[x][y + j] = i;
				}
				end = 1;
			}
		}
	}


	return ++i;
}
void fire(int(*ptrc)[10], int(*pan)[10]) {
	int pan_c[10][10];//컴퓨터 공격판 초기화
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			pan_c[i][j] = 8;
		}
	}
	int c = 0;
	int arr[10][10];

	for (int i = 0; i < 10; i++) {//판출력
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 8;
		}
	}
	int cnt = 30;
	int end = 0;
	int x, y;
	for (int i = cnt - 1; i >= 0; i--) {
		printf("\n좌표를 찍으세요!! >> ");
		scanf_s("%d, %d", &x, &y);



		if (ptrc[x - 1][y - 1] != 0) {
			end++;
			if (end == 15) {
				system("cls");
				printf("사용자 승리!!");
				exit(1);
			}
			printf("격추 성공!!\n");
			arr[x - 1][y - 1] = 1;
			printf("기회 %d번 남았습니다!!\n", i);
			Sleep(3000);
			system("cls");
		}
		else {
			printf("격추 실패!!\n");
			arr[x - 1][y - 1] = 0;
			printf("기회 %d번 남았습니다!!\n", i);
			Sleep(3000);
			system("cls");

		}

		system("cls");
		printf("<유저>\n ");
		for (int i = 1; i <= 10; i++) {
			printf("\t%d", i);
		}
		printf("\n\n");
		for (int i = 0; i < 10; i++) {
			printf("%d", i + 1);
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] == 8) {
					printf("\t ");
					continue;
				}
				printf("\t%d", arr[i][j]);
			}
			printf("\n\n");
		}//판 출력

		Sleep(3000);
		fire_c(pan, arr, pan_c);

	}
	system("cls");
	printf("이런~~ 기회 안에 격추시키지 못하셨군요?\n");//패배 문구
	exit(1);

}
void fire_c(int(*pan)[10], int(*arr)[10], int(*pan_c)[10]) {//컴퓨터의 랜덤한 공격
	system("cls");
	int x, y;

	x = rand() % 9;
	y = rand() % 9;

	if (pan[x][y] != 0) {
		printf("컴퓨터는 유저 격추 성공\n");
		pan_c[x][y] = 1;

	}
	else {
		printf("컴퓨터는 유저 격추 실패...\n");
		pan_c[x][y] = 0;
	}


	printf("<컴퓨터>\n ");
	for (int i = 1; i <= 10; i++) {
		printf("\t%d", i);
	}
	printf("\n\n");
	for (int i = 0; i < 10; i++) {
		printf("%d", i + 1);
		for (int j = 0; j < 10; j++) {
			if (pan_c[i][j] == 8) {
				printf("\t ");
				continue;
			}
			printf("\t%d", pan_c[i][j]);
		}
		printf("\n\n");
	}//판 출력
	Sleep(3000);
	system("cls");
	printf("<유저>\n ");
	for (int i = 1; i <= 10; i++) {
		printf("\t%d", i);
	}
	printf("\n\n");
	for (int i = 0; i < 10; i++) {
		printf("%d", i + 1);
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 8) {
				printf("\t ");
				continue;
			}
			printf("\t%d", arr[i][j]);
		}
		printf("\n\n");
	}//판 출력
}
