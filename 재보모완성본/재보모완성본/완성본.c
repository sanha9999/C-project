#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define SIZE_S 4 //�⺻ ��������� ����
#define SIZE_E 6 //�⺻ ��������� ����
int ro, b = 0, board[SIZE_S][SIZE_E], play = 0, ex = 0, aha = 0;
void roll() { //�ֻ��� ������ �Լ�
	ro = 0;

	ro = rand() % 6 + 1;
	printf("�ֻ����� ���� ���� %d�Դϴ�.\n", ro);
}

void goingf() { //1��° �Ͽ��� �ǿ��� �ֻ��� ���� ���� �̵��ϴ� ����
	if (play == 1) { //�� ������ ����
		aha = 0; //�ֻ��� ���� ���� �̵��ϴ� �Ÿ��� ��� ����
		while (aha != ro)
			aha++; //�Ÿ�++
		board[0][aha] = '1'; //�� ��ġ
		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++) {
				printf("%c", board[i][j]); //�� ���
			}
			printf("\n");
		}
		printf("����Ϸ��� ���͸� ġ�ʽÿ�..\n");
		getchar(b);
		system("cls");
	}
	if (play == 2) { //��� ������ ����
		board[0][0] = 'S'; //���� �κ��� �����̶�� ǥ��
		aha = 0;
		while (aha != ro)
			aha++;
		if (board[0][aha] == '1') { //���� �ߺ��̶��
			board[0][aha] = '3'; //3���� ǥ��
			ex = 1; //�ߺ��̶�� ���� �˸�
		}
		else //�׷��� ������
			board[0][aha] = '2'; //�� ��ġ

		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++)
				printf("%c", board[i][j]); //�� ���
			printf("\n");
		}
	}
}
void going1() { //�ǿ��� �ֻ��� ���� ���� �̵��ϴ� ���� 
	int ah = 0; //�ֻ��� ���� ���� �̵��ϴ� �Ÿ��� ��� ����
	for (int i = 0; i < SIZE_S; i++) {
		for (int j = 0; j < SIZE_E; j++) {
			if (play == 1) { //�� �����϶�
				if (ex == 1) { //�ߺ������� ��
					if (board[i][j] == '3') { //3�̶�� ���� �ִ°��� ã�Ƽ�
						board[i][j] = '2'; //��� ���� �ٲ� �Ŀ�
						while (ah != ro) {
							ah++; //�Ÿ� ����
							j++; //���� �� ����
							if (j > SIZE_E) { //���� ���� ���� 6�� �Ѿ�ٸ�
								j = 1; //���� ���� 1�� �����
								i++; //���� �� ����
							}
						}
						if (board[i][j] == '2') { //���� �ߺ��̶��
							board[i][j] = '3'; //3���� ǥ��
							ex = 1; //�ߺ��̶�� ���� �˸�
						}
						else { //�׷��� ������
							board[i][j] = '1'; //�� ��ġ
							ex = 0; //�ߺ����� ����
						}
						break;
					}
				}
				else if (board[i][j] == '1') { //�ߺ����°� �ƴ϶�� 1�̶�� ���� �ִ� ���� ã�Ƽ�
					board[i][j] = '0'; //0���� ǥ��
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
			else if (play == 2) { //��� ���ʶ��
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
				else if (board[i][j] == '2') { //�ߺ����°� �ƴ϶�� ��� ���� �ִ°��� ã�Ƽ�
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
			printf("%c", board[i][j]); //�� ���
		}
		printf("\n");
	}
	printf("����Ϸ��� ���͸� ġ�ʽÿ�..\n");
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
	printf("----------------------------------------666|||||  |||||99-------------------------------------------------\n\n\n\n");//�������� ���
}
void print_1() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                    0||||||      <0-0>\n");
	printf("                                        |||||||||||||||||||||||||\n");
	printf("                                              ||||||||||||    |||\n");
	printf("                                              ||||||||||||    |||||0\n");
	printf("                                           ||||||||   ||||\n");
	printf("                                           |||         |||\n");
	printf("                                          ||||         |||||\n");//������ �� 1
}
void print_2() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                <0-0>        ||||||0\n");
	printf("                                        ||||||||||||||||||||||||\n");
	printf("                                        |||    |||||||||||\n");
	printf("                                      0||||   |||||||||||\n");
	printf("                                               ||||  |||||||\n");
	printf("                                                |||      ||||||\n");
	printf("                                             |||||          |||||\n");//������ ��2
}
int game(int);
int start_1(int);
int start_2(int);
int start_3(int);
void kb(int, int*, int*);//���� �𸣰����� �Լ��� ���ʿ��ٰ� �ٷξ��� �������� ������
void sayong();
int start(int(*)[10], int);
int cmt(int(*)[10], int);
void fire(int(*)[10], int(*)[10]);
void fire_c(int(*)[10], int(*)[10], int(*)[10]);
int main() {
	char as = 0;
	srand((unsigned int)time(NULL));//���� �ʱ�ȭ
	int a;
	int turn = 1, fturn = 0, fro = 0, sro = 0;//�⺻ ������� ����
	int pan[10][10] = { 0 };//������� ��
	int pan_c[10][10] = { 0 };//��ǻ���� ��
	int(*ptr)[10];//�迭���� �Լ������� �ٲپ��ֱ����� �迭 ������
	int(*ptr2)[10];
	ptr = pan;//����
	ptr2 = pan_c;
	int menu;
	int end = 0;
	int i = 1, i_c = 1;//�Լ��� ���̸� �����ϱ� ���� ����
	printf("-----<��մ� ������� ����>-----\n");//�޴�
	printf("1. �⺻ �������\n");
	printf("2. <��Ʋ��> �������\n");
	printf("3. ���ο� ������\n");
	printf("������ �ϰ� �����Ű���? >> ");
	scanf_s("%d", &a);
	switch (a) {
	case 1://�⺻ �������
		system("cls");
		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++) {
				board[i][j] = '0'; //�� ����
			}
		}
		board[SIZE_S - 1][SIZE_E - 1] = 'F'; //�������� ����
		board[0][0] = '3'; //�������� ����
		printf("�� ���� ���ϼ���.");//���̵� ���ϱ�
		scanf_s("%d", &fturn);
		getchar(b);
		//rock(); //���� ���ϱ�
		printf("�������\n");
		printf("����� 1�� ǥ��, ���� 2�� ǥ�õ˴ϴ�.\n3���� ǥ�õ� ���� ��Ű� ��� ��� �ִ°��Դϴ�. ����� ���������� 3���� ǥ�õ˴ϴ�.\n\n");
		for (int i = 0; i < SIZE_S; i++) {
			for (int j = 0; j < SIZE_E; j++) {
				printf("%c", board[i][j]); //�� ���
			}
			printf("\n");
		}
		printf("���͸� ġ�ø� �����մϴ�.\n");
		getchar(b);
		system("cls");
		while (1) { //�������� ���������� ���ѹݺ�
			printf("%d��° ��", turn);
			printf("\n����� �����Դϴ�.\n");
			play = 1; //���ʸ� ���(1)���� ����

			printf("�ֻ����� �����ڽ��ϴ�.\n");
			roll(); //�ֻ��� ������ �Լ� ȣ��
			fro = fro + ro; //���� ���� �ֻ��� ���� ����

			if (turn == 1) { //���� ù��° ���̸�
				goingf(); //ù��° �� �Լ� ȣ��
			}
			else //�׷��� ������
				going1(); //�� ���� �� �Լ� ȣ��

			printf("��� �����Դϴ�.\n");
			play = 2; //���ʸ� ���(2)�� ����
			roll();
			sro = sro + ro; //����� ���� �ֻ��� ���� ����
			if (turn == 1) {
				goingf();
			}
			else
				going1();

			printf("%d��° ���� �������ϴ�.\n", turn);
			printf("���͸� ġ�ø� ���� ���� �����մϴ�.\n");
			getchar(b);
			system("cls");
			turn++; //���� ������ �� ����

			if (turn == fturn + 1) { //���� �����ٸ�
				if (fro > sro) { //���� ���� ��뺸�� �ָ� ���ٸ�
					printf("YOU WIN"); //���� �¸��� ����
					break;
				}
				else if (fro == sro) { //���� ���� ��밡 �� ���� �����ϴٸ�
					printf("���º�"); //���ºη� ����
					break;
				}
				else if (fro < sro) { //���� ��밡 ������ �ָ� ���ٸ�
					printf("YOU LOSE"); //����� �¸��� ����
					break;
				}
			}

			if (fro > SIZE_S * SIZE_E) { //���� ���� �ֻ��� ���� �����ߴٸ�
				printf("YOU WIN"); //���� �¸��� ����
				break;
			}
			else if (sro > SIZE_S * SIZE_E) { //���� ����� �ֻ��� ���� �����ߴٸ�
				printf("YOU LOSE"); //����� �¸��� ����
				break;
			}
			else if (fro > SIZE_S * SIZE_E && sro > SIZE_S * SIZE_E) {//���� ���� ��� �Ѵ��� �ֻ��� ���� �����ߴٸ�
				printf("���º�"); //���ºη� ����
				break;
			}
		}
		break;
	case 2://��Ʋ��
		system("cls");
		printf("----�޴�----\n");//�޴�
		printf("1.���� ����\n");
		printf("2.���� ����\n");
		printf("3.����\n");
		printf("�Է�>> ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
		back:
			while (i != 7) {//����ڰ� �Լ��� ��ġ�ϴ� ����
				system("cls");
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						printf("%d ", pan[i][j]);
					}
					printf("\n");
				}//�� ���
				i = start(ptr, i);
			}
			system("cls");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					printf("%d ", pan[i][j]);
				}
				printf("\n");
			}//�� ���

			while (i_c != 7) {

				system("cls");

				i_c = cmt(ptr2, i_c);//��ǻ�� ����

			}

			fire(ptr2, pan);
			end = 1;
			break;
		case 2:
			system("cls");
			sayong();
			goto back;
		case 3:
			printf("\n\n---����---");
			end = 1;
			break;
		default:
			printf("\n\n�߸��� �Է�");
			end = 1;
			break;
		}
	case 3://���ο� ������
		system("cls");
		print();
		printf("\n\n�ȳ�? ���� ����� ��ɲ� ����������.\n");
		printf("�� ���ο� �Բ� ��û�� ���� ��ġ������!\n");
		printf("�, �ʵ� ���� �Բ� �ϰھ�? >> (Y or N)\n");
		scanf_s("%*c%c", &as);
		system("cls");
		if (as == 'Y') {
			int dan = 1;
			while (dan <= 8) {
				dan = game(dan);//++dan�� ���� ������ ���̵��� �ö�
			}
			system("cls");
			print();
			printf("\n\n�̹� ������ �� Ŭ�����߱�?\n");
			printf("�� ���� ���� ������ ��� ��ɲ��� �ָӴϿ� ����ġ�� �ٰ�!\n ");
			printf("������ �� ���ڰ�!\n");//�¸�������
		}

		else {
			system("cls");
			printf("����.. �ʵ� ���� �����ϴ� �ž�!?!");//������ ���Ѵٰ� ������
			exit(1);
		}
		break;
	default:
		printf("�߸��� ����....");
		break;
	}
	return 0;
}
int game(int d) {//���̵� ����
	switch (d) {
	case 1:
	case 2:
		d = start_1(d);//1~2�ܰ�
		system("cls");
		return d;
	case 3:
	case 4:
		d = start_2(d);//3~4�ܰ�
		system("cls");
		return d;
	case 5:
	case 6:
	case 7:
	case 8:
		d = start_3(d);//5~8�ܰ�
		system("cls");
		return d;
	}
}
int start_1(int d) {
	int arr[4];
	int ans[4] = { 0 };//�˻��ϴ� �迭
	int z = 4;
	int i = 0;
	int key;
	for (int i = 0; i < 4; i++) {//ȭ��ǥ ���� ��������
		arr[i] = rand() % 4;
	}
	printf("\t\t\t������ �� :  \t");
	for (int i = 0; i < 4; i++) {
		if (arr[i] == 0) {
			printf("��\t");
			ans[i] = 77;
		}
		else if (arr[i] == 1) {
			printf("��\t");
			ans[i] = 75;
		}
		else if (arr[i] == 2) {
			printf("��\t");
			ans[i] = 72;
		}
		else if (arr[i] == 3) {
			printf("��\t");
			ans[i] = 80;
		}
	}
	kb(z, arr, ans);
	return ++d;

}
int start_2(int d) {
	int arr[6];
	int ans[6] = { 0 };//�˻��ϴ� �迭
	int z = 6;
	int i = 0;
	int key;
	for (int i = 0; i < 6; i++) {//ȭ��ǥ ���� ��������
		arr[i] = rand() % 4;
	}
	printf("\t\t\t������ �� :  \t");
	for (int i = 0; i < 6; i++) {
		if (arr[i] == 0) {
			printf("��\t");
			ans[i] = 77;
		}
		else if (arr[i] == 1) {
			printf("��\t");
			ans[i] = 75;
		}
		else if (arr[i] == 2) {
			printf("��\t");
			ans[i] = 72;
		}
		else if (arr[i] == 3) {
			printf("��\t");
			ans[i] = 80;
		}
	}

	kb(z, arr, ans);
	return ++d;

}
int start_3(int d) {
	int arr[8];
	int ans[8] = { 0 };//�˻��ϴ� �迭
	int z = 8;
	int i = 0;
	int key;
	for (int i = 0; i < 8; i++) {//ȭ��ǥ ���� ��������
		arr[i] = rand() % 4;
	}
	printf("\t\t\t������ �� :  \t");
	for (int i = 0; i < 8; i++) {//�����ϰ� ���� ���� ����ϰ� �˻��ϴ� �迭�� ���� �Է�
		if (arr[i] == 0) {
			printf("��\t");
			ans[i] = 77;
		}
		else if (arr[i] == 1) {
			printf("��\t");
			ans[i] = 75;
		}
		else if (arr[i] == 2) {
			printf("��\t");
			ans[i] = 72;
		}
		else if (arr[i] == 3) {
			printf("��\t");
			ans[i] = 80;
		}
	}
	kb(z, arr, ans);//Ű���� �Է��Լ� ȣ��
	return ++d;//���̵��� ���Ͽ� ����

}
void kb(int d, int* arr, int* ans) {
	int key;
	int i = 0;
	int ch = 0;
	while (i < d) {

		if (_kbhit()) {//Ű �Է�
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();//���๮�� ���ֱ�

				if (ans[i] == key) {
					i++;

					system("cls");
					printf("\t\t\t������ �� : \t");

					for (int u = i; u <= d; u++) {//ȭ��ǥ �Է��� �ϰ� ���� ������ ���� ���� �������� ���
						if (arr[u] == 0) {
							printf("��\t");

						}
						else if (arr[u] == 1) {
							printf("��\t");

						}
						else if (arr[u] == 2) {
							printf("��\t");

						}
						else if (arr[u] == 3) {
							printf("��\t");

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
					system("cls");//Ű�� �߸��Է������� ���� ����
					printf("����...���� �׷��� �ۿ� ���ߴ�?\n");
					printf("�׷� ������ ������ ��ż���� ���� �� ����...\n");

					exit(1);


				}
			}
		}
	}
}
void sayong() {//���� ����
	printf("1. ��ǥ�� �Է��Ͽ� �츮 �Դ븦 ������Ű����!\n");
	printf("2. ���� ��ǥ�� �Է��Ͽ� ���Դ븦 ��ħ��Ű����!\n");
	printf("3. ���ߵ� �Դ�� 1�� ǥ�õǰ�, ������ 0�� ǥ�õ�\n");
	Sleep(3000);
	system("cls");
}
int start(int(*pan)[10], int i) {//���� ����

	int x = 0, y = 0, end = 1;

	int key;//Ű���� �ν�
	end = 1;
	char ip;//�ڸ��� ����
	while (end != 0) {
		printf("��ǥ�� �Է��ϼ���!! >> ");
		scanf_s("%d, %d", &x, &y);
		x -= 1;
		y -= 1;
		for (int z = 0; z < i; z++) {
			if (y + z >= 10) {
				printf("�ٽ� ������ �ּ���\n");//�Ѵ� ������ �ϸ� �ٽ� ����
				system("cls");
				return i;
			}
			if (pan[x][y + z] != 0) {
				printf("�ٽ� ������ �ּ���\n");//��ġ�� ������ �ϸ� �ٽ� ����
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
		}//�� ���

	}
	return ++i;
}
int cmt(int(*ptr2)[10], int i) {
	int x, y;//��ǻ���� ���� ��ǥ
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
				continue;//��ġ�� �ٽ� ����
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
	int pan_c[10][10];//��ǻ�� ������ �ʱ�ȭ
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			pan_c[i][j] = 8;
		}
	}
	int c = 0;
	int arr[10][10];

	for (int i = 0; i < 10; i++) {//�����
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 8;
		}
	}
	int cnt = 30;
	int end = 0;
	int x, y;
	for (int i = cnt - 1; i >= 0; i--) {
		printf("\n��ǥ�� ��������!! >> ");
		scanf_s("%d, %d", &x, &y);



		if (ptrc[x - 1][y - 1] != 0) {
			end++;
			if (end == 15) {
				system("cls");
				printf("����� �¸�!!");
				exit(1);
			}
			printf("���� ����!!\n");
			arr[x - 1][y - 1] = 1;
			printf("��ȸ %d�� ���ҽ��ϴ�!!\n", i);
			Sleep(3000);
			system("cls");
		}
		else {
			printf("���� ����!!\n");
			arr[x - 1][y - 1] = 0;
			printf("��ȸ %d�� ���ҽ��ϴ�!!\n", i);
			Sleep(3000);
			system("cls");

		}

		system("cls");
		printf("<����>\n ");
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
		}//�� ���

		Sleep(3000);
		fire_c(pan, arr, pan_c);

	}
	system("cls");
	printf("�̷�~~ ��ȸ �ȿ� ���߽�Ű�� ���ϼ̱���?\n");//�й� ����
	exit(1);

}
void fire_c(int(*pan)[10], int(*arr)[10], int(*pan_c)[10]) {//��ǻ���� ������ ����
	system("cls");
	int x, y;

	x = rand() % 9;
	y = rand() % 9;

	if (pan[x][y] != 0) {
		printf("��ǻ�ʹ� ���� ���� ����\n");
		pan_c[x][y] = 1;

	}
	else {
		printf("��ǻ�ʹ� ���� ���� ����...\n");
		pan_c[x][y] = 0;
	}


	printf("<��ǻ��>\n ");
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
	}//�� ���
	Sleep(3000);
	system("cls");
	printf("<����>\n ");
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
	}//�� ���
}
